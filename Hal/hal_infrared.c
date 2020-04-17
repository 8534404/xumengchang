/**
********************************************************
*
* @file      Hal_infrared.c
* @author    Gizwtis
* @version   V03010100
* @date      2016-07-05
*
* @brief     机智云.只为智能硬件而生
*            Gizwits Smart Cloud  for Smart Products
*            链接|增值ֵ|开放|中立|安全|自有|自由|生态
*            www.gizwits.com
*
*********************************************************/

#include "stm32f1xx_hal.h"
#include "hal_infrared.h"
#include <math.h>

void infraredInit(void)
{
		/*Configure GPIO pins : Infrared_GPIO */
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.Pin =  Infrared_GPIO_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(Infrared_GPIO_PORT, &GPIO_InitStruct);
}

bool infraredHandle(void)
{
    if(HAL_GPIO_ReadPin(Infrared_GPIO_Port, Infrared_Pin))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
