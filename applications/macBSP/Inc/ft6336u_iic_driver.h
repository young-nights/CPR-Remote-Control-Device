/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-06-30     18452       the first version
 */
#ifndef APPLICATIONS_MACBSP_INC_FT6336U_IIC_DRIVER_H_
#define APPLICATIONS_MACBSP_INC_FT6336U_IIC_DRIVER_H_

#include "bsp_sys.h"

/* 复位引脚 -- RST */
#define     TOUCH_RST_PORT       TOUCH_RST_GPIO_Port
#define     TOUCH_RST_PIN        TOUCH_RST_Pin

#define     TOUCH_RST_SET(bit)   if(bit) \
                                 HAL_GPIO_WritePin ( TOUCH_RST_PORT, TOUCH_RST_PIN , GPIO_PIN_SET );\
                                 else \
                                 HAL_GPIO_WritePin ( TOUCH_RST_PORT, TOUCH_RST_PIN , GPIO_PIN_RESET );




#endif /* APPLICATIONS_MACBSP_INC_FT6336U_IIC_DRIVER_H_ */
