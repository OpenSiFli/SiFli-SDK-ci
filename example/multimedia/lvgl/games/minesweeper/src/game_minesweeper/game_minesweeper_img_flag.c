#ifdef __has_include
    #if __has_include("lvgl.h")
        #ifndef LV_LVGL_H_INCLUDE_SIMPLE
            #define LV_LVGL_H_INCLUDE_SIMPLE
        #endif
    #endif
#endif

#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
    #include "lvgl.h"
#else
    #include "lvgl/lvgl.h"
#endif


#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMG_GAME_MINESWEEPER_IMG_FLAG
#define LV_ATTRIBUTE_IMG_GAME_MINESWEEPER_IMG_FLAG
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_GAME_MINESWEEPER_IMG_FLAG uint8_t game_minesweeper_img_flag_map[] = {
#if LV_COLOR_DEPTH == 1 || LV_COLOR_DEPTH == 8
  /*Pixel format: Red: 3 bit, Green: 3 bit, Blue: 2 bit*/
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdb, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xb7, 0x92, 
  0xff, 0xff, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdf, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0x6e, 0x92, 
  0xff, 0xff, 0xdb, 0xdb, 0xdb, 0xdb, 0xdf, 0xf2, 0xe5, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0x92, 0x92, 
  0xff, 0xff, 0xdb, 0xdb, 0xdf, 0xd7, 0xed, 0xe0, 0xe0, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0x92, 0x92, 
  0xff, 0xff, 0xdb, 0xdb, 0xe9, 0xe0, 0xe0, 0xe0, 0xe4, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0x92, 0x92, 
  0xff, 0xff, 0xdb, 0xdb, 0xe5, 0xe0, 0xe0, 0xe0, 0xe4, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0x92, 0x92, 
  0xff, 0xff, 0xdb, 0xdb, 0xdf, 0xd6, 0xe9, 0xe0, 0xe0, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0x92, 0x92, 
  0xff, 0xff, 0xdb, 0xdb, 0xdb, 0xdf, 0xdf, 0xad, 0x40, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0x92, 0x92, 
  0xff, 0xff, 0xdb, 0xdb, 0xff, 0xff, 0xff, 0x96, 0x00, 0xdb, 0xff, 0xff, 0xdb, 0xdb, 0x92, 0x92, 
  0xff, 0xff, 0xdb, 0xdb, 0xb7, 0xb7, 0xdb, 0x6e, 0x00, 0xb6, 0xb7, 0xb7, 0xdb, 0xdb, 0x92, 0x92, 
  0xff, 0xff, 0xff, 0xb6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb6, 0xff, 0x92, 0x92, 
  0xff, 0xff, 0xff, 0xb7, 0x25, 0x25, 0x25, 0x25, 0x25, 0x25, 0x25, 0x25, 0xb7, 0xff, 0x92, 0x92, 
  0xff, 0xff, 0xdb, 0xdb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdb, 0xdb, 0x92, 0x92, 
  0xff, 0xb7, 0x6e, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 
  0xdb, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x6e, 
#endif
#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP == 0
  /*Pixel format: Red: 5 bit, Green: 6 bit, Blue: 5 bit*/
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x18, 0xc6, 
  0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xdf, 0xff, 0xdf, 0xff, 0xdf, 0xff, 0xdf, 0xff, 0xdf, 0xff, 0xdf, 0xff, 0xdf, 0xff, 0xdf, 0xff, 0xdf, 0xff, 0xdf, 0xff, 0xbf, 0xff, 0x96, 0xb5, 0xf0, 0x83, 
  0xff, 0xff, 0xdf, 0xff, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x38, 0xc6, 0x9a, 0xbe, 0x7a, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x38, 0xc6, 0x18, 0xc6, 0x6e, 0x73, 0x8e, 0x73, 
  0xff, 0xff, 0xdf, 0xff, 0x18, 0xc6, 0xf8, 0xc5, 0xf8, 0xc5, 0x79, 0xbe, 0x5d, 0xb7, 0xae, 0xdb, 0x45, 0xf1, 0xd7, 0xc5, 0x39, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x39, 0xce, 0x10, 0x84, 0xf0, 0x83, 
  0xff, 0xff, 0xdf, 0xff, 0x18, 0xc6, 0x39, 0xc6, 0xdb, 0xbe, 0x96, 0xcd, 0xeb, 0xe2, 0x00, 0xf8, 0x00, 0xf8, 0xd7, 0xc5, 0x59, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x39, 0xce, 0x10, 0x84, 0xef, 0x7b, 
  0xff, 0xff, 0xdf, 0xff, 0x59, 0xc6, 0x18, 0xc6, 0x49, 0xea, 0x41, 0xf8, 0x00, 0xf8, 0x00, 0xf8, 0xa3, 0xf8, 0xd7, 0xc5, 0x59, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x39, 0xce, 0x10, 0x84, 0xef, 0x7b, 
  0xff, 0xff, 0xdf, 0xff, 0x59, 0xc6, 0x18, 0xc6, 0x66, 0xf1, 0x00, 0xf8, 0x00, 0xf8, 0x00, 0xf8, 0xa3, 0xf8, 0xd7, 0xc5, 0x59, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x39, 0xce, 0x10, 0x84, 0xef, 0x7b, 
  0xff, 0xff, 0xdf, 0xff, 0xf8, 0xc5, 0x79, 0xbe, 0x9a, 0xbe, 0xd3, 0xd4, 0xa7, 0xe9, 0x00, 0xf8, 0x82, 0xf8, 0xd7, 0xc5, 0x59, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x39, 0xce, 0x10, 0x84, 0xef, 0x7b, 
  0xff, 0xff, 0xdf, 0xff, 0x18, 0xc6, 0xf8, 0xc5, 0x39, 0xc6, 0xba, 0xbe, 0x5d, 0xcf, 0xab, 0xa2, 0x00, 0x50, 0xd7, 0xc5, 0x59, 0xce, 0x18, 0xc6, 0x18, 0xc6, 0x39, 0xce, 0x10, 0x84, 0xef, 0x7b, 
  0xff, 0xff, 0xdf, 0xff, 0x18, 0xc6, 0x18, 0xc6, 0x9a, 0xd6, 0x9a, 0xd6, 0x9e, 0xf7, 0xb2, 0x74, 0x00, 0x00, 0x59, 0xce, 0xdb, 0xde, 0x9a, 0xd6, 0x39, 0xce, 0x38, 0xc6, 0x10, 0x84, 0xef, 0x7b, 
  0xff, 0xff, 0xdf, 0xff, 0x38, 0xc6, 0xd7, 0xbd, 0x34, 0xa5, 0x34, 0xa5, 0xd7, 0xbd, 0x4d, 0x6b, 0x00, 0x00, 0xf4, 0xa4, 0x55, 0xad, 0x34, 0xa5, 0xf8, 0xc5, 0x59, 0xce, 0x10, 0x84, 0xef, 0x7b, 
  0xff, 0xff, 0xdf, 0xff, 0xbb, 0xde, 0xd3, 0x9c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf3, 0x9c, 0xdb, 0xde, 0x10, 0x84, 0xef, 0x7b, 
  0xff, 0xff, 0xdf, 0xff, 0xba, 0xd6, 0x34, 0xa5, 0x25, 0x29, 0x25, 0x29, 0x25, 0x29, 0x45, 0x29, 0x45, 0x29, 0x45, 0x29, 0x25, 0x29, 0x25, 0x29, 0x55, 0xad, 0xbb, 0xde, 0x10, 0x84, 0xef, 0x7b, 
  0xff, 0xff, 0xff, 0xff, 0x18, 0xc6, 0x39, 0xce, 0x9a, 0xd6, 0x9a, 0xd6, 0x9a, 0xd6, 0x9a, 0xd6, 0x9a, 0xd6, 0x9a, 0xd6, 0x9a, 0xd6, 0x9a, 0xd6, 0x59, 0xce, 0x59, 0xce, 0x10, 0x84, 0xf0, 0x83, 
  0x9e, 0xf7, 0x96, 0xb5, 0x6e, 0x73, 0x10, 0x84, 0x10, 0x84, 0x10, 0x84, 0x10, 0x84, 0x10, 0x84, 0x10, 0x84, 0x10, 0x84, 0x10, 0x84, 0x10, 0x84, 0x10, 0x84, 0x10, 0x84, 0x10, 0x84, 0x10, 0x84, 
  0x18, 0xc6, 0xf0, 0x83, 0x8e, 0x73, 0xf0, 0x83, 0xef, 0x7b, 0xef, 0x7b, 0xef, 0x7b, 0xef, 0x7b, 0xef, 0x7b, 0xef, 0x7b, 0xef, 0x7b, 0xef, 0x7b, 0xef, 0x7b, 0xf0, 0x83, 0x10, 0x84, 0x0c, 0x63, 
#endif
#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP != 0
  /*Pixel format: Red: 5 bit, Green: 6 bit, Blue: 5 bit BUT the 2 bytes are swapped*/
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc6, 0x18, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xdf, 0xff, 0xdf, 0xff, 0xdf, 0xff, 0xdf, 0xff, 0xdf, 0xff, 0xdf, 0xff, 0xdf, 0xff, 0xdf, 0xff, 0xdf, 0xff, 0xdf, 0xff, 0xbf, 0xb5, 0x96, 0x83, 0xf0, 
  0xff, 0xff, 0xff, 0xdf, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x38, 0xbe, 0x9a, 0xc6, 0x7a, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x38, 0xc6, 0x18, 0x73, 0x6e, 0x73, 0x8e, 
  0xff, 0xff, 0xff, 0xdf, 0xc6, 0x18, 0xc5, 0xf8, 0xc5, 0xf8, 0xbe, 0x79, 0xb7, 0x5d, 0xdb, 0xae, 0xf1, 0x45, 0xc5, 0xd7, 0xc6, 0x39, 0xc6, 0x18, 0xc6, 0x18, 0xce, 0x39, 0x84, 0x10, 0x83, 0xf0, 
  0xff, 0xff, 0xff, 0xdf, 0xc6, 0x18, 0xc6, 0x39, 0xbe, 0xdb, 0xcd, 0x96, 0xe2, 0xeb, 0xf8, 0x00, 0xf8, 0x00, 0xc5, 0xd7, 0xc6, 0x59, 0xc6, 0x18, 0xc6, 0x18, 0xce, 0x39, 0x84, 0x10, 0x7b, 0xef, 
  0xff, 0xff, 0xff, 0xdf, 0xc6, 0x59, 0xc6, 0x18, 0xea, 0x49, 0xf8, 0x41, 0xf8, 0x00, 0xf8, 0x00, 0xf8, 0xa3, 0xc5, 0xd7, 0xc6, 0x59, 0xc6, 0x18, 0xc6, 0x18, 0xce, 0x39, 0x84, 0x10, 0x7b, 0xef, 
  0xff, 0xff, 0xff, 0xdf, 0xc6, 0x59, 0xc6, 0x18, 0xf1, 0x66, 0xf8, 0x00, 0xf8, 0x00, 0xf8, 0x00, 0xf8, 0xa3, 0xc5, 0xd7, 0xc6, 0x59, 0xc6, 0x18, 0xc6, 0x18, 0xce, 0x39, 0x84, 0x10, 0x7b, 0xef, 
  0xff, 0xff, 0xff, 0xdf, 0xc5, 0xf8, 0xbe, 0x79, 0xbe, 0x9a, 0xd4, 0xd3, 0xe9, 0xa7, 0xf8, 0x00, 0xf8, 0x82, 0xc5, 0xd7, 0xc6, 0x59, 0xc6, 0x18, 0xc6, 0x18, 0xce, 0x39, 0x84, 0x10, 0x7b, 0xef, 
  0xff, 0xff, 0xff, 0xdf, 0xc6, 0x18, 0xc5, 0xf8, 0xc6, 0x39, 0xbe, 0xba, 0xcf, 0x5d, 0xa2, 0xab, 0x50, 0x00, 0xc5, 0xd7, 0xce, 0x59, 0xc6, 0x18, 0xc6, 0x18, 0xce, 0x39, 0x84, 0x10, 0x7b, 0xef, 
  0xff, 0xff, 0xff, 0xdf, 0xc6, 0x18, 0xc6, 0x18, 0xd6, 0x9a, 0xd6, 0x9a, 0xf7, 0x9e, 0x74, 0xb2, 0x00, 0x00, 0xce, 0x59, 0xde, 0xdb, 0xd6, 0x9a, 0xce, 0x39, 0xc6, 0x38, 0x84, 0x10, 0x7b, 0xef, 
  0xff, 0xff, 0xff, 0xdf, 0xc6, 0x38, 0xbd, 0xd7, 0xa5, 0x34, 0xa5, 0x34, 0xbd, 0xd7, 0x6b, 0x4d, 0x00, 0x00, 0xa4, 0xf4, 0xad, 0x55, 0xa5, 0x34, 0xc5, 0xf8, 0xce, 0x59, 0x84, 0x10, 0x7b, 0xef, 
  0xff, 0xff, 0xff, 0xdf, 0xde, 0xbb, 0x9c, 0xd3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9c, 0xf3, 0xde, 0xdb, 0x84, 0x10, 0x7b, 0xef, 
  0xff, 0xff, 0xff, 0xdf, 0xd6, 0xba, 0xa5, 0x34, 0x29, 0x25, 0x29, 0x25, 0x29, 0x25, 0x29, 0x45, 0x29, 0x45, 0x29, 0x45, 0x29, 0x25, 0x29, 0x25, 0xad, 0x55, 0xde, 0xbb, 0x84, 0x10, 0x7b, 0xef, 
  0xff, 0xff, 0xff, 0xff, 0xc6, 0x18, 0xce, 0x39, 0xd6, 0x9a, 0xd6, 0x9a, 0xd6, 0x9a, 0xd6, 0x9a, 0xd6, 0x9a, 0xd6, 0x9a, 0xd6, 0x9a, 0xd6, 0x9a, 0xce, 0x59, 0xce, 0x59, 0x84, 0x10, 0x83, 0xf0, 
  0xf7, 0x9e, 0xb5, 0x96, 0x73, 0x6e, 0x84, 0x10, 0x84, 0x10, 0x84, 0x10, 0x84, 0x10, 0x84, 0x10, 0x84, 0x10, 0x84, 0x10, 0x84, 0x10, 0x84, 0x10, 0x84, 0x10, 0x84, 0x10, 0x84, 0x10, 0x84, 0x10, 
  0xc6, 0x18, 0x83, 0xf0, 0x73, 0x8e, 0x83, 0xf0, 0x7b, 0xef, 0x7b, 0xef, 0x7b, 0xef, 0x7b, 0xef, 0x7b, 0xef, 0x7b, 0xef, 0x7b, 0xef, 0x7b, 0xef, 0x7b, 0xef, 0x83, 0xf0, 0x84, 0x10, 0x63, 0x0c, 
#endif
#if LV_COLOR_DEPTH == 32
  /*Pixel format: Fix 0xFF: 8 bit, Red: 8 bit, Green: 8 bit, Blue: 8 bit*/
  0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xfb, 0xfb, 0xfb, 0xff, 0xc1, 0xc1, 0xc1, 0xff, 
  0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xf7, 0xf7, 0xf7, 0xff, 0xf7, 0xf7, 0xf7, 0xff, 0xf7, 0xf7, 0xf7, 0xff, 0xf7, 0xf7, 0xf7, 0xff, 0xf7, 0xf7, 0xf7, 0xff, 0xf8, 0xf8, 0xf7, 0xff, 0xf8, 0xf8, 0xf7, 0xff, 0xf7, 0xf7, 0xf7, 0xff, 0xf7, 0xf7, 0xf7, 0xff, 0xf7, 0xf7, 0xf7, 0xff, 0xf8, 0xf8, 0xf8, 0xff, 0xf5, 0xf5, 0xf5, 0xff, 0xae, 0xae, 0xae, 0xff, 0x7c, 0x7c, 0x7c, 0xff, 
  0xfe, 0xfe, 0xfe, 0xff, 0xf7, 0xf7, 0xf7, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xbe, 0xbe, 0xbe, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc1, 0xff, 0xc2, 0xc2, 0xc0, 0xff, 0xd1, 0xd1, 0xbb, 0xff, 0xcd, 0xcd, 0xbc, 0xff, 0xc1, 0xc1, 0xc0, 0xff, 0xc0, 0xc0, 0xc1, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc3, 0xc3, 0xc3, 0xff, 0xbf, 0xbf, 0xbf, 0xff, 0x6c, 0x6c, 0x6c, 0xff, 0x70, 0x70, 0x70, 0xff, 
  0xfe, 0xfe, 0xfe, 0xff, 0xf7, 0xf7, 0xf7, 0xff, 0xbe, 0xbe, 0xbe, 0xff, 0xbc, 0xbc, 0xbc, 0xff, 0xbd, 0xbd, 0xbf, 0xff, 0xca, 0xca, 0xba, 0xff, 0xe9, 0xe9, 0xb0, 0xff, 0x72, 0x72, 0xd7, 0xff, 0x26, 0x26, 0xf0, 0xff, 0xb9, 0xb9, 0xc0, 0xff, 0xc4, 0xc4, 0xbd, 0xff, 0xbe, 0xbe, 0xbe, 0xff, 0xbf, 0xbf, 0xbf, 0xff, 0xc4, 0xc4, 0xc4, 0xff, 0x80, 0x80, 0x80, 0xff, 0x7c, 0x7c, 0x7c, 0xff, 
  0xfe, 0xfe, 0xfe, 0xff, 0xf7, 0xf7, 0xf7, 0xff, 0xbe, 0xbe, 0xc1, 0xff, 0xc5, 0xc5, 0xbc, 0xff, 0xd9, 0xd9, 0xb8, 0xff, 0xaf, 0xaf, 0xc6, 0xff, 0x5a, 0x5a, 0xe1, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xb8, 0xb8, 0xc2, 0xff, 0xc8, 0xc8, 0xbe, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc1, 0xc1, 0xc1, 0xff, 0xc4, 0xc4, 0xc4, 0xff, 0x7f, 0x7f, 0x7f, 0xff, 0x7b, 0x7b, 0x7b, 0xff, 
  0xfe, 0xfe, 0xfe, 0xff, 0xf7, 0xf7, 0xf7, 0xff, 0xc7, 0xc7, 0xbe, 0xff, 0xbf, 0xbf, 0xbe, 0xff, 0x49, 0x49, 0xe7, 0xff, 0x08, 0x08, 0xfc, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x14, 0x14, 0xf8, 0xff, 0xb9, 0xb9, 0xc2, 0xff, 0xc7, 0xc7, 0xbe, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc1, 0xc1, 0xc1, 0xff, 0xc4, 0xc4, 0xc4, 0xff, 0x7f, 0x7f, 0x7f, 0xff, 0x7b, 0x7b, 0x7b, 0xff, 
  0xfe, 0xfe, 0xfe, 0xff, 0xf7, 0xf7, 0xf7, 0xff, 0xc9, 0xc9, 0xbd, 0xff, 0xbe, 0xbe, 0xbf, 0xff, 0x2c, 0x2c, 0xf1, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x14, 0x14, 0xf8, 0xff, 0xb9, 0xb9, 0xc2, 0xff, 0xc7, 0xc7, 0xbe, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc1, 0xc1, 0xc1, 0xff, 0xc4, 0xc4, 0xc4, 0xff, 0x7f, 0x7f, 0x7f, 0xff, 0x7b, 0x7b, 0x7b, 0xff, 
  0xfe, 0xfe, 0xfe, 0xff, 0xf7, 0xf7, 0xf7, 0xff, 0xbd, 0xbd, 0xc1, 0xff, 0xca, 0xca, 0xba, 0xff, 0xd1, 0xd1, 0xbb, 0xff, 0x96, 0x96, 0xce, 0xff, 0x35, 0x35, 0xe9, 0xff, 0x00, 0x00, 0xff, 0xff, 0x0f, 0x0f, 0xff, 0xff, 0xb9, 0xb9, 0xc3, 0xff, 0xc7, 0xc7, 0xbd, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc1, 0xc1, 0xc1, 0xff, 0xc4, 0xc4, 0xc4, 0xff, 0x7f, 0x7f, 0x7f, 0xff, 0x7b, 0x7b, 0x7b, 0xff, 
  0xfe, 0xfe, 0xfe, 0xff, 0xf7, 0xf7, 0xf7, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xbc, 0xbc, 0xbf, 0xff, 0xc5, 0xc5, 0xbe, 0xff, 0xd2, 0xd2, 0xba, 0xff, 0xe8, 0xe8, 0xcb, 0xff, 0x55, 0x55, 0xa1, 0xff, 0x00, 0x00, 0x4f, 0xff, 0xb9, 0xb9, 0xbc, 0xff, 0xc7, 0xc7, 0xc4, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc1, 0xc1, 0xc1, 0xff, 0xc4, 0xc4, 0xc4, 0xff, 0x7f, 0x7f, 0x7f, 0xff, 0x7b, 0x7b, 0x7b, 0xff, 
  0xfe, 0xfe, 0xfe, 0xff, 0xf7, 0xf7, 0xf7, 0xff, 0xbe, 0xbe, 0xbe, 0xff, 0xc1, 0xc1, 0xc1, 0xff, 0xd1, 0xd1, 0xd1, 0xff, 0xd0, 0xd0, 0xd1, 0xff, 0xf1, 0xf1, 0xf0, 0xff, 0x92, 0x92, 0x70, 0xff, 0x00, 0x00, 0x00, 0xff, 0xc9, 0xc9, 0xc8, 0xff, 0xd8, 0xd8, 0xd9, 0xff, 0xd1, 0xd1, 0xd1, 0xff, 0xc4, 0xc4, 0xc4, 0xff, 0xc2, 0xc2, 0xc2, 0xff, 0x7f, 0x7f, 0x7f, 0xff, 0x7b, 0x7b, 0x7b, 0xff, 
  0xfe, 0xfe, 0xfe, 0xff, 0xf7, 0xf7, 0xf7, 0xff, 0xc3, 0xc3, 0xc3, 0xff, 0xb9, 0xb9, 0xb9, 0xff, 0xa3, 0xa3, 0xa3, 0xff, 0xa3, 0xa3, 0xa3, 0xff, 0xb9, 0xb9, 0xb9, 0xff, 0x66, 0x66, 0x66, 0xff, 0x00, 0x00, 0x00, 0xff, 0x9d, 0x9d, 0x9d, 0xff, 0xa9, 0xa9, 0xa9, 0xff, 0xa3, 0xa3, 0xa3, 0xff, 0xbc, 0xbc, 0xbc, 0xff, 0xc7, 0xc7, 0xc7, 0xff, 0x7f, 0x7f, 0x7f, 0xff, 0x7b, 0x7b, 0x7b, 0xff, 
  0xfe, 0xfe, 0xfe, 0xff, 0xf7, 0xf7, 0xf7, 0xff, 0xd5, 0xd5, 0xd5, 0xff, 0x98, 0x98, 0x98, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x9a, 0x9a, 0x9a, 0xff, 0xd8, 0xd8, 0xd8, 0xff, 0x7f, 0x7f, 0x7f, 0xff, 0x7b, 0x7b, 0x7b, 0xff, 
  0xfe, 0xfe, 0xfe, 0xff, 0xf9, 0xf9, 0xf9, 0xff, 0xd2, 0xd2, 0xd2, 0xff, 0xa3, 0xa3, 0xa3, 0xff, 0x25, 0x25, 0x25, 0xff, 0x25, 0x25, 0x25, 0xff, 0x25, 0x25, 0x25, 0xff, 0x27, 0x27, 0x27, 0xff, 0x29, 0x29, 0x29, 0xff, 0x26, 0x26, 0x26, 0xff, 0x25, 0x25, 0x25, 0xff, 0x25, 0x25, 0x25, 0xff, 0xa6, 0xa6, 0xa6, 0xff, 0xd4, 0xd4, 0xd4, 0xff, 0x7f, 0x7f, 0x7f, 0xff, 0x7b, 0x7b, 0x7b, 0xff, 
  0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbe, 0xbe, 0xbe, 0xff, 0xc5, 0xc5, 0xc5, 0xff, 0xd1, 0xd1, 0xd1, 0xff, 0xd1, 0xd1, 0xd1, 0xff, 0xd1, 0xd1, 0xd1, 0xff, 0xd1, 0xd1, 0xd1, 0xff, 0xd1, 0xd1, 0xd1, 0xff, 0xd1, 0xd1, 0xd1, 0xff, 0xd1, 0xd1, 0xd1, 0xff, 0xd1, 0xd1, 0xd1, 0xff, 0xc7, 0xc7, 0xc7, 0xff, 0xc6, 0xc6, 0xc6, 0xff, 0x7f, 0x7f, 0x7f, 0xff, 0x7c, 0x7c, 0x7c, 0xff, 
  0xf0, 0xf0, 0xf0, 0xff, 0xae, 0xae, 0xae, 0xff, 0x6c, 0x6c, 0x6c, 0xff, 0x80, 0x80, 0x80, 0xff, 0x80, 0x80, 0x80, 0xff, 0x80, 0x80, 0x80, 0xff, 0x80, 0x80, 0x80, 0xff, 0x80, 0x80, 0x80, 0xff, 0x80, 0x80, 0x80, 0xff, 0x80, 0x80, 0x80, 0xff, 0x80, 0x80, 0x80, 0xff, 0x80, 0x80, 0x80, 0xff, 0x7f, 0x7f, 0x7f, 0xff, 0x7f, 0x7f, 0x7f, 0xff, 0x80, 0x80, 0x80, 0xff, 0x7f, 0x7f, 0x7f, 0xff, 
  0xc1, 0xc1, 0xc1, 0xff, 0x7c, 0x7c, 0x7c, 0xff, 0x71, 0x71, 0x71, 0xff, 0x7c, 0x7c, 0x7c, 0xff, 0x7b, 0x7b, 0x7b, 0xff, 0x7b, 0x7b, 0x7b, 0xff, 0x7b, 0x7b, 0x7b, 0xff, 0x7b, 0x7b, 0x7b, 0xff, 0x7b, 0x7b, 0x7b, 0xff, 0x7b, 0x7b, 0x7b, 0xff, 0x7b, 0x7b, 0x7b, 0xff, 0x7b, 0x7b, 0x7b, 0xff, 0x7b, 0x7b, 0x7b, 0xff, 0x7d, 0x7d, 0x7d, 0xff, 0x80, 0x80, 0x80, 0xff, 0x61, 0x61, 0x61, 0xff, 
#endif
};

const lv_img_dsc_t game_minesweeper_img_flag = {
  .header.cf = LV_IMG_CF_TRUE_COLOR,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 16,
  .header.h = 16,
  .data_size = 256 * LV_COLOR_SIZE / 8,
  .data = game_minesweeper_img_flag_map,
};
