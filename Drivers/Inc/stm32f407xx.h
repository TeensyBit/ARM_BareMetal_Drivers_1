/*
 * stm32f407xx.h
 *
 *  Created on: Jan 15, 2024
 *      Author: TeensyDev
 */

#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_

#include <stdint.h>
#include <stddef.h>

/*
 * Base addresses of different memories
 * Base addresses of AHBx and APBx
 * Base addresses of Peripherals on each of the BUS
 *
 * Structure the Peripheral Registers
 */

#define __vo	volatile

//Memory Base address definitions
#define FLASH_BASEADDR	0x08000000U
#define SRAM1_BASEADDR	0x20000000U
#define SRAM2_BASEADDR	0x2001C000u

//BUS Base address definitions
#define APB1_BASEADDR	0x40000000U
#define APB2_BASEADDR 	0x40010000U
#define AHB1_BASEADDR	0x40020000U
#define AHB2_BASEADDR	0x50000000U
#define AHB3_BASEADDR	0xA0000000U

//GPIO Base Addresses on AHB1
#define GPIOA_BASEADDR	AHB1_BASEADDR
#define GPIOB_BASEADDR 	(AHB1_BASEADDR+0x0400)
#define GPIOC_BASEADDR  (AHB1_BASEADDR + 0x0800)
#define GPIOD_BASEADDR  (AHB1_BASEADDR + 0x0C00)
#define GPIOE_BASEADDR  (AHB1_BASEADDR + 0x1000)
#define GPIOF_BASEADDR  (AHB1_BASEADDR + 0x1400)
#define GPIOG_BASEADDR  (AHB1_BASEADDR + 0x1800)
#define GPIOH_BASEADDR  (AHB1_BASEADDR + 0x1C00)
#define GPIOI_BASEADDR  (AHB1_BASEADDR + 0x2000)
#define GPIOJ_BASEADDR  (AHB1_BASEADDR + 0x2400)
#define GPIOK_BASEADDR  (AHB1_BASEADDR + 0x2800)

//RCC Base Address on AHB1
#define RCC_BASEADDR	(AHB1_BASEADDR+0x3800)

typedef struct
{
	__vo uint32_t GPIOx_MODER;
	__vo uint32_t GPIOx_OTYPER;
	__vo uint32_t GPIOx_OSPEEDR;
	__vo uint32_t GPIOx_PUPDR;
	__vo uint32_t GPIOx_IDR;
	__vo uint32_t GPIOx_ODR;
	__vo uint32_t GPIOx_BSRR;
	__vo uint32_t GPIOx_LCKR;
	__vo uint32_t GPIOx_AFR[2];
}GPIOx_RegDef_t;

//GPIOx_RegDef_t *pGPIOx = (GPIOx_RegDef_t*)GPIOx_BASEADDR
#define GPIOA   (GPIOx_RegDef_t*)GPIOA_BASEADDR
#define GPIOB   (GPIOx_RegDef_t*)GPIOB_BASEADDR
#define GPIOC   (GPIOx_RegDef_t*)GPIOC_BASEADDR
#define GPIOD   (GPIOx_RegDef_t*)GPIOD_BASEADDR
#define GPIOE   (GPIOx_RegDef_t*)GPIOE_BASEADDR
#define GPIOF   (GPIOx_RegDef_t*)GPIOF_BASEADDR
#define GPIOG   (GPIOx_RegDef_t*)GPIOG_BASEADDR
#define GPIOH   (GPIOx_RegDef_t*)GPIOH_BASEADDR
#define GPIOI   (GPIOx_RegDef_t*)GPIOI_BASEADDR
#define GPIOJ   (GPIOx_RegDef_t*)GPIOJ_BASEADDR
#define GPIOK   (GPIOx_RegDef_t*)GPIOK_BASEADDR

//RCC Peripheral Register structure
typedef struct
{
	__vo uint32_t RCC_CR;
	__vo uint32_t RCC_PLLCFGR;
	__vo uint32_t RCC_CFGR;
	__vo uint32_t RCC_CIR;
	__vo uint32_t RCC_AHB1RSTR;
	__vo uint32_t RCC_AHB2RSTR;
	__vo uint32_t RCC_AHB3RSTR;
	__vo uint32_t RESERVED1;
	__vo uint32_t RCC_APB1RSTR;
	__vo uint32_t RCC_APB2RSTR;
	__vo uint32_t RESERVED2[2];
	__vo uint32_t RCC_AHB1ENR;
	__vo uint32_t RCC_AHB2ENR;
	__vo uint32_t RCC_AHB3ENR;
	__vo uint32_t RESERVED3;
	__vo uint32_t RCC_APB1ENR;
	__vo uint32_t RCC_APB2ENR;
	__vo uint32_t RESERVED4[2];
	__vo uint32_t RCC_AHB1LPENR;
	__vo uint32_t RCC_AHB2LPENR;
	__vo uint32_t RCC_AHB3LPENR;
	__vo uint32_t RESERVED5[2];
	__vo uint32_t RCC_APB1LPENR;
	__vo uint32_t RCC_APB2LPENR;
	__vo uint32_t RESERVED6[2];
	__vo uint32_t RCC_BDCR;
	__vo uint32_t RCC_CSR;
	__vo uint32_t RESERVED7[2];
	__vo uint32_t RCC_SSCGR;
	__vo uint32_t RCC_PLLI2SCFGR;
}RCC_RegDef_t;

#define RCC		((RCC_RegDef_t*)RCC_BASEADDR)

//GPIO Peripheral Clock Enables
#define GPIO_PCLK_EN(i)	  (RCC->RCC_AHB1ENR |= (1U << i))

//GPIO Peripheral Clock Disable
#define GPIO_PCLK_DI(i)   (RCC->RCC_AHB1ENR &= ~(1U << i))

//SPI Peripheral Clock Enable
#define SPI1_EN()	((RCC->RCC_APB2ENR) |= (1U<<12))
#define SPI2_EN()   ((RCC->RCC_APB1ENR) |= (1U << 14))
#define SPI3_EN()   ((RCC->RCC_APB1ENR) |= (1U << 15))
//SPI Peripheral Clock Disable
#define SPI1_DI()	((RCC->RCC_APB2ENR) &= ~(1U<<12))
#define SPI2_DI()   ((RCC->RCC_APB1ENR) &= ~(1U << 14))
#define SPI3_DI()   ((RCC->RCC_APB1ENR) &= ~(1U << 15))

#endif /* INC_STM32F407XX_H_ */
