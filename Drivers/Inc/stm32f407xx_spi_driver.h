/*
 * stm32f407xx_spi_driver.h
 *
 *  Created on: Jan 24, 2024
 *      Author: TeensyDev
 */

#ifndef INC_STM32F407XX_SPI_DRIVER_H_
#define INC_STM32F407XX_SPI_DRIVER_H_

#include "stm32f407xx.h"

//SPI_Mode
#define SPI_SLAV	0
#define SPI_MSTR	1

//SPI_BusConf
#define SPI_FULL		0
#define SPI_HALF		1
#define SPI_SIMP_TX		2
#define SPI_SIMP_RX		3

//SPI_Data Frame
#define SPI_8BIT	0
#define SPI_16BIT	1

//SPI_ClkPol
#define SPI_CLKPO0	0
#define SPI_CLKPO1	1

//SPI_ClkPha
#define SPI_CLKPH0	0
#define SPI_CLKPH1	1

//SPI_SoftMgmt
#define SPI_SOFT	0
#define SPI_HARD	1

//SPI_BaudCtrl
#define SPI_BRDIV_2		0
#define SPI_BRDIV_4		1
#define SPI_BRDIV_8		2
#define SPI_BRDIV_16	3
#define SPI_BRDIV_32	4
#define SPI_BRDIV_64	5
#define SPI_BRDIV_128	6
#define SPI_BRDIV_256	7

//SPI_CR1 Register
#define SPI_CR1_CPHA		0
#define SPI_CR1_CPOL		1
#define SPI_CR1_MSTR    	2
#define SPI_CR1_BR      	3
#define SPI_CR1_SPE     	6
#define SPI_CR1_LSBFIRST    7
#define SPI_CR1_SSI     	8
#define SPI_CR1_SSM     	9
#define SPI_CR1_RXONLY  	10
#define SPI_CR1_DFF     	11
#define SPI_CR1_CRCNEXT 	12
#define SPI_CR1_CRCEN   	13
#define SPI_CR1_BIDIOE  	14
#define SPI_CR1_BIDIMODE    15

//SPI_SR Register
#define SPI_SR_RXNE			0 // Receive buffer not empty
#define SPI_SR_TXE			1 // Transmit buffer empty
#define SPI_SR_CHSIDE		2 // Channel side
#define SPI_SR_UDR			3 // Underrun flag
#define SPI_SR_CRCERR		4 // CRC error flag
#define SPI_SR_MODF			5 // Mode fault
#define SPI_SR_OVR			6 // Overrun flag
#define SPI_SR_BSY			7 // Busy flag
#define SPI_SR_FRE			8 // TI frame format error

//SPI Reset
#define SPI_RST_OFF			12		//SPI1_RST = 12-APB2RSTR;SPI<2_3>_RST = 12+(<2_3>)-AHB2RSTR;

typedef struct
{
	uint8_t SPI_Mode;			//Master/Slave
	uint8_t SPI_BusConf;		//Full/Half - Duplex/Simplex
	uint8_t SPI_DataFrm;		//8/16 bit
	uint8_t SPI_ClkPol;			//Clock Polarity
	uint8_t SPI_ClkPha;			//Clock Phase
	uint8_t SPI_SoftMgmt;		//SSM bit
	uint8_t SPI_BaudCtrl;			//BaudRate Control
}SPI_PinConfig_t;

typedef struct
{
	SPIx_RegDef_t* pSPIx;
	SPI_PinConfig_t SPI_PinConfig;
}SPIx_Handler_t;

//API Prototypes
void SPI_PCLK_Ctrl(SPIx_RegDef_t *pSPIx, uint8_t EN_DI);
void SPI_Init(SPIx_Handler_t *pSPIx_Handle);
void SPI_DeInit(SPIx_RegDef_t *pSPIx);
void SPI_RST(uint8_t i);
void SPI_TxDataB(SPIx_RegDef_t *pSPIx, uint8_t *pTxBuff, uint32_t len);
void SPI_RxData(void);

#endif /* INC_STM32F407XX_SPI_DRIVER_H_ */
