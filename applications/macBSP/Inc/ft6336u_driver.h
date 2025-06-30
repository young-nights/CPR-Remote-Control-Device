/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-06-30     18452       the first version
 */
#ifndef APPLICATIONS_MACBSP_INC_FT6336U_DRIVER_H_
#define APPLICATIONS_MACBSP_INC_FT6336U_DRIVER_H_
#include "bsp_sys.h"




//FT6336U芯片相关信息结构液体
typedef struct
{
    unsigned long    CPIPHER_INFO;
    uint16_t    LIB_VERSION;
    uint8_t     FIRMWARE_VERSION;
    uint8_t     VENDOR_ID;
}FT6336U_IC_INFO;



//-----------寄存器定义------------------
#define ID_G_CIPHER_HIGH      0xA3  //芯片代号高字节
#define ID_G_CIPHER_MIDE      0x9F  //芯片代号中字节
#define ID_G_CIPHER_LOW       0xA0  //芯片代号低字节

#define ID_G_LIB_VERSION_H    0xA1  //APP库文件版本高字节
#define ID_G_LIB_VERSION_L    0xA2  //APP库文件版本低字节

#define ID_G_FIRMID           0xA6  //固件版本
#define ID_G_FOCALTECH_ID     0xA8  //VENDOR ID

#define ID_G_FACE_DEC_MODE    0xB0  //近距离感应使能




//-----------函数声明------------------
void FT6336U_RESET(void);



#endif /* APPLICATIONS_MACBSP_INC_FT6336U_DRIVER_H_ */
