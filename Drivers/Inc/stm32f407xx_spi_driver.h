/*
 * stm32f407xx_spi_driver.h
 *
 *  Created on: Jan 24, 2024
 *      Author: TeensyDev
 */

#ifndef INC_STM32F407XX_SPI_DRIVER_H_
#define INC_STM32F407XX_SPI_DRIVER_H_

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
}SPI_RegDef_t;

#endif /* INC_STM32F407XX_SPI_DRIVER_H_ */
