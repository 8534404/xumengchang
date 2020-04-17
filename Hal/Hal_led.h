#ifndef _HAL_LED_H
#define _HAL_LED_H

#include <stdio.h>
#include <stdint.h>
#include <stm32f1xx.h>

#define GPIO_LED1_CLK    RCC_APB2Periph_GPIOB
#define GPIO_LED1_PORT   GPIOB
#define GPIO_LED1_PIN    GPIO_PIN_9

#define GPIO_LED2_CLK    RCC_APB2Periph_GPIOB
#define GPIO_LED2_PORT   GPIOB
#define GPIO_LED2_PIN    GPIO_PIN_8

#define GPIO_LED3_CLK    RCC_APB2Periph_GPIOB
#define GPIO_LED3_PORT   GPIOB
#define GPIO_LED3_PIN    GPIO_PIN_7

#define GPIO_LED4_CLK    RCC_APB2Periph_GPIOB
#define GPIO_LED4_PORT   GPIOB
#define GPIO_LED4_PIN    GPIO_PIN_12
#define GPIO_LED4_RUN    HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_12);   //È¡·´



#define LED1             0X01
#define LED2             0X02
#define LED3             0X04
#define LED4             0X08


void LED_GPIO_Init(void);
void LED_ON(uint8_t LEDNUM);
void LED_OFF(uint8_t LEDNUM);

#endif /*_HAL_LED_H*/

