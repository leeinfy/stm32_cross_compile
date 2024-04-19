#include <stdint.h>
#include "led.h"

void delay(void){
	for(uint32_t i=0; i<500000; i++);
}

int main(void){
    LED_Init();

	while(1){
		GPIO_toggle_led();
		delay();
	}
}