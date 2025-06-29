/*
 * Copyright (c) 2006-2025, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-06-29     RT-Thread    first version
 */

#include <rtthread.h>
#include "bsp_sys.h"

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_SPI1_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */



  //-------BSP板级硬件初始化----------
  LED_Init();

  //-------软件定时器初始化----------
  rt_kprintf("----------------------------------------\r\n");
  sysTimer_Init();
  ledTimer_Init();
  keyTimer_Init();



  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
      LED_Blink(LED_Name_Green, 1, 0, 0);
      rt_thread_delay(500);
    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}
