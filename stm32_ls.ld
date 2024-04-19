ENTRY(Reset_Handler)

MEMORY{
    /*flash memory read and executable*/
    FLASH(rx):ORIGIN = 0x08000000,LENGTH = 1024K

    /*SRAM read, write and executable*/
    SRAM(rwx):ORIGIN = 0x20000000,LENGTH = 128K
    SRAM1(rwx):ORIGIN = 0x20000000,LENGTH = 112K
    SRAM2(rwx):ORIGIN = 0x2001C000,LENGTH = 16K
}

SECTIONS{
    .text :{
        *(.isr_vector)
        *(.text)
        *(.rodata)
        . = ALIGN(4);                 /*aligned to next word boundary*/
        _etext = .;
    }> FLASH AT > FLASH             /*>(vma) AT>(lma)*/

    .data :{
        /*location counter only track vma*/
        _sdata = .;
        *(.data)
        _edata = .;
    }> SRAM AT > FLASH

    .bss :{
        _sbss = .;
        *(.bss)
        _ebss = .;
    }> SRAM
}