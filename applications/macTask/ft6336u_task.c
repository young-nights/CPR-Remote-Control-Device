/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-07-01     Administrator       the first version
 */
#include "bsp_sys.h"



/**
  * @brief  This thread entry is used for touch check
  * @retval void
  */
void FT6336U_Thread_entry(void* parameter)
{


    FT6336U_RESET();
    ft6336u_device_init();
    FT6336U_READ_INFO(ft6336u_iic.i2c_bus, &ft6336u_info);

    for(;;)
    {

        rt_thread_mdelay(10);
    }


}



/**
  * @brief  This is a Initialization for water level Check
  * @retval int
  */
int FT6336U_Thread_Init(void)
{
    rt_thread_t FT6336U_Task_Handle = RT_NULL;
    /* 创建检查一些系统状态标志的线程  -- 优先级：25 */
    FT6336U_Task_Handle = rt_thread_create("FT6336U_Thread_entry", FT6336U_Thread_entry, RT_NULL, 512, 25, 300);
    /* 检查是否创建成功,成功就启动线程 */
    if(FT6336U_Task_Handle != RT_NULL)
    {
        rt_kprintf("PRINTF:%d. FT6336U_Thread_entry is Succeed!! \r\n",Record.kprintf_cnt++);
        rt_thread_startup(FT6336U_Task_Handle);
    }
    else {
        rt_kprintf("PRINTF:%d. FT6336U_Thread_entry is Failed \r\n",Record.kprintf_cnt++);
    }

    return RT_EOK;
}
INIT_APP_EXPORT(FT6336U_Thread_Init);







