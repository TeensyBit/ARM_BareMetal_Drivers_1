#Documentation: 

##Setting up handler and setting the PORT

GPIOx_Handler_t <Handle>;
<Handle>.pGPIOx = GPIO<X>;

Example: 
GPIOx_Handler_t gpio;
gpio.pGPIOx = GPIOA;

##Enabling Peripheral Clock for the corresponding GPIO

GPIO_PCLK_Ctrl(<Handle>.pGPIOx)

Example: 
GPIO_PCLK_Ctrl(gpio.pGPIOx)

##Configuring the GPIO pins
<Handle>.GPIO_PinConfig.GPIO_<Config> = <Configuration>

##Available Configs:
	###GPIO_PinNO
	Configurations:	GPIO_P<PinNo_0_15> 
					Eg: GPIO_PO 
	
	
	