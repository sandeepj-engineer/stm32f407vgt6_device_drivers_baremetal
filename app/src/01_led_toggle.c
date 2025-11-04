/*
 * 01_led_toggle.c
 *
 *  Created on: Nov 4, 2025
 *      Author: Sandeep J
 */

#include "stm32f407xx_gpio_driver.h"

/**
 * @brief
 *
 */
static void delay (void)
{

    for( uint32_t i = 0; i < 500000; i++);

}

/**
 * @brief
 *
 * @return int
 */

int main(void)
{
    GPIO_Handle_t GPIOLed;

    GPIOLed.pGPIOx=GPIOD; //GPIO base address

    //pin configuration
    GPIOLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
    GPIOLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
    GPIOLed.GPIO_PinConfig.GPIO_PinPinOPType = GPIO_OP_TYPE_PP;
    GPIOLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
    GPIOLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

    GPIO_PeripheralClockControl(GPIOD,ENABLE);

    GPIO_Init(&GPIOLed);

    while (1)
    {
        GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12) ;
        delay();
    }


    return 0;
}
