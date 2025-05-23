/*
 * H.26L/H.264/AVC/JVT/14496-10/... sei decoding
 * Copyright (c) 2003 Michael Niedermayer <michaelni@gmx.at>
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

/**
 * @file
 * H.264 / AVC / MPEG4 part10 sei decoding.
 * @author Michael Niedermayer <michaelni@gmx.at>
 */
#ifdef WIN32
#pragma warning(disable:4244 4018 4101 4996 4554 4090 4005 4305 4146)
#endif
#include "avcodec.h"
#include "golomb.h"
#include "h264.h"
#include "internal.h"
#include "libavutil/internal.h"
#define EINVAL 22
#define ENOMEM 12
static const uint8_t sei_num_clock_ts_table[9] = {
    1, 1, 1, 2, 2, 3, 3, 2, 3
};

void ff_h264_reset_sei(H264Context *h)
{
    h->sei_recovery_frame_cnt       = -1;
    h->sei_dpb_output_delay         =  0;
    h->sei_cpb_removal_delay        = -1;
    h->sei_buffering_period_present =  0;
    h->sei_frame_packing_present    =  0;
    h->sei_display_orientation_present = 0;
    h->sei_reguserdata_afd_present  =  0;

    h->a53_caption_size = 0;
    av_freep(&h->a53_caption);
}

static int decode_picture_timing(H264Context *h)
{
    SPS *sps = &h->sps;
    int i;

    for (i = 0; i<MAX_SPS_COUNT; i++)
        if (!sps->log2_max_frame_num && h->sps_buffers[i])
            sps = h->sps_buffers[i];

    if (sps->nal_hrd_parameters_present_flag || sps->vcl_hrd_parameters_present_flag) {
        h->sei_cpb_removal_delay = get_bits_long(&h->gb,
                                                 sps->cpb_removal_delay_length);
        h->sei_dpb_output_delay  = get_bits_long(&h->gb,
                                                 sps->dpb_output_delay_length);
    }
    if (sps->pic_struct_present_flag) {
        unsigned int i, num_clock_ts;

        h->sei_pic_struct = get_bits(&h->gb, 4);
        h->sei_ct_type    = 0;

        if (h->sei_pic_struct > SEI_PIC_STRUCT_FRAME_TRIPLING)
            return AVERROR_INVALIDDATA;

        num_clock_ts = sei_num_clock_ts_table[h->sei_pic_struct];

        for (i = 0; i < num_clock_ts; i++) {
            if (get_bits(&h->gb, 1)) {                /* clock_timestamp_flag */
                unsigned int full_timestamp_flag;

                h->sei_ct_type |= 1 << get_bits(&h->gb, 2);
                skip_bits(&h->gb, 1);                 /* nuit_field_based_flag */
                skip_bits(&h->gb, 5);                 /* counting_type */
                full_timestamp_flag = get_bits(&h->gb, 1);
                skip_bits(&h->gb, 1);                 /* discontinuity_flag */
                skip_bits(&h->gb, 1);                 /* cnt_dropped_flag */
                skip_bits(&h->gb, 8);                 /* n_frames */
                if (full_timestamp_flag) {
                    skip_bits(&h->gb, 6);             /* seconds_value 0..59 */
                    skip_bits(&h->gb, 6);             /* minutes_value 0..59 */
                    skip_bits(&h->gb, 5);             /* hours_value 0..23 */
                } else {
                    if (get_bits(&h->gb, 1)) {        /* seconds_flag */
                        skip_bits(&h->gb, 6);         /* seconds_value range 0..59 */
                        if (get_bits(&h->gb, 1)) {    /* minutes_flag */
                            skip_bits(&h->gb, 6);     /* minutes_value 0..59 */
                            if (get_bits(&h->gb, 1))  /* hours_flag */
                                skip_bits(&h->gb, 5); /* hours_value 0..23 */
                        }
                    }
                }
                if (sps->time_offset_length > 0)
                    skip_bits(&h->gb,
                              sps->time_offset_length); /* time_offset */
            }
        }

        if (h->avctx->debug & FF_DEBUG_PICT_INFO)
            av_log(h->avctx, AV_LOG_DEBUG, "ct_type:%X pic_struct:%d\n",
                   h->sei_ct_type, h->sei_pic_struct);
    }
    return 0;
}

static int decode_registered_user_data_afd(H264Context *h, int size)
{
    int flag;

    if (size-- < 1)
        return AVERROR_INVALIDDATA;
    skip_bits(&h->gb, 1);               // 0
    flag = get_bits(&h->gb, 1);         // active_format_flag
    skip_bits(&h->gb, 6);               // reserved

    if (flag) {
        if (size-- < 1)
            return AVERROR_INVALIDDATA;
        skip_bits(&h->gb, 4);           // reserved
        h->active_format_description   = get_bits(&h->gb, 4);
        h->sei_reguserdata_afd_present = 1;
#if FF_API_AFD
FF_DISABLE_DEPRECATION_WARNINGS
        h->avctx->dtg_active_format = h->active_format_description;
FF_ENABLE_DEPRECATION_WARNINGS
#endif /* FF_API_AFD */
    }

    return 0;
}

static int decode_registered_user_data_closed_caption(H264Context *h, int size)
{
    int flag;
    int user_data_type_code;
    int cc_count;

    if (size < 3)
        return AVERROR(EINVAL);

    user_data_type_code = get_bits(&h->gb, 8);
    if (user_data_type_code == 0x3) {
        skip_bits(&h->gb, 1);           // reserved

        flag = get_bits(&h->gb, 1);     // process_cc_data_flag
        if (flag) {
            skip_bits(&h->gb, 1);       // zero bit
            cc_count = get_bits(&h->gb, 5);
            skip_bits(&h->gb, 8);       // reserved
            size -= 2;

            if (cc_count && size >= cc_count * 3) {
                const uint64_t new_size = (h->a53_caption_size + cc_count
                                           * UINT64_C(3));
                int i, ret;

                if (new_size > INT_MAX)
                    return AVERROR(EINVAL);

                /* Allow merging of the cc data from two fields. */
                ret = av_reallocp(&h->a53_caption, new_size);
                if (ret < 0)
                    return ret;

                for (i = 0; i < cc_count; i++) {
                    h->a53_caption[h->a53_caption_size++] = get_bits(&h->gb, 8);
                    h->a53_caption[h->a53_caption_size++] = get_bits(&h->gb, 8);
                    h->a53_caption[h->a53_caption_size++] = get_bits(&h->gb, 8);
                }

                skip_bits(&h->gb, 8);   // marker_bits
            }
        }
    } else {
        int i;
        for (i = 0; i < size - 1; i++)
            skip_bits(&h->gb, 8);
    }

    return 0;
}

static int decode_registered_user_data(H264Context *h, int size)
{
    uint32_t country_code;
    uint32_t user_identifier;

    if (size < 7)
        return AVERROR_INVALIDDATA;
    size -= 7;

    country_code = get_bits(&h->gb, 8); // itu_t_t35_country_code
    if (country_code == 0xFF) {
        skip_bits(&h->gb, 8);           // itu_t_t35_country_code_extension_byte
        size--;
    }

    /* itu_t_t35_payload_byte follows */
    skip_bits(&h->gb, 8);              // terminal provider code
    skip_bits(&h->gb, 8);              // terminal provider oriented code
    user_identifier = get_bits_long(&h->gb, 32);

    switch (user_identifier) {
        case MKBETAG('D', 'T', 'G', '1'):       // afd_data
            return decode_registered_user_data_afd(h, size);
        case MKBETAG('G', 'A', '9', '4'):       // closed captions
            return decode_registered_user_data_closed_caption(h, size);
        default:
            skip_bits(&h->gb, size * 8);
            break;
    }

    return 0;
}

static int decode_unregistered_user_data(H264Context *h, int size)
{
    uint8_t *user_data;
    int e, build, i;

    if (size < 16 || size >= INT_MAX - 16)
        return AVERROR_INVALIDDATA;

    user_data = av_malloc(16 + size + 1);
    if (!user_data)
        return AVERROR(ENOMEM);

    for (i = 0; i < size + 16; i++)
        user_data[i] = get_bits(&h->gb, 8);

    user_data[i] = 0;
    e = sscanf(user_data + 16, "x264 - core %d", &build);
    if (e == 1 && build > 0)
        h->x264_build = build;
    if (e == 1 && build == 1 && !strncmp(user_data+16, "x264 - core 0000", 16))
        h->x264_build = 67;

    if (strlen(user_data + 16) > 0)
        av_log(h->avctx, AV_LOG_DEBUG, "user data:\"%s\"\n", user_data + 16);

    av_free(user_data);
    return 0;
}

static int decode_recovery_point(H264Context *h)
{
    h->sei_recovery_frame_cnt = get_ue_golomb_long(&h->gb);

    /* 1b exact_match_flag,
     * 1b broken_link_flag,
     * 2b changing_slice_group_idc */
    skip_bits(&h->gb, 4);

    if (h->avctx->debug & FF_DEBUG_PICT_INFO)
        av_log(h->avctx, AV_LOG_DEBUG, "sei_recovery_frame_cnt: %d\n", h->sei_recovery_frame_cnt);

    h->has_recovery_point = 1;

    return 0;
}

static int decode_buffering_period(H264Context *h)
{
    unsigned int sps_id;
    int sched_sel_idx;
    SPS *sps;

    sps_id = get_ue_golomb_31(&h->gb);
    if (sps_id > 31 || !h->sps_buffers[sps_id]) {
        av_log(h->avctx, AV_LOG_ERROR,
               "non-existing SPS %d referenced in buffering period\n", sps_id);
        return AVERROR_INVALIDDATA;
    }
    sps = h->sps_buffers[sps_id];

    // NOTE: This is really so duplicated in the standard... See H.264, D.1.1
    if (sps->nal_hrd_parameters_present_flag) {
        for (sched_sel_idx = 0; sched_sel_idx < sps->cpb_cnt; sched_sel_idx++) {
            h->initial_cpb_removal_delay[sched_sel_idx] =
                get_bits_long(&h->gb, sps->initial_cpb_removal_delay_length);
            // initial_cpb_removal_delay_offset
            skip_bits(&h->gb, sps->initial_cpb_removal_delay_length);
        }
    }
    if (sps->vcl_hrd_parameters_present_flag) {
        for (sched_sel_idx = 0; sched_sel_idx < sps->cpb_cnt; sched_sel_idx++) {
            h->initial_cpb_removal_delay[sched_sel_idx] =
                get_bits_long(&h->gb, sps->initial_cpb_removal_delay_length);
            // initial_cpb_removal_delay_offset
            skip_bits(&h->gb, sps->initial_cpb_removal_delay_length);
        }
    }

    h->sei_buffering_period_present = 1;
    return 0;
}

static int decode_frame_packing_arrangement(H264Context *h)
{
    h->sei_fpa.frame_packing_arrangement_id          = get_ue_golomb_long(&h->gb);
    h->sei_fpa.frame_packing_arrangement_cancel_flag = get_bits1(&h->gb);
    h->sei_frame_packing_present = !h->sei_fpa.frame_packing_arrangement_cancel_flag;

    if (h->sei_frame_packing_present) {
        h->sei_fpa.frame_packing_arrangement_type =
        h->frame_packing_arrangement_type = get_bits(&h->gb, 7);
        h->sei_fpa.quincunx_sampling_flag         =
        h->quincunx_subsampling           = get_bits1(&h->gb);
        h->sei_fpa.content_interpretation_type    =
        h->content_interpretation_type    = get_bits(&h->gb, 6);

        // the following skips: spatial_flipping_flag, frame0_flipped_flag,
        // field_views_flag, current_frame_is_frame0_flag,
        // frame0_self_contained_flag, frame1_self_contained_flag
        skip_bits(&h->gb, 6);

        if (!h->quincunx_subsampling && h->frame_packing_arrangement_type != 5)
            skip_bits(&h->gb, 16);      // frame[01]_grid_position_[xy]
        skip_bits(&h->gb, 8);           // frame_packing_arrangement_reserved_byte
        h->sei_fpa.frame_packing_arrangement_repetition_period = get_ue_golomb_long(&h->gb);
    }
    skip_bits1(&h->gb);                 // frame_packing_arrangement_extension_flag

    if (h->avctx->debug & FF_DEBUG_PICT_INFO)
        av_log(h->avctx, AV_LOG_DEBUG, "SEI FPA %d %d %d %d %d %d\n",
                                       h->sei_fpa.frame_packing_arrangement_id,
                                       h->sei_fpa.frame_packing_arrangement_cancel_flag,
                                       h->sei_fpa.frame_packing_arrangement_type,
                                       h->sei_fpa.quincunx_sampling_flag,
                                       h->sei_fpa.content_interpretation_type,
                                       h->sei_fpa.frame_packing_arrangement_repetition_period);

    return 0;
}

static int decode_display_orientation(H264Context *h)
{
    h->sei_display_orientation_present = !get_bits1(&h->gb);

    if (h->sei_display_orientation_present) {
        h->sei_hflip = get_bits1(&h->gb);     // hor_flip
        h->sei_vflip = get_bits1(&h->gb);     // ver_flip

        h->sei_anticlockwise_rotation = get_bits(&h->gb, 16);
        get_ue_golomb_long(&h->gb);  // display_orientation_repetition_period
        skip_bits1(&h->gb);          // display_orientation_extension_flag
    }

    return 0;
}

static int decode_GreenMetadata(H264Context *h)
{
    if (h->avctx->debug & FF_DEBUG_GREEN_MD)
        av_log(h->avctx, AV_LOG_DEBUG,          "Green Metadata Info SEI message\n");

    h->sei_green_metadata.green_metadata_type=get_bits(&h->gb, 8);

    if (h->avctx->debug & FF_DEBUG_GREEN_MD)
        av_log(h->avctx, AV_LOG_DEBUG,          "green_metadata_type                            = %d\n",
               h->sei_green_metadata.green_metadata_type);

    if (h->sei_green_metadata.green_metadata_type==0){
        h->sei_green_metadata.period_type=get_bits(&h->gb, 8);

        if (h->avctx->debug & FF_DEBUG_GREEN_MD)
            av_log(h->avctx, AV_LOG_DEBUG,      "green_metadata_period_type                     = %d\n",
                   h->sei_green_metadata.period_type);

        if (h->sei_green_metadata.green_metadata_type==2){
            h->sei_green_metadata.num_seconds = get_bits(&h->gb, 16);
            if (h->avctx->debug & FF_DEBUG_GREEN_MD)
                av_log(h->avctx, AV_LOG_DEBUG,  "green_metadata_num_seconds                     = %d\n",
                       h->sei_green_metadata.num_seconds);
        }
        else if (h->sei_green_metadata.period_type==3){
            h->sei_green_metadata.num_pictures = get_bits(&h->gb, 16);
            if (h->avctx->debug & FF_DEBUG_GREEN_MD)
                av_log(h->avctx, AV_LOG_DEBUG,  "green_metadata_num_pictures                    = %d\n",
                       h->sei_green_metadata.num_pictures);
        }

        h->sei_green_metadata.percent_non_zero_macroblocks=get_bits(&h->gb, 8);
        h->sei_green_metadata.percent_intra_coded_macroblocks=get_bits(&h->gb, 8);
        h->sei_green_metadata.percent_six_tap_filtering=get_bits(&h->gb, 8);
        h->sei_green_metadata.percent_alpha_point_deblocking_instance=get_bits(&h->gb, 8);

        if (h->avctx->debug & FF_DEBUG_GREEN_MD)
            av_log(h->avctx, AV_LOG_DEBUG,      "SEI GREEN Complexity Metrics                   = %f %f %f %f\n",
                                           (float)h->sei_green_metadata.percent_non_zero_macroblocks/255,
                                           (float)h->sei_green_metadata.percent_intra_coded_macroblocks/255,
                                           (float)h->sei_green_metadata.percent_six_tap_filtering/255,
                                           (float)h->sei_green_metadata.percent_alpha_point_deblocking_instance/255);

    }else if( h->sei_green_metadata.green_metadata_type==1){
        h->sei_green_metadata.xsd_metric_type=get_bits(&h->gb, 8);
        h->sei_green_metadata.xsd_metric_value=get_bits(&h->gb, 16);

        if (h->avctx->debug & FF_DEBUG_GREEN_MD)
            av_log(h->avctx, AV_LOG_DEBUG,      "xsd_metric_type                                = %d\n",
                   h->sei_green_metadata.xsd_metric_type);
        if ( h->sei_green_metadata.xsd_metric_type==0){
            if (h->avctx->debug & FF_DEBUG_GREEN_MD)
                av_log(h->avctx, AV_LOG_DEBUG,  "xsd_metric_value                               = %f\n",
                       (float)h->sei_green_metadata.xsd_metric_value/100);
        }
    }

    return 0;
}

int ff_h264_decode_sei(H264Context *h)
{
    while (get_bits_left(&h->gb) > 16 && show_bits(&h->gb, 16)) {
        int type = 0;
        unsigned size = 0;
        unsigned next;
        int ret  = 0;

        do {
            if (get_bits_left(&h->gb) < 8)
                return AVERROR_INVALIDDATA;
            type += show_bits(&h->gb, 8);
        } while (get_bits(&h->gb, 8) == 255);

        do {
            if (get_bits_left(&h->gb) < 8)
                return AVERROR_INVALIDDATA;
            size += show_bits(&h->gb, 8);
        } while (get_bits(&h->gb, 8) == 255);

        if (h->avctx->debug&FF_DEBUG_STARTCODE)
            av_log(h->avctx, AV_LOG_DEBUG, "SEI %d len:%d\n", type, size);

        if (size > get_bits_left(&h->gb) / 8) {
            av_log(h->avctx, AV_LOG_ERROR, "SEI type %d size %d truncated at %d\n",
                   type, 8*size, get_bits_left(&h->gb));
            return AVERROR_INVALIDDATA;
        }
        next = get_bits_count(&h->gb) + 8 * size;

        switch (type) {
        case SEI_TYPE_PIC_TIMING: // Picture timing SEI
            ret = decode_picture_timing(h);
            break;
        case SEI_TYPE_USER_DATA_REGISTERED:
            ret = decode_registered_user_data(h, size);
            break;
        case SEI_TYPE_USER_DATA_UNREGISTERED:
            ret = decode_unregistered_user_data(h, size);
            break;
        case SEI_TYPE_RECOVERY_POINT:
            ret = decode_recovery_point(h);
            break;
        case SEI_TYPE_BUFFERING_PERIOD:
            ret = decode_buffering_period(h);
            break;
        case SEI_TYPE_FRAME_PACKING:
            ret = decode_frame_packing_arrangement(h);
            break;
        case SEI_TYPE_DISPLAY_ORIENTATION:
            ret = decode_display_orientation(h);
            break;
        case SEI_TYPE_GREEN_METADATA:
            ret = decode_GreenMetadata(h);
            break;
        default:
            av_log(h->avctx, AV_LOG_DEBUG, "unknown SEI type %d\n", type);
        }
        if (ret < 0)
            return ret;

        skip_bits_long(&h->gb, next - get_bits_count(&h->gb));

        // FIXME check bits here
        align_get_bits(&h->gb);
    }

    return 0;
}

const char* ff_h264_sei_stereo_mode(H264Context *h)
{
    if (h->sei_fpa.frame_packing_arrangement_cancel_flag == 0) {
        switch (h->sei_fpa.frame_packing_arrangement_type) {
            case SEI_FPA_TYPE_CHECKERBOARD:
                if (h->sei_fpa.content_interpretation_type == 2)
                    return "checkerboard_rl";
                else
                    return "checkerboard_lr";
            case SEI_FPA_TYPE_INTERLEAVE_COLUMN:
                if (h->sei_fpa.content_interpretation_type == 2)
                    return "col_interleaved_rl";
                else
                    return "col_interleaved_lr";
            case SEI_FPA_TYPE_INTERLEAVE_ROW:
                if (h->sei_fpa.content_interpretation_type == 2)
                    return "row_interleaved_rl";
                else
                    return "row_interleaved_lr";
            case SEI_FPA_TYPE_SIDE_BY_SIDE:
                if (h->sei_fpa.content_interpretation_type == 2)
                    return "right_left";
                else
                    return "left_right";
            case SEI_FPA_TYPE_TOP_BOTTOM:
                if (h->sei_fpa.content_interpretation_type == 2)
                    return "bottom_top";
                else
                    return "top_bottom";
            case SEI_FPA_TYPE_INTERLEAVE_TEMPORAL:
                if (h->sei_fpa.content_interpretation_type == 2)
                    return "block_rl";
                else
                    return "block_lr";
            case SEI_FPA_TYPE_2D:
            default:
                return "mono";
        }
    } else if (h->sei_fpa.frame_packing_arrangement_cancel_flag == 1) {
        return "mono";
    } else {
        return NULL;
    }
}
