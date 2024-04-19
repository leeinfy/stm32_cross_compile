#include "stm32_startup.h"

extern uint32_t _etext;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _ebss;

extern void main(void);

//when reset the mcu, reset_handler will be called
//this address of rest_handler is store in 0x0000_0004
void Reset_Handler(void){
    //copy .data
    uint32_t size = &_edata - &_sdata;
    //copy byte by bytes
    uint8_t *pDst = (uint8_t*)&_sdata;        //SRAM
    uint8_t *pSrc = (uint8_t*)&_etext;        //Flash

    for(uint32_t i=0; i<size; i++){
        *pDst++ = *pSrc++;
    }
    //init .bss
    size = &_ebss - &_sbss;
    pDst = (uint8_t*)&_sbss;        //SRAM

    for(uint32_t i=0; i<size; i++){
        *pDst++ = 0;
    }

    //call main(), import std library is skipped
    main();
}

void Default_Handler(void){
    while(1);
}

