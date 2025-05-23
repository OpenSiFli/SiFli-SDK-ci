/**
 * @copyright (c) 2003 - 2020, Goodix Co., Ltd. All rights reserved.
 *
 * @file    gh3011_example_reg_array.c
 *
 * @brief   example code for gh3011 (condensed  hbd_ctrl lib)
 *
 */


#include "gh3011_example_common.h"


// init config
ST_HBD_INIT_CONFIG_TYPE gh30x_init_config =
{
    {
        HBD_FUNCTIONAL_STATE_ENABLE,
        HBD_FUNCTIONAL_STATE_ENABLE,
        HBD_FUNCTIONAL_STATE_ENABLE,
        HBD_FUNCTIONAL_STATE_ENABLE,
        HBD_FUNCTIONAL_STATE_ENABLE,
        HBD_FUNCTIONAL_STATE_ENABLE
    },
    {
        HBD_FUNCTIONAL_STATE_DISABLE,
        HBD_LED_LOGIC_CHANNEL_MAP_PHY012,
        HBD_LED_PD_SEL_EXTERNAL,
        HBD_LED_PD_SEL_EXTERNAL,
        0x28, 0x28, HBD_TIA_GAIN_2, HBD_TIA_GAIN_2,
        HBD_SAMPLE_TIME_128CYCLES
    }
};


// 以下配置数组与结构相关，请联系GOODIX输出对应数组

/* hb config */
const ST_REGISTER hb_adt_confirm_reg_config[] =
{
    {0x0100,  0xf530},
    {0x0102,  0x2710},
    {0x0104,  0xf530},
    {0x0106,  0x2710},
    {0x0108,  0xf530},
    {0x010a,  0x2710},
    {0x010c,  0xf148},
    {0x010e,  0x30d4},
    {0x0110,  0xf148},
    {0x0112,  0x30d4},
    {0x0114,  0xf148},
    {0x0116,  0x30d4},
    {0x011c,  0x01FF},
    {0x011e,  0x01FF},
    {0x0120,  0x01FF},
    {0x0126,  0x0202},
    {0x0128,  0x0002},
    {0x0130,  0x0246},
    {0x0132,  0x0246},
    {0x0134,  0x0346},
    {0x16,  0x51e},
    {0x80,  0x205},
    {0x82,  0x1c2},
    {0x84,  0x21},
    {0x118,  0x004C},
    {0x11a,  0x0000},
    {0x012e,  0x0000},
    {0x0136,  0x0110},
    {0x0186,  0x0001},
    {0x0180,  0x8D},
    {0x12a,  0x0606},
    {0x12c,  0x06},
    {0x10C0,  0x01},
    {0xC2,  0xFFFF},
    {0xC4,  0x123a},
    {0xC6,  0xFFFF},
    {0xC8,  0x123a},
    {0xCA,  0x00A0},
    {0xCC,  0x006E},
    {0xCE,  0x1140},
    {0xD0,  0x0},
    {0xD4,  0x1140},
    {0xD6,  0x0},
    {0xD8,  0x0505},
    {0xDA,  0x0000},
    {0xDC,  0x0101},
    {0xDE,  0x0000},
    {0x2A16, 0x0000},
};
const uint8_t hb_adt_confirm_reg_config_len = sizeof(hb_adt_confirm_reg_config) / sizeof(hb_adt_confirm_reg_config[0]);

const ST_REGISTER hb_reg_config_array[] =
{
    {0x0100,  0xf530},
    {0x0102,  0x2710},
    {0x0104,  0xf530},
    {0x0106,  0x2710},
    {0x0108,  0xf530},
    {0x010a,  0x2710},
    {0x010c,  0xf148},
    {0x010e,  0x30d4},
    {0x0110,  0xf148},
    {0x0112,  0x30d4},
    {0x0114,  0xf148},
    {0x0116,  0x30d4},
    {0x011c,  0x01FF},
    {0x011e,  0x01FF},
    {0x0120,  0x01FF},
    {0x0126,  0x0202},
    {0x0128,  0x0002},
    {0x0130,  0x0246},
    {0x0132,  0x0246},
    {0x0134,  0x0346},
    {0x16,  0x51e},
    {0x80,  0x605},
    {0x82,  0x1c6},
    {0x84,  0x24},
    {0x118,  0x0000},
    {0x11a,  0x004C},
    {0x012e,  0x0004},
    {0x0136,  0x0404},
    {0x0186,  0x0406},
    {0x0180,  0x8D},
    {0x12a,  0x0606},
    {0x12c,  0x06},
    {0x10C0,  0x01},
    {0xC2,  0xFFFF},
    {0xC4,  0x123a},
    {0xC6,  0xFFFF},
    {0xC8,  0x123a},
    {0xCA,  0x00A0},
    {0xCC,  0x006E},
    {0xCE,  0x1140},
    {0xD0,  0x0},
    {0xD4,  0x1140},
    {0xD6,  0x0},
    {0xD8,  0x0505},
    {0xDA,  0x0000},
    {0xDC,  0x0101},
    {0xDE,  0x0000},
    {0x2A00, 0x00FF},
    {0x2A02, 0},
    {0X2A03, 60000},
    {0x2A04, 0},
    {0x2A05, 20000},
    {0x2A06, 0},
    {0x2A07, 58000},
    {0x2A08, 0},
    {0x2A09, 25000},
    {0x2A0A, 0},
    {0x2A0B, 1000},
    {0x2A0C, 0},
    {0x2A0D, 60000},
    {0x2A0E, 0},
    {0x2A0F, 20000},
    {0x2A10, 0},
    {0x2A11, 58000},
    {0x2A12, 0},
    {0x2A13, 25000},
    {0x2A14, 0},
    {0x2A15, 1000},
    {0x2A16, 0x0000},
    {0x2A17, 0x0602},
};
const uint8_t hb_reg_config_array_len = sizeof(hb_reg_config_array) / sizeof(hb_reg_config_array[0]);

const ST_REGISTER hb_wear_confirm_reg_config_array[] =
{
    {0x0016, 0x051E},
    {0x0080, 0x0405},
    {0x0082, 0x01C4},
    {0x0084, 0x0021},
    {0x0118, 0x0028},
    {0x012E, 0x0000},
    {0x0136, 0x0020},
    {0x0186, 0x0007},
    {0x0180, 0x002D},
    {0x00C2, 0xFFFF},
    {0x00C4, 0x0A28},
    {0x00C6, 0xFFFF},
    {0x00C8, 0x0A28},
    {0x00CE, 0x0708},
    {0x00D0, 0x0000},
    {0x00D4, 0x0708},
    {0x00D6, 0x0000},
    {0x2A00, 0x00FF},
    {0x2A16, 0x0000},
};
const uint8_t hb_wear_confirm_reg_config_array_len = sizeof(hb_wear_confirm_reg_config_array) / sizeof(hb_wear_confirm_reg_config_array[0]);



/* spo2 config */
const ST_REGISTER spo2_reg_config_array[] =
{
    {0x0100, 0xf530},
    {0x0102, 0x4e20},
    {0x0104, 0xf530},
    {0x0106, 0x4e20},
    {0x0108, 0xf530},
    {0x010a, 0x2710},
    {0x010c, 0xf148},
    {0x010e, 0x57e4},
    {0x0110, 0xf148},
    {0x0112, 0x57e4},
    {0x0114, 0xf148},
    {0x0116, 0x30d4},
    {0x011c, 0x01FF},
    {0x011e, 0x01FF},
    {0x0120, 0x01FF},
    {0x0126, 0x0202},
    {0x0128, 0x0002},
    {0x0130, 0x1546},
    {0x0132, 0x1746},
    {0x0134, 0x0546},
    {0x0016, 0x0147},
    {0x0080, 0x0605},
    {0x0082, 0x01C6},
    {0x0084, 0x0023},
    {0x0118, 0x6666},
    {0x011a, 0x0000},
    {0x012E, 0x0000},
    {0x0136, 0x0110},
    {0x0186, 0x0406},
    {0x0180, 0x008D},
    {0x012a, 0x0303},
    {0x012c, 0x0003},
    {0x00C2, 0xFFFF},
    {0x00C4, 0x0528},
    {0x00C6, 0xFFFF},
    {0x00C8, 0x0528},
    {0x00CA, 0x00A0},
    {0x00CC, 0x006E},
    {0x00CE, 0x042e},
    {0x00D0, 0x0000},
    {0x00D4, 0x042e},
    {0x00D6, 0x0000},
    {0x00D8, 0x0303},
    {0x00DA, 0x0101},
    {0x00DC, 0x0101},
    {0x00DE, 0x0000},
    {0x2000, 0xFFFD},
    {0x2001, 0x846C},
    {0x2002, 0x0000},
    {0x2003, 0x781D},
    {0x2004, 0x000F},
    {0x2005, 0xCC34},
    {0x2300, 0x0001},
    {0x2301, 0x0001},
    {0x2A00, 0x00FF},
    {0x2A02, 0},
    {0X2A03, 60000},
    {0x2A04, 0},
    {0x2A05, 20000},
    {0x2A06, 0},
    {0x2A07, 58000},
    {0x2A08, 0},
    {0x2A09, 25000},
    {0x2A0A, 0},
    {0x2A0B, 1000},
    {0x2A0C, 0},
    {0x2A0D, 60000},
    {0x2A0E, 0},
    {0x2A0F, 20000},
    {0x2A10, 0},
    {0x2A11, 58000},
    {0x2A12, 0},
    {0x2A13, 25000},
    {0x2A14, 0},
    {0x2A15, 1000},
    {0x2A16, 0x0101},
    {0x2A17, 0x0602},
};
const uint8_t spo2_reg_config_array_len = sizeof(spo2_reg_config_array) / sizeof(spo2_reg_config_array[0]);



/* hrv config */
const ST_REGISTER hrv_reg_config_array[] =
{
    {0x0100,  0xf530},
    {0x0102,  0x2710},
    {0x0104,  0xf530},
    {0x0106,  0x2710},
    {0x0108,  0xf530},
    {0x010a,  0x2710},
    {0x010c,  0xf148},
    {0x010e,  0x30d4},
    {0x0110,  0xf148},
    {0x0112,  0x30d4},
    {0x0114,  0xf148},
    {0x0116,  0x30d4},
    {0x011c,  0x01FF},
    {0x011e,  0x01FF},
    {0x0120,  0x01FF},
    {0x0126,  0x0202},
    {0x0128,  0x0002},
    {0x0130,  0x0246},
    {0x0132,  0x0246},
    {0x0134,  0x0346},
    {0x16,  0x51e},
    {0x80,  0x605},
    {0x82,  0x1c6},
    {0x84,  0x24},
    {0x118,  0x0000},
    {0x11a,  0x004C},
    {0x012e,  0x0004},
    {0x0136,  0x0404},
    {0x0186,  0x0406},
    {0x0180,  0x8D},
    {0x12a,  0x0606},
    {0x12c,  0x06},
    {0x10C0,  0x01},
    {0xC2,  0xFFFF},
    {0xC4,  0x123a},
    {0xC6,  0xFFFF},
    {0xC8,  0x123a},
    {0xCA,  0x00A0},
    {0xCC,  0x006E},
    {0xCE,  0x1140},
    {0xD0,  0x0},
    {0xD4,  0x1140},
    {0xD6,  0x0},
    {0xD8,  0x0505},
    {0xDA,  0x0000},
    {0xDC,  0x0101},
    {0xDE,  0x0000},
    {0x2A16, 0x0000},
};
const uint8_t hrv_reg_config_array_len = sizeof(hrv_reg_config_array) / sizeof(hrv_reg_config_array[0]);



/* hsm config */
const ST_REGISTER hsm_reg_config_array[] =
{
    {0x0100,  0xf530},
    {0x0102,  0x2710},
    {0x0104,  0xf530},
    {0x0106,  0x2710},
    {0x0108,  0xf530},
    {0x010a,  0x2710},
    {0x010c,  0xf148},
    {0x010e,  0x30d4},
    {0x0110,  0xf148},
    {0x0112,  0x30d4},
    {0x0114,  0xf148},
    {0x0116,  0x30d4},
    {0x011c,  0x01FF},
    {0x011e,  0x01FF},
    {0x0120,  0x01FF},
    {0x0126,  0x0202},
    {0x0128,  0x0002},
    {0x0130,  0x0246},
    {0x0132,  0x0246},
    {0x0134,  0x0346},
    {0x16,  0x51e},
    {0x80,  0x605},
    {0x82,  0x1c6},
    {0x84,  0x24},
    {0x118,  0x0000},
    {0x11a,  0x004C},
    {0x012e,  0x0004},
    {0x0136,  0x0404},
    {0x0186,  0x0406},
    {0x0180,  0x8D},
    {0x12a,  0x0606},
    {0x12c,  0x06},
    {0x10C0,  0x01},
    {0xC2,  0xFFFF},
    {0xC4,  0x123a},
    {0xC6,  0xFFFF},
    {0xC8,  0x123a},
    {0xCA,  0x00A0},
    {0xCC,  0x006E},
    {0xCE,  0x1140},
    {0xD0,  0x0},
    {0xD4,  0x1140},
    {0xD6,  0x0},
    {0xD8,  0x0505},
    {0xDA,  0x0000},
    {0xDC,  0x0101},
    {0xDE,  0x0000},
    {0x2A16, 0x0000},
};
const uint8_t hsm_reg_config_array_len = sizeof(hsm_reg_config_array) / sizeof(hsm_reg_config_array[0]);



/* bpd config */
const ST_REGISTER bpd_reg_config_array[] =
{
    {0x0100,  0xf530},
    {0x0102,  0x2710},
    {0x0104,  0xf530},
    {0x0106,  0x2710},
    {0x0108,  0xf530},
    {0x010a,  0x2710},
    {0x010c,  0xf148},
    {0x010e,  0x30d4},
    {0x0110,  0xf148},
    {0x0112,  0x30d4},
    {0x0114,  0xf148},
    {0x0116,  0x30d4},
    {0x011c,  0x01FF},
    {0x011e,  0x01FF},
    {0x0120,  0x01FF},
    {0x0126,  0x0202},
    {0x0128,  0x0002},
    {0x0130,  0x0246},
    {0x0132,  0x0246},
    {0x0134,  0x0346},
    {0x16,  0x51e},
    {0x80,  0x605},
    {0x82,  0x1c6},
    {0x84,  0x24},
    {0x118,  0x0000},
    {0x11a,  0x004C},
    {0x012e,  0x0004},
    {0x0136,  0x0404},
    {0x0186,  0x0406},
    {0x0180,  0x8D},
    {0x12a,  0x0606},
    {0x12c,  0x06},
    {0x10C0,  0x01},
    {0xC2,  0xFFFF},
    {0xC4,  0x123a},
    {0xC6,  0xFFFF},
    {0xC8,  0x123a},
    {0xCA,  0x00A0},
    {0xCC,  0x006E},
    {0xCE,  0x1140},
    {0xD0,  0x0},
    {0xD4,  0x1140},
    {0xD6,  0x0},
    {0xD8,  0x0505},
    {0xDA,  0x0000},
    {0xDC,  0x0101},
    {0xDE,  0x0000},
    {0x2A16, 0x0000},
};
const uint8_t bpd_reg_config_array_len = sizeof(bpd_reg_config_array) / sizeof(bpd_reg_config_array[0]);


/* pfa config */
const ST_REGISTER pfa_reg_config_array[] =
{
    {0x0100,  0xf530},
    {0x0102,  0x2710},
    {0x0104,  0xf530},
    {0x0106,  0x2710},
    {0x0108,  0xf530},
    {0x010a,  0x2710},
    {0x010c,  0xf148},
    {0x010e,  0x30d4},
    {0x0110,  0xf148},
    {0x0112,  0x30d4},
    {0x0114,  0xf148},
    {0x0116,  0x30d4},
    {0x011c,  0x01FF},
    {0x011e,  0x01FF},
    {0x0120,  0x01FF},
    {0x0126,  0x0202},
    {0x0128,  0x0002},
    {0x0130,  0x0246},
    {0x0132,  0x0246},
    {0x0134,  0x0346},
    {0x16,  0x51e},
    {0x80,  0x605},
    {0x82,  0x1c6},
    {0x84,  0x24},
    {0x118,  0x0000},
    {0x11a,  0x004C},
    {0x012e,  0x0004},
    {0x0136,  0x0404},
    {0x0186,  0x0406},
    {0x0180,  0x8D},
    {0x12a,  0x0606},
    {0x12c,  0x06},
    {0x10C0,  0x01},
    {0xC2,  0xFFFF},
    {0xC4,  0x123a},
    {0xC6,  0xFFFF},
    {0xC8,  0x123a},
    {0xCA,  0x00A0},
    {0xCC,  0x006E},
    {0xCE,  0x1140},
    {0xD0,  0x0},
    {0xD4,  0x1140},
    {0xD6,  0x0},
    {0xD8,  0x0505},
    {0xDA,  0x0000},
    {0xDC,  0x0101},
    {0xDE,  0x0000},
    {0x2A16, 0x0000},
};
const uint8_t pfa_reg_config_array_len = sizeof(pfa_reg_config_array) / sizeof(pfa_reg_config_array[0]);


/* system test config */
const ST_REGISTER systemtest_led0_reg_config_array[] =
{
    {0x0012, 0x0d02},
    {0x000c, 0x09f0},
    {0x0080, 0x0405},
    {0x0082, 0x01C4},
    {0x0118, 0x0000},
    {0x011a, 0x0000},
    {0x012e, 0x0000},
    {0x0136, 0x0DB0},
    {0x0186, 0x0007},
    {0x0180, 0x008d},
    {0x0048, 0x0001},
    {0x0002, 0x1321},
    {0x0044, 0x0064},
    {0x0016, 0x051e},
    {0x012e, 0x0000},
    {0x0016, 0x051e},
    {0x0084, 0x0021},
    {0x0136, 0x0490},
    {0x0186, 0x0007},
    {0x0118, 0x6464},
    {0x011a, 0x0064},
    {0x0082, 0x01c4},
    {0x0002, 0xFF21},
    {0x0044, 0x0001},
    {0x0048, 0x0001},
};
const uint8_t systemtest_led0_reg_config_array_len = sizeof(systemtest_led0_reg_config_array) / sizeof(systemtest_led0_reg_config_array[0]);
#if (__SYSTEM_TEST_SUPPORT__)
ROMAHBData systemtest_led0_os_result =
{
    34, 99999, 37, 0,
};
#endif

const ST_REGISTER systemtest_led1_reg_config_array[] =
{
    {0x0012, 0x0d02},
    {0x000c, 0x09f0},
    {0x0080, 0x0405},
    {0x0082, 0x01C4},
    {0x0118, 0x0000},
    {0x011a, 0x0000},
    {0x012e, 0x0000},
    {0x0136, 0x0DB0},
    {0x0186, 0x0007},
    {0x0180, 0x008d},
    {0x0048, 0x0001},
    {0x0002, 0x1321},
    {0x0044, 0x0064},
    {0x0016, 0x051e},
    {0x012e, 0x0000},
    {0x0016, 0x051e},
    {0x0084, 0x0022},
    {0x0136, 0x0490},
    {0x0186, 0x0007},
    {0x0118, 0x6464},
    {0x011a, 0x0064},
    {0x0082, 0x01c4},
    {0x0002, 0xFF21},
    {0x0044, 0x0001},
    {0x0048, 0x0001},
};
const uint8_t systemtest_led1_reg_config_array_len = sizeof(systemtest_led1_reg_config_array) / sizeof(systemtest_led1_reg_config_array[0]);
#if (__SYSTEM_TEST_SUPPORT__)
ROMAHBData systemtest_led1_os_result =
{
    34, 99999, 37, 0,
};
#endif

const ST_REGISTER systemtest_led2_reg_config_array[] =
{
    {0x0012, 0x0d02},
    {0x000c, 0x09f0},
    {0x0080, 0x0405},
    {0x0082, 0x01C4},
    {0x0118, 0x0000},
    {0x011a, 0x0000},
    {0x012e, 0x0000},
    {0x0136, 0x0DB0},
    {0x0186, 0x0007},
    {0x0180, 0x008d},
    {0x0048, 0x0001},
    {0x0002, 0x1321},
    {0x0044, 0x0064},
    {0x0016, 0x051e},
    {0x012e, 0x0000},
    {0x0016, 0x051e},
    {0x0084, 0x0024},
    {0x0136, 0x0490},
    {0x0186, 0x0007},
    {0x0118, 0x6464},
    {0x011a, 0x0064},
    {0x0082, 0x01c4},
    {0x0002, 0xFF21},
    {0x0044, 0x0001},
    {0x0048, 0x0001},
};
const uint8_t systemtest_led2_reg_config_array_len = sizeof(systemtest_led2_reg_config_array) / sizeof(systemtest_led2_reg_config_array[0]);
#if (__SYSTEM_TEST_SUPPORT__)
ROMAHBData systemtest_led2_os_result =
{
    34, 99999, 37, 0,
};
#endif

/********END OF FILE********* Copyright (c) 2003 - 2020, Goodix Co., Ltd. ********/
