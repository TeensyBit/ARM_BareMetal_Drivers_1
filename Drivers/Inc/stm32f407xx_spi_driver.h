/*
 * stm32f407xx_spi_driver.h
 *
 *  Created on: Jan 24, 2024
 *      Author: TeensyDev
 */

#ifndef INC_STM32F407XX_SPI_DRIVER_H_
#define INC_STM32F407XX_SPI_DRIVER_H_

//SPI_Mode
#define SPI_SLAV	0
#define SPI_MSTR	1

//SPI_BusConf
#define SPI_FULL	0
#define SPI_HALF	1
#define SPI_SIMP	2

//SPI_Data Frame
#define SPI_8BIT	0
#define SPI_16BIT	1

//SPI_ClkPol
#define SPI_CLKPO0	0
#define SPI_CLKPO1	1

//SPI_ClkPha
#define SPI_CLKPH1	0
#define SPI_CLKPH2	1

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


typedef struct
{
	uint8_t SPI_Mode;			//Master/Slave
	uint8_t SPI_BusConf;		//Full/Half - Duplex/ Simplex
	uint8_t SPI_DataFrm;		//8/16 bit
	uint8_t SPI_ClkPol;			//Clock Polarity
	uint8_t SPI_ClkPha;			//Clock Phase
	uint8_t SPI_SoftMgmt;		//SSM bit
	uint8_t BaudCtrl;			//BaudRate Control
}SPI_PinConfig_t;

typedef struct
{
	SPIx_RegDef_t* pSPIx;
	SPI_PinConfig_t SPI_PinConfig;
}SPIx_Handler_t;

//API Prototypes
void GPIO_PCLK_Ctrl(GPIOx_RegDef_t *pGPIOx, uint8_t EN_DI);
void SPI_Init(void);
void SPI_DeInit(void);
void SPI_TxData(void);
void SPI_RxData(void);

#endif /* INC_STM32F407XX_SPI_DRIVER_H_ */
