#include <stdint.h>
#include "stm32f407xx.h"
#include "stm32f407xx_gpio_driver.h"

void GPIO_Config(GPIOx_Handler_t* gpio, GPIOx_RegDef_t* GPIOx, uint8_t GPIO_PinNo, uint8_t GPIO_PinMode);
void EXTI1_IRQHandler(void);

uint8_t flag = 0;

int main(void)
{
	GPIOx_Handler_t gpio;

	GPIO_PCLK_Ctrl(GPIOA, EN);

	//GPIO_PinConfig_t* temp = &(gpio.GPIO_PinConfig);
	GPIO_Config(&gpio, GPIOA, GPIO_P0, GPIO_OUT);
	GPIO_Config(&gpio, GPIOA, GPIO_P1, GPIO_IT_FT);
	GPIO_IRQConfig(GPIO_IRQNum(GPIO_P1), EN);
	GPIO_IRQPriority(GPIO_IRQNum(GPIO_P1), IRQ_Pri_0);

	for(;;)
	{
		if(flag==1)
		{
			GPIO_ToggleOPin(GPIOA, GPIO_P0);
			for(int i=1;i<=533333;i++);
		}
		else
			GPIO_OPinWrite(GPIOA, GPIO_P0, LOW);
	}
}

void EXTI1_IRQHandler(void)
{
	GPIO_IRQ_Handle(GPIO_P1);
	flag ^= 1;
}

void GPIO_Config(GPIOx_Handler_t* gpio, GPIOx_RegDef_t* GPIOx, uint8_t GPIO_PinNo, uint8_t GPIO_PinMode)
{

	gpio->pGPIOx = GPIOx;
	gpio->GPIO_PinConfig.GPIO_PinNo = GPIO_PinNo;
	gpio->GPIO_PinConfig.GPIO_PinMode = GPIO_PinMode;
	GPIO_Init(gpio);
}
