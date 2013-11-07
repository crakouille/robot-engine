# Recursive Wildcard Function
rwildcard=$(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2) $(filter $(subst *,%,$2),$d))

ARDUINOSRC=../../../../../external/arduino-1.0.5/hardware/arduino/cores/arduino

INC=-I /usr/lib/gcc/avr/4.7.2/include -I ../../../../../include -I ../../src/ -I $(ARDUINOSRC) -I $(ARDUINOSRC)/../../variants/standard/

SRC=$(call rwildcard, ../../src/, *.cpp) $(call rwildcard, ../../src/, *.c)
OACL=../../../../../bin/atmega328p/arduino.a

all: compile upload

compile:
	avr-gcc -D__AVR_ATmega328p__ -DF_CPU=16000000UL -mmcu=atmega328p -o main.elf $(SRC) -Os $(INC) $(OACL)
	objcopy -O ihex -R .eeprom main.elf main.hex

upload:
	avrdude -p m328p -c stk500v1 \
  -P /dev/ttyACM0 \
  -c arduino \
 -e -U flash:w:main.hex

clean:
	rm main.elf
	rm main.hex

# -P /dev/serial/by-id/usb-Arduino__www.arduino.cc__Arduino_Uno_64935343633351800161-if00 \

#atmega328p

