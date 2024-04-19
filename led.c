#include "led.h"

void LED_Init(void){
    //enable GPIOD perherial clk
    RCC->AHB1ENR |= (1 << 3);

	//config the port 12 to output
	GPIOD->MODER &= ~(0b11 << (2*12));
	GPIOD->MODER |= (0b01 << (2*12));

    //setup no pull up & pull down register
	GPIOD->PUPDR &= ~(0b11 << (2*12));

	//setup output to push pul
	GPIOD->OTYPER &= ~(0b1 << 12);

	//setup low output speed
	GPIOD->OSPEEDR &= ~(0b11 << (2*12));
}

void GPIO_toggle_led(void){
	uint8_t value = (GPIOD->ODR >> 12) & 0b0001;
	if (value == 0) (GPIOD->BSRR) |= (1 << 12);
	else if (value == 1) (GPIOD->BSRR) |= (1 << (12 + 16));
}