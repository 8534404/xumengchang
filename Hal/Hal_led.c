/**
********************************************************
*
* @file      Hal_led.c
* @author    Gizwtis
* @version   V2.3
* @date      2015-07-06
*
* @brief     机智云 只为智能硬件而生
*            Gizwits Smart Cloud  for Smart Products
*            链接|增值|开放|中立|安全|自有|自由|生态
*            www.gizwits.com
*
*********************************************************/
#include "Hal_led.h"


void LED_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct;

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8|GPIO_PIN_9, GPIO_PIN_RESET);

  /*Configure GPIO pins : PB6 PB7 PB8 PB9 */
  GPIO_InitStruct.Pin = GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_12;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);


    LED_OFF(LED1);
    LED_OFF(LED2);
}

void LED_ON(uint8_t LEDNUM)
{
    switch (LEDNUM)
    {
    case LED1:
        
				HAL_GPIO_WritePin(GPIO_LED1_PORT, GPIO_LED1_PIN, GPIO_PIN_SET);
        break;
    case LED2:
        HAL_GPIO_WritePin(GPIO_LED2_PORT, GPIO_LED2_PIN, GPIO_PIN_SET);
        break;
    case LED3:
        HAL_GPIO_WritePin(GPIO_LED3_PORT, GPIO_LED3_PIN, GPIO_PIN_SET);
        break;
    case LED4:
        HAL_GPIO_WritePin(GPIO_LED4_PORT, GPIO_LED4_PIN, GPIO_PIN_SET);
        break;
    default:
        break;
    }
}

void LED_OFF(uint8_t LEDNUM)
{
    switch (LEDNUM)
    {
    case LED1:
        
				HAL_GPIO_WritePin(GPIO_LED1_PORT, GPIO_LED1_PIN, GPIO_PIN_RESET);
        break;
    case LED2:
        HAL_GPIO_WritePin(GPIO_LED2_PORT, GPIO_LED2_PIN, GPIO_PIN_RESET);
        break;
    case LED3:
        HAL_GPIO_WritePin(GPIO_LED3_PORT, GPIO_LED3_PIN, GPIO_PIN_RESET);
        break;
    case LED4:
        HAL_GPIO_WritePin(GPIO_LED4_PORT, GPIO_LED4_PIN, GPIO_PIN_RESET);
        break;
    default:
        break;
    }
}
