#ifndef LED_H_
#define LED_H_
#include <stdint.h>

#define GPIOD_BASE_ADDR				0x40020C00U

#define RCC_BASE_ADDR				0x40023800U

typedef struct{
	volatile uint32_t CR;			//clock control 			offset 0x00
	volatile uint32_t PLLCFGR;		//PLL configuration			offset 0x04
	volatile uint32_t CFGR;			//clock	configuration		offset 0x08
	volatile uint32_t CIR;			//clock interrupt			offset 0x0C
	volatile uint32_t AHB1RSTR;		//AHB1 peripheral reset		offset 0x10
	volatile uint32_t AHB2RSTR;		//AHB2 peripheral reset		offset 0x14
	volatile uint32_t AHB3RSTR;		//AHB3 peripheral reset		offset 0x18
	volatile uint32_t RESERVED1;		//							offset 0x1C
	volatile uint32_t APB1RSTR;		//AHB3 peripheral reset		offset 0x20
	volatile uint32_t APB2RSTR;		//AHB3 peripheral reset		offset 0x24
	volatile uint32_t RESERVED2[2];	//							offset 0x28,0x2C
	volatile uint32_t AHB1ENR;		//AHB1 peripheral clock enable		offset 0x30
	volatile uint32_t AHB2ENR;		//AHB2 peripheral clock enable		offset 0x34
	volatile uint32_t AHB3ENR;		//AHB3 peripheral clock enable		offset 0x38
	volatile uint32_t RESERVED3;		//									offset 0x3C
	volatile uint32_t APB1ENR;		//APB1 peripheral clock enable		offset 0x40
	volatile uint32_t APB2ENR;		//APB2 peripheral clock enable		offset 0x44
	volatile uint32_t RESERVED4[2];	//									offset 0x48,0x4C
	volatile uint32_t AHB1LPENR;		//AHB1 clock enable low power		offset 0x50
	volatile uint32_t AHB2LPENR;		//AHB2 clock enable low power		offset 0x54
	volatile uint32_t AHB3LPENR;		//AHB3 clock enable low power		offset 0x58
	volatile uint32_t RESERVED5;		//									offset 0x5C
	volatile uint32_t APB1LPENR;		//APB1 clock enable low power		offset 0x60
	volatile uint32_t APB2LPENR;		//APB2 clock enable low power		offset 0x64
	volatile uint32_t RESERVED6[2];	//									offset 0x68,0x6C
	volatile uint32_t BDCR;			//backup domain control				offset 0x70
	volatile uint32_t CSR;			//clock control & status register 	offset 0x74
	volatile uint32_t RESERVED7[2];	//									offset 0x78,0x7C
	volatile uint32_t SSCGR;			//spread spectrum clock generation	offset 0x80
	volatile uint32_t PLLI2SCFGR;	//PLLI2S configuration				offset 0x84
}RCC_RegDef_t;

#define RCC			((RCC_RegDef_t*) RCC_BASE_ADDR)

typedef struct{
	volatile uint32_t MODER;			//mode 						offset 0x00
	volatile uint32_t OTYPER;		//output type 				offset 0x04
	volatile uint32_t OSPEEDR;		//output speed				offset 0x08
	volatile uint32_t PUPDR;			//pull-up/pull-down			offset 0x0C
	volatile uint32_t IDR;			//input data				offset 0x10
	volatile uint32_t ODR;			//output data				offset 0x14
	volatile uint32_t BSRR;			//bit set/reset				offset 0x18
	volatile uint32_t LCKR;			//configuration lock 		offset 0x1C
	volatile uint32_t AFR[2];		//alternate function 		offset 0x20,0x24
}GPIOx_RegDef_t;


#define GPIOD		((GPIOx_RegDef_t*) GPIOD_BASE_ADDR)

void LED_Init(void);
void GPIO_toggle_led(void);

#endif