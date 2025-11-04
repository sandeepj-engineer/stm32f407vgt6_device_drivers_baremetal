/*
 * 02_led_button.c
 *
 *  Created on: Nov 3, 2025
 *      Author: Admin
 */

#include "stm32f407xx_gpio_driver.h"

#define HIGH           SET
#define LOW            RESET
#define BTN_PRESSED    HIGH
#define BTN_NPRESSED   LOW

void debounce_delay(void)
{
	for(uint32_t i = 0; i < 500000/2; i++);
}

static void Led_Delay(void){
    for(int i = 0; i < 100000; i++);
}


int main(void)
{
    GPIO_Handle_t GPIOLed, GPIOBtn;

    GPIOLed.pGPIOx=GPIOD; //GPIO base address

    //pin configuration
    GPIOLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
    GPIOLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
    GPIOLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
    GPIOLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
    GPIOLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
    GPIO_Init(&GPIOLed);

    GPIOLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
    GPIOLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
    GPIOLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
    GPIOLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
    GPIOLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
    GPIO_Init(&GPIOLed);

    GPIOLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_14;
    GPIOLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
    GPIOLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
    GPIOLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
    GPIOLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
    GPIO_Init(&GPIOLed);

    GPIOLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_15;
    GPIOLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
    GPIOLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
    GPIOLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
    GPIOLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
    GPIO_Init(&GPIOLed);

    GPIO_PeripheralClockControl(GPIOD, ENABLE);

    //GPIO Button configuration

    GPIOBtn.pGPIOx = GPIOA; //GPIO base address

    GPIOBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;
    GPIOBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
    GPIOBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
    GPIOBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD; //there is a pull down available in the schematic of the Button
    GPIO_Init(&GPIOBtn);

    GPIO_PeripheralClockControl(GPIOA, ENABLE);

    //Reset LED pins
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12, GPIO_PIN_RESET);
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, GPIO_PIN_RESET);
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14, GPIO_PIN_RESET);
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15, GPIO_PIN_RESET);

    while(1){

    	//printf("waiting for the button press\n");

    	if(GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0) != BTN_NPRESSED){
            {
                // wait until the debouncing of button over cuz this ISR will excute few times before getting stable
            	debounce_delay(); //200ms

            		for(int i = 12; i <= 15; i++){
            			Led_Delay();
            			GPIO_ToggleOutputPin(GPIOD, i);
            			Led_Delay();
            		}
            }
          }
    }
        return 0;
}
