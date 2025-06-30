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
void FT6336U_READ_INFO(FT6336U_IC_INFO *info)
{
    rt_uint8_t info_buf[3] = { 0 };
    rt_uint8_t libv_buf[2] = { 0 };
    rt_uint8_t frame_version = 0;
    rt_uint8_t vendor_id = 0;

    //--------------------------------------------------------------
    iic_ft6336u_write_reg(ft6336u_iic.i2c_bus, ID_G_CIPHER_HIGH);
    iic_ft6336u_read_reg(ft6336u_iic.i2c_bus, 1, &info_buf[0]);

    iic_ft6336u_write_reg(ft6336u_iic.i2c_bus, ID_G_CIPHER_MIDE);
    iic_ft6336u_read_reg(ft6336u_iic.i2c_bus, 1, &info_buf[1]);

    iic_ft6336u_write_reg(ft6336u_iic.i2c_bus, ID_G_CIPHER_LOW);
    iic_ft6336u_read_reg(ft6336u_iic.i2c_bus, 1, &info_buf[2]);

    info->CPIPHER_INFO = (info_buf[0] << 16) + (info_buf[1] << 8) + info_buf[2];
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

    //--------------------------------------------------------------
    iic_ft6336u_write_reg(ft6336u_iic.i2c_bus, ID_G_LIB_VERSION_H);
    iic_ft6336u_read_reg(ft6336u_iic.i2c_bus, 1, &libv_buf[0]);

    iic_ft6336u_write_reg(ft6336u_iic.i2c_bus, ID_G_LIB_VERSION_L);
    iic_ft6336u_read_reg(ft6336u_iic.i2c_bus, 1, &libv_buf[1]);

    info->LIB_VERSION = (libv_buf[0] << 8) + libv_buf[1];
    rt_kprintf("PRINTF:%d. Touch Chip library file version is %d \r\n",Record.kprintf_cnt++,info->LIB_VERSION);

    //--------------------------------------------------------------
    iic_ft6336u_write_reg(ft6336u_iic.i2c_bus, ID_G_FIRMID);
    iic_ft6336u_read_reg(ft6336u_iic.i2c_bus, 1, &frame_version);
    info->FIRMWARE_VERSION = frame_version;
    rt_kprintf("PRINTF:%d. Touch Chip frameware version is %d \r\n",Record.kprintf_cnt++,info->FIRMWARE_VERSION);

    //--------------------------------------------------------------
    iic_ft6336u_write_reg(ft6336u_iic.i2c_bus, ID_G_FOCALTECH_ID);
    iic_ft6336u_read_reg(ft6336u_iic.i2c_bus, 1, &vendor_id);
    info->VENDOR_ID = vendor_id;
    rt_kprintf("PRINTF:%d. Touch Chip vendor_id is %d \r\n",Record.kprintf_cnt++,info->VENDOR_ID);
}


/**
 * @brief  近距离感应使能
 * @param  void
 * @return NULL
 */
void FT6336U_IN_Plant_Enable(uint8_t enable){
    iic_ft6336u_write_reg(ft6336u_iic.i2c_bus, ID_G_FACE_DEC_MODE);
    IIC_Write_One_Byte(FT6336U_Slave_Addr,ID_G_FACE_DEC_MODE,enable);
}




