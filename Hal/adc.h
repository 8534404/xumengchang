#ifndef __ADC_H
#define __ADC_H
#include <stdio.h>
#include <stm32f1xx_hal.h>

//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK STM32F103������
//ADC��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//��������:2017/5/29
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2014-2024
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	

void MY_ADC_Init(void); 				//ADCͨ����ʼ��
uint16_t  Get_Adc(uint32_t ch); 		        //���ĳ��ͨ��ֵ 
uint16_t Get_Adc_Average(uint32_t ch,uint8_t times);//�õ�ĳ��ͨ����������������ƽ��ֵ
#endif 
