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
		if (pGPIOx == GPIOA) GPIOA_PCLK_EN();
		else if (pGPIOx == GPIOB) GPIOB_PCLK_EN();
		else if (pGPIOx == GPIOC) GPIOC_PCLK_EN();
		else if (pGPIOx == GPIOD) GPIOD_PCLK_EN();
		else if (pGPIOx == GPIOE) GPIOE_PCLK_EN();
		else if (pGPIOx == GPIOF) GPIOF_PCLK_EN();
		else if (pGPIOx == GPIOG) GPIOG_PCLK_EN();
		else if (pGPIOx == GPIOH) GPIOH_PCLK_EN();
		else if (pGPIOx == GPIOI) GPIOI_PCLK_EN();
		else if (pGPIOx == GPIOJ) GPIOJ_PCLK_EN();
		else if (pGPIOx == GPIOK) GPIOK_PCLK_EN();
	}
	else if(EN_DI == DI)
	{
		if (pGPIOx == GPIOA) GPIOA_PCLK_DI();
		else if (pGPIOx == GPIOB) GPIOB_PCLK_DI();
		else if (pGPIOx == GPIOC) GPIOC_PCLK_DI();
		else if (pGPIOx == GPIOD) GPIOD_PCLK_DI();
		else if (pGPIOx == GPIOE) GPIOE_PCLK_DI();
		else if (pGPIOx == GPIOF) GPIOF_PCLK_DI();
		else if (pGPIOx == GPIOG) GPIOG_PCLK_DI();
		else if (pGPIOx == GPIOH) GPIOH_PCLK_DI();
		else if (pGPIOx == GPIOI) GPIOI_PCLK_DI();
		else if (pGPIOx == GPIOJ) GPIOJ_PCLK_DI();
		else if (pGPIOx == GPIOK) GPIOK_PCLK_DI();
	}
}

//	API Implementation
/*
 * 	@function				: GPIO_Init
 * 	@info					: Peripheral Clock Control
 *
 * 	@param[in]_datatypes	: GPIO_RegDef_t, uint8_t
 * 	@param[in] variables	: GPIO_RegDef_t *pGPIOx, uint8_t EN_DI
 *
 * 	@return					: void
 *
 * 	@notes					: API for enabling and disabling the clock
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

	//PinMode Alternate Function - AF0
	uint8_t L_H = (temp->GPIO_PinNo)/8;
	pGPIOx_Handle->pGPIOx->GPIOx_AFR[L_H] &= ~(0xF<<(4*(temp->GPIO_PinNo)));
	pGPIOx_Handle->pGPIOx->GPIOx_AFR[L_H] &= ~(((temp->GPIO_PinNo)%8)<<(4*(temp->GPIO_PinNo)));
}
