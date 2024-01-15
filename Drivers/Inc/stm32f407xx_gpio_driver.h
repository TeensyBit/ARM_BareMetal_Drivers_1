/*
 * stm32f407xx_gpio_driver.h
 *
 *  Created on: Jan 15, 2024
 *      Author: TeensyDev
 */

#ifndef INC_STM32F407XX_GPIO_DRIVER_H_
#define INC_STM32F407XX_GPIO_DRIVER_H_

/*
 * -> Handler
 * -> Pin Config
 */

#include <stdint.h>
#include "stm32f407xx.h"

//GPIO_PinNo
#define GPIO_P0  0
#define GPIO_P1  1
#define GPIO_P2  2
#define GPIO_P3  3
#define GPIO_P4  4
#define GPIO_P5  5
#define GPIO_P6  6
#define GPIO_P7  7
#define GPIO_P8  8
#define GPIO_P9  9
#define GPIO_P10 10
#define GPIO_P11 11
#define GPIO_P12 12
#define GPIO_P13 13
#define GPIO_P14 14
#define GPIO_P15 15

//GPIO_Mode
#define GPIO_IN		0		//Input
#define GPIO_OUT	1		//Output
#define GPIO_AF		2		//Alternate functions
#define GPIO_AN		3		//Analog

//GPIO_GPIO_OTYPE
#define GPIO_PP		0		//Push-pull
#define GPIO_OD		1		//Open-drain

//GPIO_OSPEED
#define GPIO_LOW		0
#define GPIO_MED		1
#define GPIO_HIGH		2
#define GPIO_VHIGH		3

//GPIO_PUPDR
#define GPIO_NPUPD		0	//No pull-up
#define GPIO_PU			1	//Pull-Up
#define GPIO_PD			2	//Pull-down

//GPIO API PinConfiguration
typedef struct
{
	uint8_t GPIO_PinNo;
	uint8_t GPIO_PinMode;
	uint8_t GPIO_PinModeOType;
	uint8_t GPIO_PinOSpeed;
	uint8_t GPIO_PinAltFunc;
}GPIO_PinConfig_t;

//GPIO API Handler
typedef struct
{
	GPIOx_RegDef_t *pGPIOx;
	GPIO_PinConfig_t GPIO_PinConfig;
}GPIOx_Handler_t;

//API Prototypes
/*
 * GPIO_PCLK_Ctrl: This API enables/disables the peripheral clock for respective GPIO Port
 * GPIO_Init
 * GPIO_DeInit
 * GPIO_IPinRead
 * GPIO_PortRead
 * GPIO_OPinWrite
 * GPIO_OPortWrite
 * GPIO_ToggleOPins
 */

//EN_DI
#define EN	1
#define DI	0

void GPIO_PCLK_Ctrl(GPIOx_RegDef_t *pGPIOx, uint8_t EN_DI);
void GPIO_Init(GPIOx_Handler_t* pGPIOx_Handle);
void GPIO_DeInit(void);
uint8_t GPIO_IPinRead(uint8_t PinNumber);
uint16_t GPIO_PortRead(void);
void GPIO_OPinWrite(uint8_t PinNumber, uint8_t Value);
void GPIO_OPortWrite(uint16_t Value);
void GPIO_ToggleOPins(uint8_t PinNumber);

#endif /* INC_STM32F407XX_GPIO_DRIVER_H_ */
