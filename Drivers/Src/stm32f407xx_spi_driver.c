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

	/* SPI Bus Configuration
	 * Full-Duplex: Also called 2 line bi-directional mode
	 * Half-Duplex: 1 line bi-directional mode, Setting the BIDIOE bit determines between Tx/Rx
	 * Simplex:  Tx only - Disconnect MISO line in Full-Duplex communication
	 * 			 Rx only - Unidirectional Rx Only mode (BIDIMODE=0;RXONLY=1)
	 */

	if(temp->SPI_BusConf == SPI_FULL || temp->SPI_BusConf == SPI_SIMP_TX)	//BIDIMODE=0;RXONLY=0
	{
		pSPIx_Handle->pSPIx->SPI_CR1 &= ~(1<<SPI_CR1_BIDIMODE);		//Clear BIDIMODE
		pSPIx_Handle->pSPIx->SPI_CR1 &= ~(1<<SPI_CR1_RXONLY);		//Clear RXONLY
	}
	else if(temp->SPI_BusConf == SPI_SIMP_RX)
	{
		pSPIx_Handle->pSPIx->SPI_CR1 &= ~(1<<SPI_CR1_BIDIMODE);		//Clear BIDIMODE
		pSPIx_Handle->pSPIx->SPI_CR1 |= ~(1<<SPI_CR1_RXONLY);		//Set RXONLY
	}
	else if(temp->SPI_BusConf == SPI_HALF)				//Set BIDIOE in the Application
		pSPIx_Handle->pSPIx->SPI_CR1 |= (1<<SPI_CR1_BIDIMODE);

	//SPI Data Frame Format
	pSPIx_Handle->pSPIx->SPI_CR1 &= ~(1<<11);
	pSPIx_Handle->pSPIx->SPI_CR1 |= ((temp->SPI_DataFrm)<<SPI_CR1_DFF);

	//SPI Peripheral Clock Polarity
	pSPIx_Handle->pSPIx->SPI_CR1 &= ~(1<<1);
	pSPIx_Handle->pSPIx->SPI_CR1 |= ((temp->SPI_ClkPol)<<SPI_CR1_CPOL);

	//SPI Peripheral Clock Phase
	pSPIx_Handle->pSPIx->SPI_CR1 &= ~(1<<SPI_CR1_CPHA);
	pSPIx_Handle->pSPIx->SPI_CR1 |= ((temp->SPI_ClkPha)<<SPI_CR1_CPHA);

	//Software Slave Management
	if(temp->SPI_SoftMgmt)
		pSPIx_Handle->pSPIx->SPI_CR1 |= ((temp->SPI_SoftMgmt)<<SPI_CR1_SSM);

	//Baud Rate Configuration
	pSPIx_Handle->pSPIx->SPI_CR1 &= ~(7<<SPI_CR1_BR);
	pSPIx_Handle->pSPIx->SPI_CR1 |= ((temp->BaudCtrl)<<SPI_CR1_BR);
}

void SPI_DeInit(SPIx_RegDef_t* pSPIx)
{
	if(pSPIx == SPI1) SPI_RST(1);
	else if(pSPIx == SPI2) SPI_RST(2);
	else if(pSPIx == SPI3) SPI_RST(3);
}

void SPI_RST(uint8_t i)
{
	if(i==1)
	{
		(RCC->RCC_APB2RSTR) |= (1<<SPI_RST_OFF);
		(RCC->RCC_APB2RSTR) &= ~(1<<SPI_RST_OFF);
	}
	else
	{
		(RCC->RCC_APB1RSTR) |= (1<<(SPI_RST_OFF+i));
		(RCC->RCC_APB1RSTR) &= ~(1<<(SPI_RST_OFF+i));
	}
}

void SPI_TxDataB(SPIx_RegDef_t *pSPIx, uint8_t *pTxBuff, uint32_t len)
{
	/*
	 * Wait until TXE bit is SET
	 * Check if the Data Frame format is 8/16 bit
	 * Paste 8/16 bit data to he register
	 */
	while(len)			//len should be an even number
	{
		if((pSPIx->SPI_SR)&(1<<SPI_SR_TXE))
		{
			if((pSPIx->SPI_CR1)&(1<<SPI_CR1_DFF))
			{
				pSPIx->SPI_DR = *(uint16_t*)pTxBuff;
				pTxBuff++;
				len -= 2;
			}
			else
			{
				pSPIx->SPI_DR = *pTxBuff;
				pTxBuff++;
				len--;
			}
		}
	}
}
