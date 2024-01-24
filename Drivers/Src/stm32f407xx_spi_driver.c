/*
 * stm32f407xx_spi_driver.c
 *
 *  Created on: Jan 25, 2024
 *      Author: TeensyDev
 */

#include "stm32f407xx_spi_driver.h"

void SPI_PCLK_Ctrl(SPIx_RegDef_t *pSPIx, uint8_t EN_DI)
{
	if(EN_DI == EN)
	{
		if (pSPIx == SPI1) SPI1_PCLK_EN();
		else if (pSPIx == SPI2) SPI2_PCLK_EN();
		else if (pSPIx == SPI3) SPI3_PCLK_EN();
	}
	else if(EN_DI == DI)
	{
		if (pSPIx == SPI1) SPI1_PCLK_DI();
		else if (pSPIx == SPI2) SPI2_PCLK_DI();
		else if (pSPIx == SPI3) SPI3_PCLK_DI();
	}
}

void SPI_Init(SPIx_Handler_t *pSPIx_Handle)
{
	SPI_PinConfig_t *temp = &(pSPIx_Handle->SPI_PinConfig);

	//Master/Slave Configuration
	pSPIx_Handle->pSPIx->SPI_CR1 &= (1<<2);
	pSPIx_Handle->pSPIx->SPI_CR1 |= ((temp->SPI_Mode)<<2);
}
