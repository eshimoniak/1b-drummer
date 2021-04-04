SRC=$(wildcard *.c)
OBJ=$(subst .c,.o,$(SRC))
ELF=$(notdir $(CURDIR)).elf
HEX=$(notdir $(CURDIR)).hex
F_CPU=8000000L
PRGMR=usbtiny

CFLAGS=-mmcu=atmega328p -DF_CPU=$(F_CPU) -Wall -Wno-main
CC=avr-gcc

all: $(HEX)

main.o: main.c main.h noise.h
noise.o: noise.c noise.h main.h
loop.o: loop.c loop.h main.h

flash: $(HEX)
	avrdude -v -c $(PRGMR) -p m328p -U flash:w:$(HEX)

setfuse:
	avrdude -v -c $(PRGMR) -p m328p -U lfuse:w:0xE2:m 

$(HEX): $(ELF)
	avr-objcopy -O ihex -R .eeprom $< $@

$(ELF): $(OBJ)
	$(CC) $(CFLAGS) $(SRC) -o $@

clean:
	rm -f $(OBJ) $(ELF) $(HEX)
