/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-06-30     18452       the first version
 */
#include "ft6336u_iic_driver.h"



/* 软件iic配置参数结构体 */
typedef struct {
    char        i2c_name[16];
    uint8_t     i2c_addr;
    uint8_t     i2c_read_flag;
    uint8_t     i2c_write_flag;
    uint8_t     i2c_wl_reg;
    rt_bool_t   initialized;
    struct rt_i2c_bus_device    *i2c_bus;
}iicStructure_t;


static iicStructure_t   tm601_iic = {
        .i2c_name       = "i2c1",     /* 设备结点 */
        .i2c_addr       = 0x40,       /* ft6336u的iic地址 */
        .i2c_write_flag = 0x80,       /* ft6336u的写标志   */
        .i2c_read_flag  = 0x81,       /* ft6336u的读标志   */
        .i2c_wl_reg     = 0x00,       /* 液位高度寄存器  */
        .initialized    = RT_FALSE,   /* 初始化状态 */
};



/**
 * @brief   ft6336u向寄存器中写入一个字节的数据
 * @param  *bus     : 设备结点
 *         *i2c_reg : 寄存器地址
 * @return
 */
rt_err_t iic_ft6336u_write_reg(struct rt_i2c_bus_device *bus,rt_uint8_t* i2c_reg)
{
    /* 定义IIC消息结构体 */
    struct rt_i2c_msg   ft6336u_msg;
    rt_uint8_t *SendDat;
    SendDat = i2c_reg;

    ft6336u_msg.addr  = ft6336u_iic.i2c_addr;
    ft6336u_msg.flags = RT_I2C_WR;
    ft6336u_msg.buf   = SendDat;
    ft6336u_msg.len   = 1;

    if(rt_i2c_transfer(bus, &ft6336u_msg, 1) == 1){
        return RT_EOK;
    }
    else {
        return RT_ERROR;
    }
}




/**
 * @brief   tm601读取数据
 * @param  *bus     : iic设备句柄
 *          len     : 要读取的数据长度
 *          i2c_dat : 读取数据存入的数组
 * @return
 */
rt_err_t iic_ft6336u_read_reg(struct rt_i2c_bus_device *bus, rt_uint8_t len,rt_uint8_t* i2c_dat)
{
    struct  rt_i2c_msg  ft6336u_msg;

    ft6336u_msg.addr  = ft6336u_iic.i2c_addr;
    ft6336u_msg.flags = RT_I2C_RD;
    ft6336u_msg.buf   = i2c_dat;
    ft6336u_msg.len   = len;

    /* 调用I2C设备接口传输数据 */
    if(rt_i2c_transfer(bus, &ft6336u_msg, 1) == 1){
        return RT_EOK;
    }
    else {
        return RT_ERROR;
    }
}


