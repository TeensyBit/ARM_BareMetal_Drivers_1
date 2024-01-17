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
	GPIO_PCLK_Ctrl(gpio.pGPIOA)

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
## Initialising GPIO Pins with the selected configuration
	GPIO_Init(&<Handle>)
 	Eg: GPIO_Init(&gpio)
## De-Initialising GPIO 
	GPIO_DeInit(<Handle>.pGPIOx)
	Eg: GPIO(gpio.pGPIOx)
## Output GPIO Pin Write
 	GPIO_OPinWrite(<Handle>.pGPIOx, GPIO_P<0_15>, <HIGH/LOW>)
	Eg: GPIO_OPinWrite(gpio.pGPIOx, GPIO_P0, HIGH)
## Output GPIO Port Write
 	GPIO_OPortWrite(<Handle>.pGPIOx, <uint16_t data>)
	Eg: GPIO_OPortWrite(gpio.pGPIOx, 0x1)
## Toggle GPIO Pin
 	GPIO_ToggleOPin(GPIO<A_K>,GPIO_P<0_15>)
	Eg: GPIO_ToggleOPin(GPIOA, GPIO_P0)
## Input GPIO Pin
	GPIO_IPinRead(<Handle>.pGPIOx, GPIO_P<0_15>)
 	Eg: GPIO_IPinRead(gpio.pGPIOx, GPIO_P1)
## Input GPIO Port
	uint16_t <var> = GPIO_IPortRead(GPIO<A_K>, GPIO_P<0_15>)
 	uint16_t in = GPIO_IPortRead(GPIOA, GPIO_P0)