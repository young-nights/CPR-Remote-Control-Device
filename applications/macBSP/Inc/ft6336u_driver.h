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
extern FT6336U_IC_INFO ft6336u_info;


//-----------寄存器定义------------------
typedef struct
{
    uint8_t  ID_G_CIPHER_HIGH;
    uint8_t  ID_G_CIPHER_MIDE;
    uint8_t  ID_G_CIPHER_LOW;
    uint8_t  ID_G_LIB_VERSION_H;
    uint8_t  ID_G_LIB_VERSION_L;
    uint8_t  ID_G_FIRMID;
    uint8_t  ID_G_FOCALTECH_ID;
    uint8_t  ID_G_FACE_DEC_MODE;
}FT6336U_IC_REG;
extern FT6336U_IC_REG ft6336u_reg;





//-----------函数声明------------------
void FT6336U_RESET(void);
void FT6336U_READ_INFO(struct rt_i2c_bus_device *bus,FT6336U_IC_INFO *info);


#endif /* APPLICATIONS_MACBSP_INC_FT6336U_DRIVER_H_ */
