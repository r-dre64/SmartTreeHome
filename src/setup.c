/*
 * setup.c
 *
 *  Created on: 02.10.2016
 *      Author: Ruven
 */
#include "setup.h";
#include "stm32f746xx.h"
#include "stm32f7xx_hal.h"
#include "stm32746g_discovery.h"
#include "stm32746g_discovery_lcd.h"
#include "stm32746g_discovery_ts.h"

void setup()
{
	setupCache();
	setupClock();
	setupLCD();
	setupTouch();
	setupCycleTimer();

}

void setupClock()
{
	  RCC_ClkInitTypeDef RCC_ClkInitStruct;
	  RCC_OscInitTypeDef RCC_OscInitStruct;
	  HAL_StatusTypeDef ret = HAL_OK;

	  /* Enable HSE Oscillator and activate PLL with HSE as source */
	  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
	  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
	  RCC_OscInitStruct.PLL.PLLM = 25;
	  RCC_OscInitStruct.PLL.PLLN = 400;
	  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
	  RCC_OscInitStruct.PLL.PLLQ = 8;

	  ret = HAL_RCC_OscConfig(&RCC_OscInitStruct);
	  if(ret != HAL_OK)
	  {
	    while(1) { ; }
	  }

	  /* Activate the OverDrive to reach the 200 MHz Frequency */
	  ret = HAL_PWREx_EnableOverDrive();
	  if(ret != HAL_OK)
	  {
	    while(1) { ; }
	  }

	  /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2 clocks dividers */
	  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
	  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
	  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

	  ret = HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_6);
	  if(ret != HAL_OK)
	  {
	    while(1) { ; }
	  }
}

void setupCache()
{
	  /* Enable I-Cache */
	  SCB_EnableICache();

	  /* Enable D-Cache */
	  SCB_EnableDCache();
}

void setupCycleTimer()
{
	__HAL_RCC_TIM10_CLK_ENABLE();
	TIM_HandleTypeDef CycleTimer;
	HAL_TIM_Base_MspInit(&CycleTimer);
	CycleTimer.Channel = TIM_CHANNEL_1;
	CycleTimer.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	CycleTimer.Init.CounterMode = TIM_COUNTERMODE_UP;
	CycleTimer.Init.Period = 2000;
	CycleTimer.Init.Prescaler = 2000;
	CycleTimer.Init.RepetitionCounter= 0xFFFF;
	CycleTimer.Instance = TIM10;
	CycleTimer.State = ENABLE;
	HAL_TIM_Base_Init(&CycleTimer);


	HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_0);
	HAL_NVIC_SetPriority(TIM1_UP_TIM10_IRQn,0,0);
	HAL_NVIC_EnableIRQ(TIM1_UP_TIM10_IRQn);
	HAL_TIM_Base_Start_IT(&CycleTimer);
}

void setupLCD()
{
	  /* LCD Initialization */
	  BSP_LCD_Init();

	  BSP_LCD_SetFont(&Font8);

	  /* LCD Initialization */
	  BSP_LCD_LayerDefaultInit(0, LCD_FB_START_ADDRESS);

	  /* Enable the LCD */
	  BSP_LCD_DisplayOn();

	  /* Select the LCD Background Layer  */
	  BSP_LCD_SelectLayer(0);

	  /* Clear the Background Layer */
	  BSP_LCD_Clear(LCD_COLOR_WHITE);

	  /* Configure the transparency for background */
	  BSP_LCD_SetTransparency(0, 255);
}

void setupTouch()
{

	TS_StateTypeDef State;
	BSP_TS_Init((uint16_t)BSP_LCD_GetXSize,(uint16_t)BSP_LCD_GetYSize);


}
