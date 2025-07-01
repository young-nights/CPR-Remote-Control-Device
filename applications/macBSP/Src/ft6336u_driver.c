/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-06-30     18452       the first version
 */
#include "ft6336u_driver.h"



FT6336U_IC_REG ft6336u_reg = {
        .ID_G_CIPHER_HIGH       = 0xA3, //芯片代号高字节
        .ID_G_CIPHER_MIDE       = 0x9F, //芯片代号中字节
        .ID_G_CIPHER_LOW        = 0xA0, //芯片代号低字节
        .ID_G_LIB_VERSION_H     = 0xA1, //APP库文件版本高字节
        .ID_G_LIB_VERSION_L     = 0xA2, //APP库文件版本低字节
        .ID_G_FIRMID            = 0xA6, //固件版本
        .ID_G_FOCALTECH_ID      = 0xA8, //VENDOR ID
        .ID_G_FACE_DEC_MODE     = 0xB0, //近距离感应使能
};


/**
 * @brief  ft6336u芯片复位函数
 * @param  void
 * @return NULL
 */
void FT6336U_RESET(void)
{
    TOUCH_RST_SET(0);
    rt_thread_mdelay(120);
    TOUCH_RST_SET(1);
}





/**
 * @brief  读取ft6336u芯片的内置信息
 * @param  void
 * @return NULL
 */
FT6336U_IC_INFO ft6336u_info;
void FT6336U_READ_INFO(struct rt_i2c_bus_device *bus,FT6336U_IC_INFO *info)
{

    rt_uint8_t info_buf[3] = { 0 };
    rt_uint8_t libv_buf[2] = { 0 };
    rt_uint8_t frame_version = 0;
    rt_uint8_t vendor_id = 0;

    //--------------------------------------------------------------
    /* 根据数据手册，进行读操作时，按照 “从机地址 + 发送标志 + 寄存器地址 ”进行第一次发送  */
    iic_ft6336u_write_reg(bus, &ft6336u_reg.ID_G_CIPHER_HIGH);
    iic_ft6336u_read_reg(bus, 1, &info_buf[0]);

    iic_ft6336u_write_reg(bus, &ft6336u_reg.ID_G_CIPHER_MIDE);
    iic_ft6336u_read_reg(bus, 1, &info_buf[1]);

    iic_ft6336u_write_reg(bus, &ft6336u_reg.ID_G_CIPHER_LOW);
    iic_ft6336u_read_reg(bus, 1, &info_buf[2]);

    info->CPIPHER_INFO = (info_buf[0] << 16) + (info_buf[1] << 8) + info_buf[2];
    rt_kprintf("PRINTF:%d. info->CPIPHER_INFO == %x \r\n",Record.kprintf_cnt++,info->CPIPHER_INFO);
    if(info->CPIPHER_INFO == 0xFFFF00){
        rt_kprintf("PRINTF:%d. This Touch Chip Type is FT6236G \r\n",Record.kprintf_cnt++);
    }
    else if(info->CPIPHER_INFO == 0xFFFF01){
        rt_kprintf("PRINTF:%d. This Touch Chip Type is FT6336G \r\n",Record.kprintf_cnt++);
    }
    else if(info->CPIPHER_INFO == 0xFFFF02){
        rt_kprintf("PRINTF:%d. This Touch Chip Type is FT6336U \r\n",Record.kprintf_cnt++);
    }
    else if(info->CPIPHER_INFO == 0xFFFF03){
        rt_kprintf("PRINTF:%d. This Touch Chip Type is FT6426 \r\n",Record.kprintf_cnt++);
    }
    else{
        rt_kprintf("PRINTF:%d. This Touch Chip Type is not found \r\n",Record.kprintf_cnt++);
    }

//    //--------------------------------------------------------------
//    iic_ft6336u_write_reg(bus, ID_G_LIB_VERSION_H);
//    iic_ft6336u_read_reg(bus, 1, &libv_buf[0]);
//
//    iic_ft6336u_write_reg(bus, ID_G_LIB_VERSION_L);
//    iic_ft6336u_read_reg(bus, 1, &libv_buf[1]);
//
//    info->LIB_VERSION = (libv_buf[0] << 8) + libv_buf[1];
//    rt_kprintf("PRINTF:%d. Touch Chip library file version is %d \r\n",Record.kprintf_cnt++,info->LIB_VERSION);
//
//    //--------------------------------------------------------------
//    iic_ft6336u_write_reg(bus, ID_G_FIRMID);
//    iic_ft6336u_read_reg(bus, 1, &frame_version);
//    info->FIRMWARE_VERSION = frame_version;
//    rt_kprintf("PRINTF:%d. Touch Chip frameware version is %d \r\n",Record.kprintf_cnt++,info->FIRMWARE_VERSION);
//
//    //--------------------------------------------------------------
//    iic_ft6336u_write_reg(bus, ID_G_FOCALTECH_ID);
//    iic_ft6336u_read_reg(bus, 1, &vendor_id);
//    info->VENDOR_ID = vendor_id;
//    rt_kprintf("PRINTF:%d. Touch Chip vendor_id is %d \r\n",Record.kprintf_cnt++,info->VENDOR_ID);
}


/**
 * @brief  近距离感应使能
 * @param  void
 * @return NULL
 */



