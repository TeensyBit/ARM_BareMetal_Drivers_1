/*
 * stm32f407xx_gpio_driver.c
 *
 *  Created on: Jan 15, 2024
 *      Author: TeensyDev
 */

#include "stm32f407xx_gpio_driver.h"


//	API Implementation
/*
 * 	@function				: GPIO_PCLK_Ctrl
 * 	@info					: Peripheral Clock Control
 *
 * 	@param[in]_datatypes	: GPIO_RegDef_t, uint8_t
 * 	@param[in] variables	: GPIO_RegDef_t *pGPIOx, uint8_t EN_DI
 *
 * 	@return					: void
 *
 * 	@notes					: API for enabling and disabling the clock
 */

void GPIO_PCLK_Ctrl(GPIOx_RegDef_t *pGPIOx, uint8_t EN_DI)
{
	if(EN_DI == EN)
	{
		if (pGPIOx == GPIOA) GPIO_PCLK_EN(0);
		else if (pGPIOx == GPIOB) GPIO_PCLK_EN(1);
		else if (pGPIOx == GPIOC) GPIO_PCLK_EN(2);
		else if (pGPIOx == GPIOD) GPIO_PCLK_EN(3);
		else if (pGPIOx == GPIOE) GPIO_PCLK_EN(4);
		else if (pGPIOx == GPIOF) GPIO_PCLK_EN(5);
		else if (pGPIOx == GPIOG) GPIO_PCLK_EN(6);
		else if (pGPIOx == GPIOH) GPIO_PCLK_EN(7);
		else if (pGPIOx == GPIOI) GPIO_PCLK_EN(8);
		else if (pGPIOx == GPIOJ) GPIO_PCLK_EN(9);
		else if (pGPIOx == GPIOK) GPIO_PCLK_EN(10);
	}
	else if(EN_DI == DI)
	{
		if (pGPIOx == GPIOA) GPIO_PCLK_DI(0);
		else if (pGPIOx == GPIOB) GPIO_PCLK_DI(1);
		else if (pGPIOx == GPIOC) GPIO_PCLK_DI(2);
		else if (pGPIOx == GPIOD) GPIO_PCLK_DI(3);
		else if (pGPIOx == GPIOE) GPIO_PCLK_DI(4);
		else if (pGPIOx == GPIOF) GPIO_PCLK_DI(5);
		else if (pGPIOx == GPIOG) GPIO_PCLK_DI(6);
		else if (pGPIOx == GPIOH) GPIO_PCLK_DI(7);
		else if (pGPIOx == GPIOI) GPIO_PCLK_DI(8);
		else if (pGPIOx == GPIOJ) GPIO_PCLK_DI(9);
		else if (pGPIOx == GPIOK) GPIO_PCLK_DI(10);
	}
}

//	API Implementation
/*
 * 	@function				: GPIO_Init
 * 	@info					: Configure the GPIO as required
 *
 * 	@param[in]_datatypes	: GPIOx_Handler_t*
 * 	@param[in] variables	: GPIOx_Handler_t* pGPIOx_Handle
 *
 * 	@return					: void
 *
 * 	@notes					: API configuring the GPIO Pins
 */

void GPIO_Init(GPIOx_Handler_t* pGPIOx_Handle)
{
	GPIO_PinConfig_t *temp =  &(pGPIOx_Handle->GPIO_PinConfig);
	//Setting PinMode - Input/Output/AlternateFunc/Analog
	pGPIOx_Handle->pGPIOx->GPIOx_MODER &= ~(0x3<<(2*(temp->GPIO_PinNo)));					//Clear corresponding bits in the MODER Register
	pGPIOx_Handle->pGPIOx->GPIOx_MODER |= (temp->GPIO_PinMode<<(2*(temp->GPIO_PinNo)));		//Set the corresponding bits in the MODER Register

	//PinMode Output type - Output Push-Pull/Output Open-Drain
	pGPIOx_Handle->pGPIOx->GPIOx_OTYPER &= ~(0x1<<(temp->GPIO_PinNo));
	pGPIOx_Handle->pGPIOx->GPIOx_OTYPER |= ((temp->GPIO_PinModeOType)<<(temp->GPIO_PinNo));

	//PinMode Output Speed - LOW/MEDIUM/HIGH/VERY HIGH
	pGPIOx_Handle->pGPIOx->GPIOx_OSPEEDR &= ~(0x3<<(2*(temp->GPIO_PinNo)));
	pGPIOx_Handle->pGPIOx->GPIOx_OSPEEDR |= ((temp->GPIO_PinOSpeed)<<(2*(temp->GPIO_PinNo)));

	//PinMode Pull-Up/Down - No Pull-Up/Pull-Up/Pull-Down
	pGPIOx_Handle->pGPIOx->GPIOx_PUPDR &= ~(0x3<<(2*(temp->GPIO_PinNo)));
	pGPIOx_Handle->pGPIOx->GPIOx_PUPDR |= ((temp->GPIO_PinPUPD)<<(2*(temp->GPIO_PinNo)));

	//PinMode Alternate Function - AF0_15
	uint8_t L_H = (temp->GPIO_PinNo)/8;
	pGPIOx_Handle->pGPIOx->GPIOx_AFR[L_H] &= ~(0xF<<(4*(temp->GPIO_PinNo)));
	pGPIOx_Handle->pGPIOx->GPIOx_AFR[L_H] &= ~(((temp->GPIO_PinAF)%8)<<(4*(temp->GPIO_PinNo)));
}

//	API Implementation
/*
 * 	@function				: GPIO_DeInit
 * 	@info					: De-Initialize GPIO
 *
 * 	@param[in]_datatypes	: GPIO_RegDef_t*
 * 	@param[in] variables	: GPIO_RegDef_t *pGPIOx
 *
 * 	@return					: void
 *
 * 	@notes					: API for enabling and disabling the clock
 */

void GPIO_DeInit(GPIOx_RegDef_t* pGPIOx)
{
	if (pGPIOx == GPIOA) GPIO_RST(0);
	else if (pGPIOx == GPIOB) GPIO_RST(1);
	else if (pGPIOx == GPIOC) GPIO_RST(2);
	else if (pGPIOx == GPIOD) GPIO_RST(3);
	else if (pGPIOx == GPIOE) GPIO_RST(4);
	else if (pGPIOx == GPIOF) GPIO_RST(5);
	else if (pGPIOx == GPIOG) GPIO_RST(6);
	else if (pGPIOx == GPIOH) GPIO_RST(7);
	else if (pGPIOx == GPIOI) GPIO_RST(8);
}
