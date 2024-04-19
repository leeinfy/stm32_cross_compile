CC=arm-none-eabi-gcc
MARCH=cortex-m4
CFLAGS = -c -mcpu=$(MARCH) -mthumb -std=gnu11 -O1
LDFLAGS = -nostdlib -T stm32_ls.ld -Wl,-Map=final.map

all:main.o  led.o stm32_startup.o final.elf

#target $^ : dependency $@
main.o:main.c
	$(CC) $(CFLAGS) $^ -o $@

led.o:led.c
	$(CC) $(CFLAGS) $^ -o $@

stm32_startup.o:stm32_startup.c
	$(CC) $(CFLAGS) $^ -o $@

final.elf: main.o led.o stm32_startup.o
	$(CC) $(LDFLAGS) $^ -o $@

load:
	openocd -f board/stm32f4discovery.cfg

clean:
	rm -rf *.o *.elf