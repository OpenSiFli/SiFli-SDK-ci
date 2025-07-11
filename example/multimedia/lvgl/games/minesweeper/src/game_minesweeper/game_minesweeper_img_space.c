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

#ifndef LV_ATTRIBUTE_IMG_GMAE_MINESWEEPER_IMG_SPACE
#define LV_ATTRIBUTE_IMG_GMAE_MINESWEEPER_IMG_SPACE
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_GMAE_MINESWEEPER_IMG_SPACE uint8_t gmae_minesweeper_img_space_map[] = {
#if LV_COLOR_DEPTH == 1 || LV_COLOR_DEPTH == 8
  /*Pixel format: Red: 3 bit, Green: 3 bit, Blue: 2 bit*/
  0xb6, 0xb7, 0xb7, 0xb7, 0xb7, 0xb7, 0xb7, 0xb7, 0xb7, 0xb7, 0xb7, 0xb7, 0xb7, 0xb7, 0xb7, 0xb6, 
  0xb7, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 
  0xb7, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xb7, 
  0xb7, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xb7, 
  0xb7, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xb7, 
  0xb7, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xb7, 
  0xb7, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xb7, 
  0xb7, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xb7, 
  0xb7, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xb7, 
  0xb7, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xb7, 
  0xb7, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xb7, 
  0xb7, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xb7, 
  0xb7, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xb7, 
  0xb7, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xb7, 
  0xb7, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 
  0xb6, 0xb7, 0xb7, 0xb7, 0xb7, 0xb7, 0xb7, 0xb7, 0xb7, 0xb7, 0xb7, 0xb7, 0xb7, 0xb7, 0xb7, 0xb6, 
#endif
#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP == 0
  /*Pixel format: Red: 5 bit, Green: 6 bit, Blue: 5 bit*/
  0xd3, 0x9c, 0x55, 0xad, 0x55, 0xad, 0x55, 0xad, 0x55, 0xad, 0x55, 0xad, 0x55, 0xad, 0x55, 0xad, 0x55, 0xad, 0x55, 0xad, 0x55, 0xad, 0x55, 0xad, 0x55, 0xad, 0x55, 0xad, 0x55, 0xad, 0xf4, 0xa4, 
  0x55, 0xad, 0x59, 0xce, 0x39, 0xce, 0x39, 0xce, 0x39, 0xce, 0x39, 0xce, 0x39, 0xce, 0x39, 0xce, 0x39, 0xce, 0x39, 0xce, 0x39, 0xce, 0x39, 0xce, 0x39, 0xce, 0x39, 0xce, 0x79, 0xce, 0x96, 0xb5, 
  0x35, 0xad, 0x39, 0xce, 0x38, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x59, 0xce, 0x96, 0xb5, 
  0x35, 0xad, 0x39, 0xce, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x39, 0xce, 0x96, 0xb5, 
  0x35, 0xad, 0x39, 0xce, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x39, 0xce, 0x96, 0xb5, 
  0x35, 0xad, 0x39, 0xce, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x39, 0xce, 0x96, 0xb5, 
  0x35, 0xad, 0x39, 0xce, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x39, 0xce, 0x96, 0xb5, 
  0x35, 0xad, 0x39, 0xce, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x39, 0xce, 0x96, 0xb5, 
  0x35, 0xad, 0x39, 0xce, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x39, 0xce, 0x96, 0xb5, 
  0x35, 0xad, 0x39, 0xce, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x39, 0xce, 0x96, 0xb5, 
  0x35, 0xad, 0x39, 0xce, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x39, 0xce, 0x96, 0xb5, 
  0x35, 0xad, 0x39, 0xce, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x39, 0xce, 0x96, 0xb5, 
  0x35, 0xad, 0x39, 0xce, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x39, 0xce, 0x96, 0xb5, 
  0x35, 0xad, 0x39, 0xce, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x39, 0xce, 0x96, 0xb5, 
  0x55, 0xad, 0x79, 0xce, 0x59, 0xce, 0x59, 0xce, 0x59, 0xce, 0x59, 0xce, 0x59, 0xce, 0x59, 0xce, 0x59, 0xce, 0x59, 0xce, 0x59, 0xce, 0x59, 0xce, 0x59, 0xce, 0x59, 0xce, 0x79, 0xce, 0xb6, 0xb5, 
  0xd3, 0x9c, 0x76, 0xb5, 0x75, 0xad, 0x55, 0xad, 0x55, 0xad, 0x55, 0xad, 0x55, 0xad, 0x55, 0xad, 0x55, 0xad, 0x55, 0xad, 0x55, 0xad, 0x55, 0xad, 0x55, 0xad, 0x55, 0xad, 0x76, 0xb5, 0x14, 0xa5, 
#endif
#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP != 0
  /*Pixel format: Red: 5 bit, Green: 6 bit, Blue: 5 bit BUT the 2 bytes are swapped*/
  0x9c, 0xd3, 0xad, 0x55, 0xad, 0x55, 0xad, 0x55, 0xad, 0x55, 0xad, 0x55, 0xad, 0x55, 0xad, 0x55, 0xad, 0x55, 0xad, 0x55, 0xad, 0x55, 0xad, 0x55, 0xad, 0x55, 0xad, 0x55, 0xad, 0x55, 0xa4, 0xf4, 
  0xad, 0x55, 0xce, 0x59, 0xce, 0x39, 0xce, 0x39, 0xce, 0x39, 0xce, 0x39, 0xce, 0x39, 0xce, 0x39, 0xce, 0x39, 0xce, 0x39, 0xce, 0x39, 0xce, 0x39, 0xce, 0x39, 0xce, 0x39, 0xce, 0x79, 0xb5, 0x96, 
  0xad, 0x35, 0xce, 0x39, 0xc6, 0x38, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xce, 0x59, 0xb5, 0x96, 
  0xad, 0x35, 0xce, 0x39, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xce, 0x39, 0xb5, 0x96, 
  0xad, 0x35, 0xce, 0x39, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xce, 0x39, 0xb5, 0x96, 
  0xad, 0x35, 0xce, 0x39, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xce, 0x39, 0xb5, 0x96, 
  0xad, 0x35, 0xce, 0x39, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xce, 0x39, 0xb5, 0x96, 
  0xad, 0x35, 0xce, 0x39, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xce, 0x39, 0xb5, 0x96, 
  0xad, 0x35, 0xce, 0x39, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xce, 0x39, 0xb5, 0x96, 
  0xad, 0x35, 0xce, 0x39, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xce, 0x39, 0xb5, 0x96, 
  0xad, 0x35, 0xce, 0x39, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xce, 0x39, 0xb5, 0x96, 
  0xad, 0x35, 0xce, 0x39, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xce, 0x39, 0xb5, 0x96, 
  0xad, 0x35, 0xce, 0x39, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xce, 0x39, 0xb5, 0x96, 
  0xad, 0x35, 0xce, 0x39, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xc6, 0x18, 0xce, 0x39, 0xb5, 0x96, 
  0xad, 0x55, 0xce, 0x79, 0xce, 0x59, 0xce, 0x59, 0xce, 0x59, 0xce, 0x59, 0xce, 0x59, 0xce, 0x59, 0xce, 0x59, 0xce, 0x59, 0xce, 0x59, 0xce, 0x59, 0xce, 0x59, 0xce, 0x59, 0xce, 0x79, 0xb5, 0xb6, 
  0x9c, 0xd3, 0xb5, 0x76, 0xad, 0x75, 0xad, 0x55, 0xad, 0x55, 0xad, 0x55, 0xad, 0x55, 0xad, 0x55, 0xad, 0x55, 0xad, 0x55, 0xad, 0x55, 0xad, 0x55, 0xad, 0x55, 0xad, 0x55, 0xb5, 0x76, 0xa5, 0x14, 
#endif
#if LV_COLOR_DEPTH == 32
  /*Pixel format: Fix 0xFF: 8 bit, Red: 8 bit, Green: 8 bit, Blue: 8 bit*/
  0x97, 0x97, 0x97, 0xff, 0xa8, 0xa8, 0xa8, 0xff, 0xa6, 0xa6, 0xa6, 0xff, 0xa6, 0xa6, 0xa6, 0xff, 0xa6, 0xa6, 0xa6, 0xff, 0xa6, 0xa6, 0xa6, 0xff, 0xa6, 0xa6, 0xa6, 0xff, 0xa6, 0xa6, 0xa6, 0xff, 0xa6, 0xa6, 0xa6, 0xff, 0xa6, 0xa6, 0xa6, 0xff, 0xa6, 0xa6, 0xa6, 0xff, 0xa6, 0xa6, 0xa6, 0xff, 0xa6, 0xa6, 0xa6, 0xff, 0xa6, 0xa6, 0xa6, 0xff, 0xa8, 0xa8, 0xa8, 0xff, 0x9c, 0x9c, 0x9c, 0xff, 
  0xa6, 0xa6, 0xa6, 0xff, 0xc9, 0xc9, 0xc9, 0xff, 0xc5, 0xc5, 0xc5, 0xff, 0xc4, 0xc4, 0xc4, 0xff, 0xc4, 0xc4, 0xc4, 0xff, 0xc4, 0xc4, 0xc4, 0xff, 0xc4, 0xc4, 0xc4, 0xff, 0xc4, 0xc4, 0xc4, 0xff, 0xc4, 0xc4, 0xc4, 0xff, 0xc4, 0xc4, 0xc4, 0xff, 0xc4, 0xc4, 0xc4, 0xff, 0xc4, 0xc4, 0xc4, 0xff, 0xc4, 0xc4, 0xc4, 0xff, 0xc4, 0xc4, 0xc4, 0xff, 0xca, 0xca, 0xca, 0xff, 0xb1, 0xb1, 0xb1, 0xff, 
  0xa4, 0xa4, 0xa4, 0xff, 0xc5, 0xc5, 0xc5, 0xff, 0xc2, 0xc2, 0xc2, 0xff, 0xc1, 0xc1, 0xc1, 0xff, 0xc1, 0xc1, 0xc1, 0xff, 0xc1, 0xc1, 0xc1, 0xff, 0xc1, 0xc1, 0xc1, 0xff, 0xc1, 0xc1, 0xc1, 0xff, 0xc1, 0xc1, 0xc1, 0xff, 0xc1, 0xc1, 0xc1, 0xff, 0xc1, 0xc1, 0xc1, 0xff, 0xc1, 0xc1, 0xc1, 0xff, 0xc1, 0xc1, 0xc1, 0xff, 0xc1, 0xc1, 0xc1, 0xff, 0xc6, 0xc6, 0xc6, 0xff, 0xaf, 0xaf, 0xaf, 0xff, 
  0xa4, 0xa4, 0xa4, 0xff, 0xc4, 0xc4, 0xc4, 0xff, 0xc1, 0xc1, 0xc1, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc5, 0xc5, 0xc5, 0xff, 0xae, 0xae, 0xae, 0xff, 
  0xa4, 0xa4, 0xa4, 0xff, 0xc4, 0xc4, 0xc4, 0xff, 0xc1, 0xc1, 0xc1, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc5, 0xc5, 0xc5, 0xff, 0xae, 0xae, 0xae, 0xff, 
  0xa4, 0xa4, 0xa4, 0xff, 0xc4, 0xc4, 0xc4, 0xff, 0xc1, 0xc1, 0xc1, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc5, 0xc5, 0xc5, 0xff, 0xae, 0xae, 0xae, 0xff, 
  0xa4, 0xa4, 0xa4, 0xff, 0xc4, 0xc4, 0xc4, 0xff, 0xc1, 0xc1, 0xc1, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc5, 0xc5, 0xc5, 0xff, 0xae, 0xae, 0xae, 0xff, 
  0xa4, 0xa4, 0xa4, 0xff, 0xc4, 0xc4, 0xc4, 0xff, 0xc1, 0xc1, 0xc1, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc5, 0xc5, 0xc5, 0xff, 0xae, 0xae, 0xae, 0xff, 
  0xa4, 0xa4, 0xa4, 0xff, 0xc4, 0xc4, 0xc4, 0xff, 0xc1, 0xc1, 0xc1, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc5, 0xc5, 0xc5, 0xff, 0xae, 0xae, 0xae, 0xff, 
  0xa4, 0xa4, 0xa4, 0xff, 0xc4, 0xc4, 0xc4, 0xff, 0xc1, 0xc1, 0xc1, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc5, 0xc5, 0xc5, 0xff, 0xae, 0xae, 0xae, 0xff, 
  0xa4, 0xa4, 0xa4, 0xff, 0xc4, 0xc4, 0xc4, 0xff, 0xc1, 0xc1, 0xc1, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc5, 0xc5, 0xc5, 0xff, 0xae, 0xae, 0xae, 0xff, 
  0xa4, 0xa4, 0xa4, 0xff, 0xc4, 0xc4, 0xc4, 0xff, 0xc1, 0xc1, 0xc1, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc5, 0xc5, 0xc5, 0xff, 0xae, 0xae, 0xae, 0xff, 
  0xa4, 0xa4, 0xa4, 0xff, 0xc4, 0xc4, 0xc4, 0xff, 0xc1, 0xc1, 0xc1, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc5, 0xc5, 0xc5, 0xff, 0xae, 0xae, 0xae, 0xff, 
  0xa4, 0xa4, 0xa4, 0xff, 0xc4, 0xc4, 0xc4, 0xff, 0xc1, 0xc1, 0xc1, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc5, 0xc5, 0xc5, 0xff, 0xae, 0xae, 0xae, 0xff, 
  0xa7, 0xa7, 0xa7, 0xff, 0xca, 0xca, 0xca, 0xff, 0xc7, 0xc7, 0xc7, 0xff, 0xc6, 0xc6, 0xc6, 0xff, 0xc6, 0xc6, 0xc6, 0xff, 0xc6, 0xc6, 0xc6, 0xff, 0xc6, 0xc6, 0xc6, 0xff, 0xc6, 0xc6, 0xc6, 0xff, 0xc6, 0xc6, 0xc6, 0xff, 0xc6, 0xc6, 0xc6, 0xff, 0xc6, 0xc6, 0xc6, 0xff, 0xc6, 0xc6, 0xc6, 0xff, 0xc6, 0xc6, 0xc6, 0xff, 0xc6, 0xc6, 0xc6, 0xff, 0xcb, 0xcb, 0xcb, 0xff, 0xb2, 0xb2, 0xb2, 0xff, 
  0x98, 0x98, 0x98, 0xff, 0xac, 0xac, 0xac, 0xff, 0xaa, 0xaa, 0xaa, 0xff, 0xa9, 0xa9, 0xa9, 0xff, 0xa9, 0xa9, 0xa9, 0xff, 0xa9, 0xa9, 0xa9, 0xff, 0xa9, 0xa9, 0xa9, 0xff, 0xa9, 0xa9, 0xa9, 0xff, 0xa9, 0xa9, 0xa9, 0xff, 0xa9, 0xa9, 0xa9, 0xff, 0xa9, 0xa9, 0xa9, 0xff, 0xa9, 0xa9, 0xa9, 0xff, 0xa9, 0xa9, 0xa9, 0xff, 0xa9, 0xa9, 0xa9, 0xff, 0xac, 0xac, 0xac, 0xff, 0x9e, 0x9e, 0x9e, 0xff, 
#endif
};

const lv_img_dsc_t game_minesweeper_img_space = {
  .header.cf = LV_IMG_CF_TRUE_COLOR,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 16,
  .header.h = 16,
  .data_size = 256 * LV_COLOR_SIZE / 8,
  .data = gmae_minesweeper_img_space_map,
};
