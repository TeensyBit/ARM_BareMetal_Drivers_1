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
	if((temp->GPIO_PinMode)<=GPIO_MODE_AN)
	{
		//Setting PinMode - Input/Output/AlternateFunc/Analog
		pGPIOx_Handle->pGPIOx->GPIOx_MODER &= ~(0x3<<(2*(temp->GPIO_PinNo)));					//Clear corresponding bits in the MODER Register
		pGPIOx_Handle->pGPIOx->GPIOx_MODER |= (temp->GPIO_PinMode<<(2*(temp->GPIO_PinNo)));		//Set the corresponding bits in the MODER Register
	}
	else
	{
		/*
		 * To generate the interrupt, the interrupt line should be configured and enabled.
		 * This is done by programming the two trigger registers with the desired edge detection
		 * Enable the interrupt request by writing a ‘1’ to the corresponding bit in the IMR
		 */

		if((temp->GPIO_PinMode)==GPIO_MODE_ITRT)
		{
			(EXTI->EXTI_RTSR) &= ~(1<<(temp->GPIO_PinNo));
			(EXTI->EXTI_RTSR) |= (1<<(temp->GPIO_PinNo));
		}
		else if((temp->GPIO_PinMode)==GPIO_MODE_ITFT)
		{
			(EXTI->EXTI_FTSR) &= ~(1<<(temp->GPIO_PinNo));
			(EXTI->EXTI_FTSR) |= (1<<(temp->GPIO_PinNo));
		}
		else if((temp->GPIO_PinMode)==GPIO_MODE_ITRFT)
		{
			(EXTI->EXTI_RTSR) &= ~(1<<(temp->GPIO_PinNo));
			(EXTI->EXTI_RTSR) |= (1<<(temp->GPIO_PinNo));
			(EXTI->EXTI_FTSR) &= ~(1<<(temp->GPIO_PinNo));
			(EXTI->EXTI_FTSR) |= (1<<(temp->GPIO_PinNo));
		}
		//EXTI_IMR
		EXTI->EXTI_IMR &= ~(1<<(temp->GPIO_PinNo));		//Clear the corresponding IMR bit
		EXTI->EXTI_IMR |= (1<<(temp->GPIO_PinNo));		//Clear the corresponding IMR bit}

		SYSCFG_PCLK_EN();
		*(SYSCFG->SYSCFG_EXTICR+((temp->GPIO_PinNo)/4)) &= ~(PortCode(pGPIOx_Handle->pGPIOx)<<(((temp->GPIO_PinNo)%4)*4));
		*(SYSCFG->SYSCFG_EXTICR+((temp->GPIO_PinNo)/4)) |= (PortCode(pGPIOx_Handle->pGPIOx)<<(((temp->GPIO_PinNo)%4)*4));

		/* Same as writing:
		  SYSCFG->SYSCFG_EXTICR[((temp->GPIO_PinNo)/4)] &= ~(PortCode(pGPIOx_Handle->pGPIOx)<<(((temp->GPIO_PinNo)%4)*4));
		  SYSCFG->SYSCFG_EXTICR[((temp->GPIO_PinNo)/4)] |= (PortCode(pGPIOx_Handle->pGPIOx)<<(((temp->GPIO_PinNo)%4)*4));
		 */
	}
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

uint8_t PortCode(GPIOx_RegDef_t *pGPIOx)
{
	return ((pGPIOx == GPIOA)? 0 : \
	        (pGPIOx == GPIOB)? 1 : \
	        (pGPIOx == GPIOC)? 2 : \
	        (pGPIOx == GPIOD)? 3 : \
	        (pGPIOx == GPIOE)? 4 : \
	        (pGPIOx == GPIOF)? 5 : \
	        (pGPIOx == GPIOG)? 6 : \
	        (pGPIOx == GPIOH)? 7 : \
	        (pGPIOx == GPIOI)? 8 : \
	        (pGPIOx == GPIOJ)? 9 : \
	        (pGPIOx == GPIOK)? 10 : 0);
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
	if(pGPIOx == GPIOA) GPIO_RST(0);
	else if(pGPIOx == GPIOB) GPIO_RST(1);
	else if(pGPIOx == GPIOC) GPIO_RST(2);
	else if(pGPIOx == GPIOD) GPIO_RST(3);
	else if(pGPIOx == GPIOE) GPIO_RST(4);
	else if(pGPIOx == GPIOF) GPIO_RST(5);
	else if(pGPIOx == GPIOG) GPIO_RST(6);
	else if(pGPIOx == GPIOH) GPIO_RST(7);
	else if(pGPIOx == GPIOI) GPIO_RST(8);
}

//	API Implementation
/*
 * 	@function				: GPIO_OPinWrite
 * 	@info					: Write to Output Pin
 *
 * 	@param[in]_datatypes	: GPIO_RegDef_t*, uint8_t, uint8_t
 * 	@param[in] variables	: GPIOx_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value
 *
 * 	@return					: void
 *
 * 	@notes					: API for setting the pins HIGH/LOW
 */

void GPIO_OPinWrite(GPIOx_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t value)
{
	pGPIOx->GPIOx_ODR &= ~(1<<PinNumber);
	pGPIOx->GPIOx_ODR |= (value<<PinNumber);
}

//	API Implementation
/*
 * 	@function				: GPIO_OPortWrite
 * 	@info					: Write to Output Port
 *
 * 	@param[in]_datatypes	: GPIO_RegDef_t*, uint16_t
 * 	@param[in] variables	: GPIOx_RegDef_t *pGPIOx, uint16_t value
 *
 * 	@return					: void
 *
 * 	@notes					: API for setting the pins HIGH/LOW
 */

void GPIO_OPortWrite(GPIOx_RegDef_t *pGPIOx, uint16_t value)
{
	pGPIOx->GPIOx_ODR = value;
}

//	API Implementation
/*
 * 	@function				: GPIO_OPortWrite
 * 	@info					: Write to Output Port
 *
 * 	@param[in]_datatypes	: GPIO_RegDef_t*, uint16_t
 * 	@param[in] variables	: GPIOx_RegDef_t *pGPIOx, uint16_t value
 *
 * 	@return					: void
 *
 * 	@notes					: API for setting the pins HIGH/LOW
 */

void GPIO_ToggleOPin(GPIOx_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	pGPIOx->GPIOx_ODR ^= (1<<PinNumber);
}

//	API Implementation
/*
 * 	@function				: GPIO_IPinRead
 * 	@info					: Read Port pin
 *
 * 	@param[in]_datatypes	: GPIO_RegDef_t*, uint8_t
 * 	@param[in] variables	: GPIOx_RegDef_t *pGPIOx, uint8_t PinNumber
 *
 * 	@return					: void
 *
 * 	@notes					: API for reading the port pin
 */

uint8_t GPIO_IPinRead(GPIOx_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	return (pGPIOx->GPIOx_IDR) & (1<<PinNumber);
}

//	API Implementation
/*
 * 	@function				: GPIO_IPortRead
 * 	@info					: Read Port pin
 *
 * 	@param[in]_datatypes	: GPIO_RegDef_t*
 * 	@param[in] variables	: GPIOx_RegDef_t *pGPIOx
 *
 * 	@return					: void
 *
 * 	@notes					: API for reading the port pin
 */

uint16_t GPIO_IPortRead(GPIOx_RegDef_t *pGPIOx)
{
	return (pGPIOx->GPIOx_IDR);
}

//	API Implementation
/*
 * 	@function				: GPIO_IRQConfig
 * 	@info					: Enable/Disable interrupts on an IRQ number
 *
 * 	@param[in]_datatypes	: uint8_t, uint8_t
 * 	@param[in] variables	: uint8_t IRQ_Number, uint8_t EN_DI
 *
 * 	@return					: void
 *
 * 	@notes					: Enable/Disable Interrupts on an IRQ number by setting ISER/ICER
*/

void GPIO_IRQConfig(uint8_t IRQ_Number, uint8_t EN_DI)
{
	if(EN_DI == EN)
		*(NVIC_ISER(IRQ_Number)) |= (1<<IRQ_Number);
	else if(EN_DI == DI)
		*(NVIC_ICER(IRQ_Number)) |= (1<<IRQ_Number);
}

//	API Implementation
/*
 * 	@function				: GPIO_IRQNum
 * 	@info					: Setting priority for IRQ number
 *
 * 	@param[in]_datatypes	: uint8_t, uint8_t
 * 	@param[in] variables	: uint8_t IRQ_Number, uint8_t EN_DI
 *
 * 	@return					: void
 *
 * 	@notes					: API for setting priority for IRQ number by setting the IPR bits
 */

void GPIO_IRQPriority(uint8_t IRQ_Number, uint8_t IRQ_Priority)
{
	*(NVIC_IPR(IRQ_Number)) = IRQ_Priority<<(((IRQ_Number%4)*8)+(8-IPR_IMPLEMENTED_BITS));
}

//	API Implementation
/*
 * 	@function				: GPIO_IRQ_Handle
 * 	@info					: API to eliminate spurious interrupts
 *
 * 	@param[in]_datatypes	: uint8_t, uint8_t
 * 	@param[in] variables	: uint8_t IRQ_Number, uint8_t EN_DI
 *
 * 	@return					: void
 *
 * 	@notes					: API to eliminate spurious interrupts by setting Pending Register bits
*/

void GPIO_IRQ_Handle(uint8_t PinNo)
{
	if(EXTI->EXTI_PR & (1<<PinNo))
		EXTI->EXTI_PR |= (1<<PinNo);
}
