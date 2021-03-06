/**
********************************************************
*
* @file      Hal_rgb_led.c
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
#include "hal_rgb_led.h"
#include "delay.h"

void ledDelay(unsigned int ms)
{
    volatile unsigned  int i=0;
    for(i=0; i<ms; i++);
}


/************ generation clock *********************/
void clkProduce(void)
{
    SCL_LOW;        // SCL=0
    delay_us(50);
    SCL_HIGH;       // SCL=1
    delay_us(50);
}

/**********  send 32 zero ********************/
void send32Zero(void)
{
    unsigned char i;
    SDA_LOW;   // SDA=0
    for (i=0; i<32; i++)
    {
        clkProduce();
    }
}

/********* invert the grey value of the first two bits ***************/
uint8_t takeAntiCode(uint8_t dat)
{
    uint8_t tmp = 0;

    tmp=((~dat) & 0xC0)>>6;
    return tmp;
}

/****** send gray data *********/
void datSend(uint32_t dx)
{
    uint8_t i;

    for (i=0; i<32; i++)
    {
        if ((dx & 0x80000000) != 0)
        {

            SDA_HIGH;     //  SDA=1;
        }
        else
        {
            SDA_LOW;    //  SDA=0;
        }

        dx <<= 1;
        clkProduce();	
    }
}

/******* data processing  ********************/
void dataDealWithAndSend(uint8_t r, uint8_t g, uint8_t b)
{
    uint32_t dx = 0;

    dx |= (uint32_t)0x03 << 30;             // The front of the two bits 1 is flag bits
    dx |= (uint32_t)takeAntiCode(b) << 28;
    dx |= (uint32_t)takeAntiCode(g) << 26;
    dx |= (uint32_t)takeAntiCode(r) << 24;

    dx |= (uint32_t)b << 16;
    dx |= (uint32_t)g << 8;
    dx |= r;

    datSend(dx);
}

void rgbLedInit(void)
{
		GPIO_InitTypeDef GPIO_InitStruct;
	
		/*Configure GPIO pin : RGB_LED_EN_Pin */
		GPIO_InitStruct.Pin = RGB_LED_EN_Pin;
		GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
		HAL_GPIO_Init(RGB_LED_EN_GPIO_Port, &GPIO_InitStruct);
	
		/*Configure GPIO pins : RGBLED_CLK_Pin RGBLED_DIN_Pin */
		
		GPIO_InitStruct.Pin = RGBLED_CLK_Pin;
		GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
		HAL_GPIO_Init(RGBLED_CLK_GPIO_Port, &GPIO_InitStruct);

		GPIO_InitStruct.Pin = RGBLED_DIN_Pin;
		GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
		HAL_GPIO_Init(RGBLED_DIN_GPIO_Port, &GPIO_InitStruct);
	
	
    //RGB_Enable();
    send32Zero();
    dataDealWithAndSend(0,0,0);	 
    dataDealWithAndSend(0,0,0);
}

void ledRgbControl(uint8_t r, uint8_t g, uint8_t b)
{
    printf("R:%d, G:%d, B:%d \n", r, g, b);
		//RGB_Enable();
    send32Zero();
    dataDealWithAndSend(r, g, b);
    dataDealWithAndSend(r, g, b);
}




void ledRgbOnOff(uint8_t state)
{
	if(state == 1)
	{
		RGB_Enable();
	}
	else
	{
		RGB_Disable();
	}
}

