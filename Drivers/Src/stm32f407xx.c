/*
 * stm32f407xx.c
 *
 *  Created on: Jan 18, 2024
 *      Author: TeensyDev
 */

#include "stm32f407xx.h"
#include "stm32f407xx_gpio_driver.h"

#define IRQ_Cons(i)	(6+i)

uint8_t returnGPIO_IRQNum(uint8_t PinNo)
{
	if(PinNo<=10)
		return IRQ_Cons(PinNo);
	else if(PinNo<=23)
		return IRQNo_EXTI5_9;
	else if(PinNo<=40)
		return IRQNo_EXTI10_15;
	return -1;
}

