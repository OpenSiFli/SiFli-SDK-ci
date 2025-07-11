/*
 * SPDX-FileCopyrightText: 2019-2025 SiFli Technologies(Nanjing) Co., Ltd
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __MEM_MAP__
#define __MEM_MAP__

//#define FLASH_XIP
#define END_ADDR(start, size)  ((start) + (size) - 1)

//======================================= Memory resources  =======================================

//================== HPSYS ==================

// Size
#define HPSYS_ROM_SIZE      (64*1024)
#define HPSYS_ITCM_SIZE     (64*1024)
#define HPSYS_RETM_SIZE     (64*1024)
#define HPSYS_DTCM_SIZE     (128*1024)
#define HPSYS_RAM0_SIZE     (128*1024)
#define HPSYS_RAM1_SIZE     (128*1024)
#define HPSYS_RAM2_SIZE     (256*1024)
#define HPSYS_RAM3_SIZE     (512*1024)
#define HPSYS_RAM4_SIZE     (512*1024)
#define HPSYS_RAM5_SIZE     (512*1024)
#define HPSYS_RAM6_SIZE     (128*1024)
#define HPSYS_RAM7_SIZE     (128*1024)
#define HPSYS_RAM8_SIZE     (128*1024)
#define HPSYS_RAM9_SIZE     (128*1024)


#ifdef FPGA                 /* RAM3~RAM6 is not available on FPGA */
#undef HPSYS_RAM6_SIZE
#define HPSYS_RAM6_SIZE     (0)
#undef HPSYS_RAM7_SIZE
#define HPSYS_RAM7_SIZE     (0)
#if 0 //def FPGA_PRO
    #define HPSYS_RAM_SIZE      (HPSYS_RAM0_SIZE+HPSYS_RAM1_SIZE+HPSYS_RAM2_SIZE+HPSYS_RAM3_SIZE)
#else
    #define HPSYS_RAM_SIZE      (HPSYS_RAM0_SIZE+HPSYS_RAM1_SIZE+HPSYS_RAM2_SIZE)
#endif
#else

// Total 1.5M Bytes, rest 512KB is reserved to ACPU
#define HPSYS_RAM_SIZE      (HPSYS_RAM0_SIZE+HPSYS_RAM1_SIZE+HPSYS_RAM2_SIZE \
                                 +HPSYS_RAM3_SIZE+HPSYS_RAM4_SIZE+HPSYS_RAM5_SIZE)

#endif



// Address
#define HPSYS_ROM_BASE      (0x00000000)
#define HPSYS_ITCM_BASE     (0x00010000)
#define HPSYS_RETM_BASE     (0x00020000)
#define HPSYS_DTCM_BASE     (0x20000000)
#define HPSYS_RAM0_BASE     (0x20000000)
#define HPSYS_RAM1_BASE     (0x20020000)
#define HPSYS_RAM2_BASE     (0x20040000)
#define HPSYS_RAM3_BASE     (0x20080000)
#define HPSYS_RAM4_BASE     (0x20100000)
#define HPSYS_RAM5_BASE     (0x20180000)
#define HPSYS_RAM6_BASE     (0x20200000)
#define HPSYS_RAM7_BASE     (0x20220000)
#define HPSYS_RAM8_BASE     (0x20240000)
#define HPSYS_RAM9_BASE     (0x20260000)



#define HPSYS_RAM_END       (END_ADDR(HPSYS_RAM0_BASE, HPSYS_RAM_SIZE))
#define HPSYS_ITCM_END      (END_ADDR(HPSYS_ITCM_BASE, HPSYS_ITCM_SIZE))
#define HPSYS_RETM_END      (END_ADDR(HPSYS_RETM_BASE, HPSYS_RETM_SIZE))


// Mailbox
#define HPSYS_MBOX_BUF_SIZE (2*512)
#define HPSYS_MBOX_BUF_ADDR (HPSYS_RAM_END+1-HPSYS_MBOX_BUF_SIZE)

#define HCPU2LCPU_MB_CH2_BUF_START_ADDR  (HPSYS_MBOX_BUF_ADDR)               /* 0x2007FC00 */
#define HCPU2LCPU_MB_CH2_BUF_SIZE        (512)
#define HCPU2LCPU_MB_CH2_BUF_END_ADDR    (END_ADDR(HCPU2LCPU_MB_CH2_BUF_START_ADDR, HCPU2LCPU_MB_CH2_BUF_SIZE))

#define HCPU2LCPU_MB_CH1_BUF_START_ADDR  (HCPU2LCPU_MB_CH2_BUF_END_ADDR+1)   /* 0x2007FE00 */
#define HCPU2LCPU_MB_CH1_BUF_SIZE        (512)
#define HCPU2LCPU_MB_CH1_BUF_END_ADDR    (END_ADDR(HCPU2LCPU_MB_CH1_BUF_START_ADDR, HCPU2LCPU_MB_CH1_BUF_SIZE))

//================== LPSYS ==================
// Size
#define LPSYS_ROM_SIZE      (768*1024)
#define LPSYS_ITCM_SIZE     (16*1024)
#define LPSYS_DTCM_SIZE     (16*1024)
#define LPSYS_RAM_SIZE      (800*1024)
#define LPSYS_EM_SIZE       (39*1024)
#define LCPU_HCPU_AUDIO_MEM_SIZE         (1 * 1024)



// Address, TODO: LPSYS has more SRAM
#define LPSYS_ROM_BASE      (0x00000000)
#define LPSYS_ITCM_BASE     (0x003FC000)
#define LPSYS_DTCM_BASE     (0x203FC000)
#define LPSYS_SRAM_BASE     (0x20400000)
#define LPSYS_RAM_BASE      (0x203FC000)
#define LPSYS_ROM_RAM_BASE  (0x204EC000)
#define LPSYS_RAM_END       END_ADDR(LPSYS_RAM_BASE, LPSYS_RAM_SIZE)
#define LPSYS_RAM_CBUS_BASE (LPSYS_ITCM_BASE)
#define LPSYS_RAM_CBUS_END  END_ADDR(LPSYS_RAM_CBUS_BASE, LPSYS_RAM_SIZE)
#define LPSYS_PATCH_BASE    (0x204FA000)
#define LPSYS_PATCH_END     END_ADDR(LPSYS_PATCH_BASE, LCPU_PATCH_TOTAL_SIZE)
#define LPSYS_EM_BASE       (0x204F0000)
#define LPSYS_EM_END        END_ADDR(LPSYS_EM_BASE, LPSYS_EM_SIZE)  /* 0x20437FFF */
#define LCPU_AUDIO_MEM_START_ADDR    (0x204FF000)
#define LCPU_AUDIO_MEM_START_ADDR_H  (LCPU_AUDIO_MEM_START_ADDR)
#define LCPU_AUDIO_MEM_END_ADDR      (END_ADDR(LCPU_AUDIO_MEM_START_ADDR + LCPU_HCPU_AUDIO_MEM_SIZE))



// Mailbox
#define LPSYS_MBOX_BUF_SIZE (2*512)
#define LCPU2HCPU_MB_CH1_BUF_START_ADDR  (LPSYS_RAM_END - LPSYS_MBOX_BUF_SIZE + 1)  /* 0x20423C00 */
#define LCPU2HCPU_MB_CH1_BUF_SIZE        (512)
#define LCPU2HCPU_MB_CH1_BUF_END_ADDR    (END_ADDR(LCPU2HCPU_MB_CH1_BUF_START_ADDR, LCPU2HCPU_MB_CH1_BUF_SIZE))

#define LCPU2HCPU_MB_CH2_BUF_START_ADDR  (LCPU2HCPU_MB_CH1_BUF_END_ADDR + 1)        /* 0x20423E00 */
#define LCPU2HCPU_MB_CH2_BUF_SIZE        (512)
#define LCPU2HCPU_MB_CH2_BUF_END_ADDR    (END_ADDR(LCPU2HCPU_MB_CH2_BUF_START_ADDR, LCPU2HCPU_MB_CH2_BUF_SIZE))

//================== QSPI Memory ==================

#define QSPI1_MEM_BASE   (0x10000000)
#define QSPI2_MEM_BASE   (0x12000000)
#define QSPI3_MEM_BASE   (0x14000000)
#define QSPI4_MEM_BASE   (0x18000000)
#define QSPI5_MEM_BASE   (0x1C000000)

#define MPI1_MEM_BASE   QSPI1_MEM_BASE
#define MPI2_MEM_BASE   QSPI2_MEM_BASE
#define MPI3_MEM_BASE   QSPI3_MEM_BASE
#define MPI4_MEM_BASE   QSPI4_MEM_BASE
#define MPI5_MEM_BASE   QSPI5_MEM_BASE

#define HPSYS_MPI_MEM_CBUS_2_SBUS_OFFSET   (0x50000000)

#define QSPI1_MAX_SIZE      (0x2000000)
#define QSPI2_MAX_SIZE      (0x2000000)
#define QSPI3_MAX_SIZE      (0x4000000)
#define QSPI4_MAX_SIZE      (0x4000000)
#define QSPI5_MAX_SIZE      (0x4000000)

#define SDIO_LOGIC_ADDR     (QSPI4_MEM_BASE+HPSYS_MPI_MEM_CBUS_2_SBUS_OFFSET)

// Size
#define FLASH_TABLE_SIZE            (20*1024)
#define FLASH_CAL_TABLE_SIZE        (8*1024)
#define FLASH_BOOT_PATCH_SIZE       (64*1024)

#define FLASH_BASE_ADDR             (QSPI5_MEM_BASE)
#define FLASH_TABLE_START_ADDR      (FLASH_BASE_ADDR)
#define FLASH_TABLE_END_ADDR        (END_ADDR(FLASH_TABLE_START_ADDR, FLASH_TABLE_SIZE))
#define FLASH_CAL_TABLE_START_ADDR  (FLASH_TABLE_END_ADDR+1)
#define FLASH_BOOT_PATCH_START_ADDR (0x1C010000)
#define FLASH_BOOT_PATCH_END_ADDR   (END_ADDR(FLASH_BOOT_PATCH_START_ADDR, FLASH_BOOT_PATCH_SIZE)) /* 0x1C01FFFF */
//================== Bootloader ==================
#define FLASH_BOOT_LOADER_START_ADDR (FLASH_BOOT_PATCH_END_ADDR + 1)   /* 0x1C020000 */
#define FLASH_BOOT_LOADER_SIZE       (128*1024)
#define FLASH_BOOT_LOADER_END_ADDR   (END_ADDR(FLASH_BOOT_LOADER_START_ADDR, FLASH_BOOT_LOADER_SIZE))

//================== Flash 1 ==================
#define FLASH_USER_CODE_START_ADDR   (QSPI1_MEM_BASE)   /* 0x10000000 */
#define FLASH1_BASE_ADDR            (QSPI1_MEM_BASE)
#ifdef BSP_QSPI1_MEM_SIZE
    #define FLASH1_SIZE                 (BSP_QSPI1_MEM_SIZE*1024*1024)
#else
    #define FLASH1_SIZE                 (0)
#endif

//================== Flash 2 ==================
#define FLASH2_BASE_ADDR            (QSPI2_MEM_BASE)
#ifdef BSP_QSPI2_MEM_SIZE
    #define FLASH2_SIZE                 (BSP_QSPI2_MEM_SIZE*1024*1024)
#else
    #define FLASH2_SIZE                 (0)
#endif

//================== Flash 3 ==================
#define FLASH3_BASE_ADDR            (QSPI3_MEM_BASE)
#ifdef BSP_QSPI3_MEM_SIZE
    #define FLASH3_SIZE                 (BSP_QSPI3_MEM_SIZE*1024*1024)
#else
    #define FLASH3_SIZE                 (0)
#endif

//================== Flash 4 ==================
#define FLASH4_BASE_ADDR            (QSPI4_MEM_BASE)
#ifdef BSP_QSPI4_MEM_SIZE
    #define FLASH4_SIZE                 (BSP_QSPI4_MEM_SIZE*1024*1024)
#else
    #define FLASH4_SIZE                 (0)
#endif

//================== Flash 5 ==================
#define FLASH5_BASE_ADDR            (QSPI5_MEM_BASE)
#ifdef BSP_QSPI5_MEM_SIZE
    #define FLASH5_SIZE                 (BSP_QSPI5_MEM_SIZE*1024*1024)
#else
    #define FLASH5_SIZE                 (0)
#endif

//================== MPI-PSRAM  ==================
// NOTE : set first psram as psram base and not include QSPI PSRAM (add it ?)
#if defined (BSP_MPI1_MODE_3) || defined (BSP_MPI1_MODE_4)
    #define PSRAM_SIZE                  (BSP_QSPI1_MEM_SIZE*1024*1024)
    #define PSRAM_BASE                  (0x60000000)
#elif defined (BSP_MPI2_MODE_3)  || defined (BSP_MPI2_MODE_4)
    #define PSRAM_SIZE                  (BSP_QSPI2_MEM_SIZE*1024*1024)
    #define PSRAM_BASE                  (0x62000000)
#elif defined(BSP_MPI3_MODE_3) || defined (BSP_MPI3_MODE_4)
    #define PSRAM_SIZE                  (BSP_QSPI3_MEM_SIZE*1024*1024)
    #define PSRAM_BASE                  (0x64000000)
#elif defined(BSP_MPI4_MODE_3) || defined (BSP_MPI4_MODE_4)
    #define PSRAM_SIZE                  (BSP_QSPI4_MEM_SIZE*1024*1024)
    #define PSRAM_BASE                  (0x68000000)
#else   // Not define PSRAM, use a default value or assert?
    #define PSRAM_SIZE                  (0)
    #define PSRAM_BASE                  (0x60000000)
#endif  //(BSP_MPI_MODE_3 || BSP_MPI_MODE_4)

//================== QSPI-PSRAM  ==================
#define PSRAM2_BASE_ADDR            (QSPI2_MEM_BASE)
#ifdef BSP_QSPI2_MEM_SIZE
    #define PSRAM2_SIZE                 (BSP_QSPI2_MEM_SIZE*1024*1024)
#else
    #define PSRAM2_SIZE                 (0)
#endif

#define PSRAM3_BASE_ADDR            (QSPI3_MEM_BASE)
#ifdef BSP_QSPI3_MEM_SIZE
    #define PSRAM3_SIZE                 (BSP_QSPI3_MEM_SIZE*1024*1024)
#else
    #define PSRAM3_SIZE                 (0)
#endif

#define PSRAM4_BASE_ADDR            (QSPI4_MEM_BASE)
#ifdef BSP_QSPI4_MEM_SIZE
    #define PSRAM4_SIZE                 (BSP_QSPI4_MEM_SIZE*1024*1024)
#else
    #define PSRAM4_SIZE                 (0)
#endif
#define HPSYS_RAM_IN_ITCM(addr)  (addr>=HPSYS_ITCM_BASE&&addr<(HPSYS_ITCM_BASE+HPSYS_ITCM_SIZE+HPSYS_RETM_SIZE))


//======================================= Code mapping =======================================


//================= Boot loader ===============
// Size
#define BOOTLOADER_CODE_SIZE         (64*1024)
#define BOOTLOADER_RAM_DATA_SIZE     (64*1024) //reserved 4 byte for LCPU_BOOT_ADDR
#define BOOTLOADER_PATCH_CODE_SIZE   (64*1024) // Bootloader patch code in RAM size
#define BOOTLOADER_PATCH_DATA_SIZE   (64*1024)

// Address
#define BOOTLOADER_CODE_START_ADDR          (HPSYS_ROM_BASE)                        // Bootloader in ROM start from 0
#define BOOTLOADER_CODE_END_ADDR            (END_ADDR(BOOTLOADER_CODE_START_ADDR, BOOTLOADER_CODE_SIZE))
#define BOOTLOADER_RAM_DATA_START_ADDR      (HPSYS_RAM0_BASE)              // 0x20000000 
#define BOOTLOADER_RAM_DATA_END_ADDR        (END_ADDR(BOOTLOADER_RAM_DATA_START_ADDR, BOOTLOADER_RAM_DATA_SIZE))

// Bootloader Patch
#define BOOTLOADER_PATCH_CODE_ADDR          (BOOTLOADER_RAM_DATA_END_ADDR + 1)      //0x20010000, Bootloader patch code in RAM start from 2nd 64k bytes of RAM
#define BOOTLOADER_PATCH_CODE_END_ADDR      (END_ADDR(BOOTLOADER_PATCH_CODE_ADDR, BOOTLOADER_PATCH_CODE_SIZE))
#define BOOTLOADER_PATCH_DATA_ADDR          (BOOTLOADER_PATCH_CODE_END_ADDR + 1)    //0x20020000, Bootloader patch data in RAM start from 3th 64k bytes of RAM
#define BOOTLOADER_PATCH_DATA_END_ADDR      (END_ADDR(BOOTLOADER_PATCH_DATA_ADDR, BOOTLOADER_PATCH_DATA_SIZE))

#if BOOTLOADER_PATCH_DATA_END_ADDR >= (HPSYS_RAM0_BASE+HPSYS_RAM_SIZE)
    #error "bootloader ram overflow"
#endif


//================= HP subsys ROM =================
// Size
#define HCPU_CODE_SIZE                  (HPSYS_ROM_SIZE)
#define HCPU_RO_DATA_SIZE               (16*1024)
#define HCPU_RAM_DATA_SIZE              (HPSYS_RAM_SIZE - HCPU_RO_DATA_SIZE - HPSYS_MBOX_BUF_SIZE)
#define HCPU_CODE_START_ADDR            0 //(BOOTLOADER_CODE_END_ADDR+1)
#define HCPU_CODE_END_ADDR              (END_ADDR(HCPU_CODE_START_ADDR, HCPU_CODE_SIZE))
#define HCPU_RAM_DATA_START_ADDR        (HPSYS_RAM0_BASE)         /* 0x20000000 */
#define HCPU_RAM_DATA_END_ADDR          (END_ADDR(HCPU_RAM_DATA_START_ADDR, HCPU_RAM_DATA_SIZE))
#define HCPU_RO_DATA_START_ADDR         (HCPU_RAM_DATA_END_ADDR+1)
#define HCPU_RO_DATA_END_ADDR           (END_ADDR(HCPU_RO_DATA_START_ADDR, HCPU_RO_DATA_SIZE))
#define HCPU_LCPU_CODE_START_ADDR       (LCPU_ITCM_ADDR_2_HCPU_ADDR(LPSYS_ITCM_BASE))

//================= HP subsys Flash1 =================
#ifdef BSP_USING_DFU_COMPRESS
    // DFU Size
    #define DFU_FLASH_CODE_SIZE             (256*1024)
    #define DFU_RES_FLASH_CODE_SIZE         (640*1024)
    #define HCPU_FLASH_CODE_SIZE            (896*1024)

    // DFU Address
    #define DFU_FLASH_CODE_START_ADDR       FLASH_USER_CODE_START_ADDR
    #define DFU_FLASH_CODE_END_ADDR         (END_ADDR(DFU_FLASH_CODE_START_ADDR, DFU_FLASH_CODE_SIZE))  /* 0x1005FFFF */

    #define DFU_RES_FLASH_CODE_START_ADDR   (DFU_FLASH_CODE_END_ADDR + 1)  /* 0x10060000 */
    #define DFU_RES_FLASH_CODE_END_ADDR     (END_ADDR(DFU_RES_FLASH_CODE_START_ADDR, DFU_RES_FLASH_CODE_SIZE))  /* 0x100FFFFF */

    #define HCPU_FLASH_CODE_START_ADDR      (DFU_RES_FLASH_CODE_END_ADDR + 1)  /* 0x10100000 */
    #define HCPU_FLASH_CODE_END_ADDR        (END_ADDR(HCPU_FLASH_CODE_START_ADDR, HCPU_FLASH_CODE_SIZE))  /* 0x101DFFFF */

#else
    // Size
    #define HCPU_FLASH_CODE_SIZE            (1024*1024)

    // Address
    #define HCPU_FLASH_CODE_START_ADDR      FLASH_USER_CODE_START_ADDR  /* 0x10020000 */
    #define HCPU_FLASH_CODE_END_ADDR        (END_ADDR(HCPU_FLASH_CODE_START_ADDR, HCPU_FLASH_CODE_SIZE))  /* 0x100FFFFF */
#endif

#define PSRAM_DATA_START_ADDR               (0x60200000)
#define PSRAM_DATA_SIZE                     (2*1024*1024)
#if PSRAM_DATA_START_ADDR <= HCPU_FLASH_CODE_END_ADDR
    #error "wrong config"
#endif


// Size
#define HCPU_FLASH_IMG_SIZE             (4096*1024)
#define HCPU_FLASH_FONT_SIZE            (4096*3*1024)

// Address
#define HCPU_FLASH_IMG_START_ADDR       (0x10100000)   /* 0x10100000 */
#define HCPU_FLASH_IMG_END_ADDR         (END_ADDR(HCPU_FLASH_IMG_START_ADDR, HCPU_FLASH_IMG_SIZE))  /*  0x105FFFFF */
#define HCPU_FLASH_FONT_START_ADDR      (HCPU_FLASH_IMG_END_ADDR + 1) /* 0x10600000 */
#define HCPU_FLASH_FONT_END_ADDR        (END_ADDR(HCPU_FLASH_FONT_START_ADDR, HCPU_FLASH_FONT_SIZE))

//================= HP subsys Flash2 =================
// Size
#define HCPU_FLASH2_IMG_SIZE            (4096*1024)
#define HCPU_FLASH2_FONT_SIZE           (4096*3*1024)
#define HCPU_FLASH2_IMG_UPGRADE_SIZE    (HCPU_FLASH_IMG_SIZE/4)
#define HCPU_FLASH2_FONT_UPGRADE_SIZE   (HCPU_FLASH2_FONT_SIZE/4)

// Address
#define HCPU_FLASH2_IMG_START_ADDR              (FLASH2_BASE_ADDR)  /* 0x64000000 */
#define HCPU_FLASH2_IMG_END_ADDR                (END_ADDR(HCPU_FLASH2_IMG_START_ADDR, HCPU_FLASH2_IMG_SIZE))  /*  0x643FFFFF */
#define HCPU_FLASH2_FONT_START_ADDR             (HCPU_FLASH2_IMG_END_ADDR + 1)  /* 0x64400000 */
#define HCPU_FLASH2_FONT_END_ADDR               (END_ADDR(HCPU_FLASH2_FONT_START_ADDR, HCPU_FLASH2_FONT_SIZE))
#define HCPU_FLASH2_IMG_UPGRADE_START_ADDR      (HCPU_FLASH2_FONT_END_ADDR + 1)
#define HCPU_FLASH2_IMG_UPGRADE_END_ADDR        (END_ADDR(HCPU_FLASH2_IMG_UPGRADE_START_ADDR, HCPU_FLASH2_IMG_UPGRADE_SIZE))
#define HCPU_FLASH2_FONT_UPGRADE_START_ADDR     (HCPU_FLASH2_IMG_UPGRADE_END_ADDR + 1)
#define HCPU_FLASH2_FONT_UPGRADE_END_ADDR       (END_ADDR(HCPU_FLASH2_FONT_UPGRADE_START_ADDR, HCPU_FLASH2_FONT_UPGRADE_SIZE))


#define ACPU_CODE_START_ADDR                    (HPSYS_RAM6_BASE)
#define ACPU_CODE_SIZE                          (256*1024)

#define ACPU_RAM_SIZE                           (HPSYS_RAM6_SIZE+HPSYS_RAM7_SIZE+HPSYS_RAM8_SIZE+HPSYS_RAM9_SIZE)


//================= LP subsys ======================


#define LPSYS_FRAMEBUFFER_START_ADDR  (LPSYS_RAM_END+1)

// Size
#define LCPU_ROM_CODE_SIZE               (LPSYS_ROM_SIZE)
#define LCPU_RAM_CODE_SIZE               (250 * 1024)
#define LCPU_MBOX_SIZE                   (LPSYS_MBOX_BUF_SIZE)
#define LCPU_ROM_RAM_SIZE                (64 * 1024)
#define LCPU_PATCH_TOTAL_SIZE            (16 * 1024)
#define LCPU_PATCH_RECORD_SIZE           (256)
#define LCPU_RAM_DATA_SIZE               (LPSYS_RAM_SIZE - LCPU_MBOX_SIZE - LCPU_RAM_CODE_SIZE)
#define LCPU_FLASH_CODE_SIZE             (512*1024)

// Address in C-Bus
#define LCPU_ROM_CODE_START_ADDR     (LPSYS_ROM_BASE)
#define LCPU_RAM_CODE_START_ADDR     (LPSYS_RAM_CBUS_BASE)
#define LCPU_RAM_CODE_END_ADDR       (END_ADDR(LCPU_RAM_CODE_START_ADDR, LCPU_RAM_CODE_SIZE))
//#define LCPU_ROM_RAM_START_ADDR      (LPSYS_RAM_END + 1)
#define LCPU_ROM_RAM_START_ADDR      (LPSYS_ROM_RAM_BASE)
#define LCPU_ROM_RAM_END_ADDR        (END_ADDR(LCPU_ROM_RAM_START_ADDR + LCPU_ROM_RAM_SIZE))
#define LCPU_PATCH_START_ADDR        (LPSYS_PATCH_BASE-0x20000000)
#define LCPU_PATCH_START_ADDR_S      (LPSYS_PATCH_BASE)
#define LCPU_PATCH_END_ADDR          (END_ADDR(LCPU_PATCH_START_ADDR, LCPU_PATCH_TOTAL_SIZE))

//Address in S-Bus
#define LCPU_RAM_CODE_START_ADDR_S   (LPSYS_RAM_BASE)
#define LCPU_RAM_DATA_START_ADDR     (LCPU_RAM_CODE_START_ADDR_S + LCPU_RAM_CODE_SIZE)
#define LCPU_RAM_DATA_END_ADDR       (END_ADDR(LCPU_RAM_DATA_START_ADDR, LCPU_RAM_DATA_SIZE))
#define LCPU_PATCH_RECORD_ADDR       (LCPU_PATCH_START_ADDR_S+LCPU_PATCH_TOTAL_SIZE-LCPU_PATCH_RECORD_SIZE)

#define LCPU_FLASH_CODE_START_ADDR      (FLASH_BOOT_LOADER_END_ADDR + 1)  /* 0x12000000 */
#define LCPU_FLASH_CODE_END_ADDR        (END_ADDR(LCPU_FLASH_CODE_START_ADDR, LCPU_FLASH_CODE_SIZE))  /* 0x12040000 */


#define FLASH_PART_NAME(id)       FLASH_PART##id##_NAME
#define FLASH_PART_DEVICE(id)     FLASH_PART##id##_DEVICE
#define FLASH_PART_BASE_ADDR(id)  FLASH_PART##id##_BASE_ADDR
#define FLASH_PART_OFFSET(id)     FLASH_PART##id##_OFFSET
#define FLASH_PART_SIZE(id)       FLASH_PART##id##_SIZE


#if (LCPU2BCPU_MB_CH1_BUF_END_ADDR - LPSYS_RAM_BASE) >= LPSYS_RAM_SIZE
    #error "LCPU RAM overflow"
#endif

#ifdef LCPU_CONFIG_V2

    /* lpsys_rom */
    #undef  LPSYS_ROM_START_ADDR
    #ifdef LCPU_RUN_SEPERATE_IMG
        #define LPSYS_ROM_START_ADDR                               (0x003FC000)
    #else
        #define LPSYS_ROM_START_ADDR                               (0x00000000)
    #endif
    #undef  LPSYS_ROM_SIZE
    #define LPSYS_ROM_SIZE                                     (0x00080000)
    #undef  LPSYS_ROM_OFFSET
    #define LPSYS_ROM_OFFSET                                   (0x00000000)

    /* lpsys_rom_ram */
    #undef  LCPU_ROM_RAM_START_ADDR
    #define LCPU_ROM_RAM_START_ADDR                            (0x204E0000)
    #undef  LCPU_ROM_RAM_SIZE
    #define LCPU_ROM_RAM_SIZE                                  (0x00003E00)
    #undef  LCPU_ROM_RAM_OFFSET
    #define LCPU_ROM_RAM_OFFSET                                (0x000E0000)
    #undef  LCPU_ROM_CONFIG_START_ADDR
    #define LCPU_ROM_CONFIG_START_ADDR                         (0x204E3E00)
    #undef  LCPU_ROM_CONFIG_SIZE
    #define LCPU_ROM_CONFIG_SIZE                               (0x00000200)
    #undef  LCPU_ROM_CONFIG_OFFSET
    #define LCPU_ROM_CONFIG_OFFSET                             (0x000E3E00)
    #undef  LCPU2HCPU_MB_CH1_BUF_START_ADDR
    #define LCPU2HCPU_MB_CH1_BUF_START_ADDR                    (0x204E4000)
    #undef  LCPU2HCPU_MB_CH1_BUF_SIZE
    #define LCPU2HCPU_MB_CH1_BUF_SIZE                          (0x00000200)
    #undef  LCPU2HCPU_MB_CH1_BUF_OFFSET
    #define LCPU2HCPU_MB_CH1_BUF_OFFSET                        (0x000E4000)
    #undef  NVDS_BUF_START_ADDR
    #define NVDS_BUF_START_ADDR                                (0x204E4200)
    #undef  NVDS_BUF_SIZE
    #define NVDS_BUF_SIZE                                      (0x00000200)
    #undef  NVDS_BUF_OFFSET
    #define NVDS_BUF_OFFSET                                    (0x000E4200)
    #undef  KE_LOG_BUF_START_ADDR
    #define KE_LOG_BUF_START_ADDR                              (0x204E4400)
    #undef  KE_LOG_BUF_SIZE
    #define KE_LOG_BUF_SIZE                                    (0x00000C00)
    #undef  KE_LOG_BUF_OFFSET
    #define KE_LOG_BUF_OFFSET                                  (0x000E4400)
    #undef  KE_ENV_BUF_START_ADDR
    #define KE_ENV_BUF_START_ADDR                              (0x204E5000)
    #undef  KE_ENV_BUF_SIZE
    #define KE_ENV_BUF_SIZE                                    (0x00003800)
    #undef  KE_ENV_BUF_OFFSET
    #define KE_ENV_BUF_OFFSET                                  (0x000E5000)
    #undef  KE_MSG_BUF_START_ADDR
    #define KE_MSG_BUF_START_ADDR                              (0x204E8800)
    #undef  KE_MSG_BUF_SIZE
    #define KE_MSG_BUF_SIZE                                    (0x00003800)
    #undef  KE_MSG_BUF_OFFSET
    #define KE_MSG_BUF_OFFSET                                  (0x000E8800)
    #undef  LCPU_PATCH_BUF_START_ADDR
    #define LCPU_PATCH_BUF_START_ADDR                          (0x204EC000)
    #undef  LCPU_PATCH_BUF_SIZE
    #define LCPU_PATCH_BUF_SIZE                                (0x00004000)
    #undef  LCPU_PATCH_BUF_OFFSET
    #define LCPU_PATCH_BUF_OFFSET                              (0x000EC000)
    #undef  EM_BUF_START_ADDR
    #define EM_BUF_START_ADDR                                  (0x204F0000)
    #undef  EM_BUF_SIZE
    #define EM_BUF_SIZE                                        (0x0000F000)
    #undef  EM_BUF_OFFSET
    #define EM_BUF_OFFSET                                      (0x000F0000)

    #undef  LCPU2HCPU_MB_CH2_BUF_START_ADDR
    #define LCPU2HCPU_MB_CH2_BUF_START_ADDR                    (0x204FEE00)
    #undef  LCPU2HCPU_MB_CH2_BUF_SIZE
    #define LCPU2HCPU_MB_CH2_BUF_SIZE                          (0x00000200)
    #undef  LCPU2HCPU_MB_CH2_BUF_OFFSET
    #define LCPU2HCPU_MB_CH2_BUF_OFFSET                        (0x000FEE00)

    #undef  LCPU_AUDIO_MEM_START_ADDR
    #define LCPU_AUDIO_MEM_START_ADDR                          (0x204FF000)
    #undef  LCPU_AUDIO_MEM_SIZE
    #define LCPU_AUDIO_MEM_SIZE                                (0x00000400)
    #undef  LCPU_AUDIO_MEM_OFFSET
    #define LCPU_AUDIO_MEM_OFFSET                              (0x000FF000)

    /* lpsys_ram */
    #undef  LPSYS_RAM_START_ADDR
    #define LPSYS_RAM_START_ADDR                               (0x20400000)
    #undef  LPSYS_RAM_SIZE
    #define LPSYS_RAM_SIZE                                     (0x00080000)
    #undef  LPSYS_RAM_OFFSET
    #define LPSYS_RAM_OFFSET                                   (0x00000000)

#endif

//======================================= Customize =======================================
#ifdef CUSTOM_MEM_MAP
    #ifdef SOLUTION_WATCH
        #include "flash_map.h"
    #else
        #include "custom_mem_map.h"
    #endif
#endif /* CUSTOM_MEM_MAP */


//TODO
#define FLASH_START             FLASH_TABLE_START_ADDR


/**
    @brief  Factory configuration saved on flash
*/
#define SYSCFG_FACTORY_ADDRESS  (FLASH_TABLE_START_ADDR + 0xE000)
#define AUTO_FLASH_MAC_ADDRESS  (FLASH_TABLE_START_ADDR + 0xE000)
#define SYSCFG_FACTORY_SIZE     0x2000      /*!< Max configuration size*/


#endif  /* __MEM_MAP__ */