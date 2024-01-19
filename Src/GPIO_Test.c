#include <stdint.h>
#include "stm32f407xx.h"
#include "stm32f407xx_gpio_driver.h"

int main(void)
{
	GPIOx_Handler_t gpio;
	gpio.pGPIOx = GPIOA;

	GPIO_PCLK_Ctrl(gpio.pGPIOx, EN);

	GPIO_PinConfig_t* temp = &(gpio.GPIO_PinConfig);
	temp->GPIO_PinNo = GPIO_P0;
	temp->GPIO_PinMode = GPIO_IT_RFT;
	GPIO_Init(&gpio);
	temp->GPIO_PinModeOType = GPIO_PP;
	temp->GPIO_PinOSpeed = GPIO_VHIGH;
	temp->GPIO_PinPUPD = GPIO_NPUPD;*/

	temp->GPIO_PinNo = GPIO_P1;
	temp->GPIO_PinMode = GPIO_IN;
	GPIO_Init(&gpio);

	//GPIO_DeInit(gpio.pGPIOx);
	//GPIO_OPinWrite(gpio.pGPIOx, GPIO_P0, HIGH);
	//GPIO_OPortWrite(gpio.pGPIOx, 0x1);
	//while((GPIO_IPinRead(gpio.pGPIOx, GPIO_P1)));

	while(GPIO_IPortRead(GPIOA)&0x2);
	for(;;)
	{
		GPIO_ToggleOPin(GPIOA, GPIO_P0);
		for(int i=1;i<=533333;i++);
	}
}
