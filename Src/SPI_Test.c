/*
 * SPI_Test.c
 *
 *  Created on: Jan 25, 2024
 *      Author: TeensyDev
 */

#include "stm32f407xx_spi_driver.h"

int main(void)
{
	SPIx_Handler_t spi;
	spi.pSPIx = SPI1;
	spi.SPI_PinConfig.SPI_Mode = SPI_MSTR;

	SPI_PCLK_Ctrl(spi.pSPIx, EN);
	SPI_Init(&spi);
}

