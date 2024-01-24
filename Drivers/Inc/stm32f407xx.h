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

//Processor NVIC_ISER Register definitions
#define NVIC_ISER_BASEADDR	0xE000E100
#define NVIC_ISER_PTR		((uint32_t*)NVIC_ISER_BASEADDR)
#define NVIC_ISER(IRQ_No)	(NVIC_ISER_PTR+(IRQ_No/32))				//Example for IRQ 32, NVIC ISER will return NVIC_ISER1
//Processor NVIC_ICER Register definitions
#define NVIC_ICER_BASEADDR	0xE000E180
#define NVIC_ICER_PTR		((uint32_t*)NVIC_ICER_BASEADDR)
#define NVIC_ICER(IRQ_No)	(NVIC_ICER_PTR+(IRQ_No/32))
//Processor NVIC_IPR Register Definitions
#define NVIC_IPR_BASEADDR	0xE000E400
#define NVIC_IPR_PTR		((uint32_t*)NVIC_IPR_BASEADDR)
#define NVIC_IPR(IRQ_No)	(NVIC_IPR_PTR+(IRQ_No/4))

//Processor NVIC IPR Implemented Bits
#define IPR_IMPLEMENTED_BITS	4

//IRQ Numbers
#define IRQNo_EXTI0     6
#define IRQNo_EXTI1     7
#define IRQNo_EXTI2     8
#define IRQNo_EXTI3     9
#define IRQNo_EXTI4     10
#define IRQNo_EXTI5_9   23   // EXTI5 to EXTI9 share the same IRQ number
#define IRQNo_EXTI10_15 40   // EXTI10 to EXTI15 share the same IRQ number

//IRQ Priorities
#define IRQ_Pri_0   0
#define IRQ_Pri_1   1
#define IRQ_Pri_2   2
#define IRQ_Pri_3   3
#define IRQ_Pri_4   4
#define IRQ_Pri_5   5
#define IRQ_Pri_6   6
#define IRQ_Pri_7   7
#define IRQ_Pri_8   8
#define IRQ_Pri_9   9
#define IRQ_Pri_10  10
#define IRQ_Pri_11  11
#define IRQ_Pri_12  12
#define IRQ_Pri_13  13
#define IRQ_Pri_14  14
#define IRQ_Pri_15  15

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

//SPI Base Addresses
#define SPI1_BASEADDR	(APB2_BASEADDR + 0x3000)
#define SPI2_BASEADDR	(APB1_BASEADDR + 0x3800)
#define SPI3_BASEADDR	(APB1_BASEADDR + 0x3C00)
#define SPI4_BASEADDR	(APB2_BASEADDR + 0x3400)
#define SPI5_BASEADDR	(APB2_BASEADDR + 0x5000)
#define SPI6_BASEADDR	(APB2_BASEADDR + 0x5400)

//RCC Base Address on AHB1
#define RCC_BASEADDR		(AHB1_BASEADDR+0x3800)
#define SYSCFG_BASEADDR		(APB2_BASEADDR+0x3800)
#define EXTI_BASEADDR		(APB2_BASEADDR+0x3C00)

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

//RCC Macro
#define RCC		((RCC_RegDef_t*)RCC_BASEADDR)

//SYSCFG Register Structure
typedef struct
{
	__vo uint32_t SYSCFG_MEMRMPl;
	__vo uint32_t SYSCFG_PMC;
	__vo uint32_t SYSCFG_EXTICR[4];
	__vo uint32_t SYSCFG_CMPCR;
}SYSCFG_RegDef_t;

//SYSCFG Macro
#define SYSCFG	((SYSCFG_RegDef_t*)SYSCFG_BASEADDR)

//EXTI Register Structure
typedef struct
{
	__vo uint32_t EXTI_IMR;
	__vo uint32_t EXTI_EMR;
	__vo uint32_t EXTI_RTSR;
	__vo uint32_t EXTI_FTSR;
	__vo uint32_t EXTI_SWIER;
	__vo uint32_t EXTI_PR;
}EXTI_RegDef_t;

//EXTI Macro
#define EXTI ((EXTI_RegDef_t*)EXTI_BASEADDR)

//SPI Register Structure
typedef struct
{
	uint32_t SPI_CR1;
	uint32_t SPI_CR2;
	uint32_t SPI_SR;
	uint32_t SPI_DR;
	uint32_t SPI_CRCPR;
	uint32_t SPI_RXCRCR;
	uint32_t SPI_TXCRCR;
	uint32_t SPI_I2SCFGR;
	uint32_t SPI_I2SPR;
}SPIx_RegDef_t;

//SPI Macro
#define SPI1    ((SPIx_RegDef_t*)SPI1_BASEADDR)
#define SPI2    ((SPIx_RegDef_t*)SPI2_BASEADDR)
#define SPI3    ((SPIx_RegDef_t*)SPI3_BASEADDR)
#define SPI4    ((SPIx_RegDef_t*)SPI4_BASEADDR)
#define SPI5    ((SPIx_RegDef_t*)SPI5_BASEADDR)
#define SPI6    ((SPIx_RegDef_t*)SPI6_BASEADDR)

//GPIO Peripheral Clock Enables
#define GPIO_PCLK_EN(i)	  (RCC->RCC_AHB1ENR |= (1U << i))

//GPIO Peripheral Clock Disable
#define GPIO_PCLK_DI(i)   (RCC->RCC_AHB1ENR &= ~(1U << i))

//SYSCFG Clock Enable
#define SYSCFG_PCLK_EN()	(RCC->RCC_APB2ENR |= (1U<<14))
//SYSCFG Clock Disable
#define SYSCFG_PCLK_DI()	(RCC->RCC_APB2ENR &= ~(1U<<14))

//SPI Peripheral Clock Enable
#define SPI1_PCLK_EN()	((RCC->RCC_APB2ENR) |= (1U<<12))
#define SPI2_PCLK_EN()  ((RCC->RCC_APB1ENR) |= (1U << 14))
#define SPI3_PCLK_EN()  ((RCC->RCC_APB1ENR) |= (1U << 15))
//SPI Peripheral Clock Disable
#define SPI1_PCLK_DI()	((RCC->RCC_APB2ENR) &= ~(1U<<12))
#define SPI2_PCLK_DI()  ((RCC->RCC_APB1ENR) &= ~(1U << 14))
#define SPI3_PCLK_DI()  ((RCC->RCC_APB1ENR) &= ~(1U << 15))

#define HIGH		1
#define LOW			0

//EN_DI
#define EN	1
#define DI	0

uint8_t GPIO_IRQNum(uint8_t PinNo);

#endif /* INC_STM32F407XX_H_ */
