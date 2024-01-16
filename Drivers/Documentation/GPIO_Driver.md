# GPIO Documentation: 

## Setting up handler and setting the PORT
	GPIOx_Handler_t <Handle>;
	<Handle>.pGPIOx = GPIO<X>;

### Example: 
	GPIOx_Handler_t gpio;
	gpio.pGPIOx = GPIOA;

## Enabling Peripheral Clock for the corresponding GPIO
	GPIO_PCLK_Ctrl(<Handle>.pGPIOx)
### Example: 
	GPIO_PCLK_Ctrl(gpio.pGPIOx)

## Configuring the GPIO pins: 
	<Handle>.GPIO_PinConfig.GPIO_<Config> = <Configuration>

 ## Available Configurations:
1. ```GPIO_PinNo``` 
	```  
	 GPIO_P<0_15>
	 Eg: GPIO_P0 
	 ``` 
2. ```GPIO_Mode``` 
	```  
	 GPIO_<IN/OUT/AF/AN>
	 Eg: GPIO_OUT 
	 ```
 3. ```GPIO_PinModeOType``` 
	```  
	 GPIO_<PP/OD>
	 Eg: GPIO_PP 
	 ``` 
 4. ```GPIO_PinOSpeed```
	```
 	GPIO_<LOW/MED/HIGH/VHIGH>
 	Eg. GPIO_LOW
 	```
 5. ```GPIO_PinPUPD``` 
	```  
	 GPIO_<NPUPD/PU/PD>
	 Eg: GPIO_PU 
	 ```
 6. ```GPIO_PinAF``` 
	```  
	 GPIO_AF<0_15>
	 Eg: GPIO_AF<0> 
	 ```