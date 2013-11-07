# Recursive Wildcard Function
rwildcard=$(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2) $(filter $(subst *,%,$2),$d))

ARDUINO_PATH=../../../../../../external/arduino/

ARDUINOSRC=$(ARDUINO_PATH)/external/arduino-1.0.5/hardware/arduino/cores/arduino

INC=-I /usr/lib/gcc/avr/4.7.2/include -I ../../src/ -I $(ARDUINOSRC) -I $(ARDUINOSRC)/../../variants/standard/ \
-I ../../../../../../include/

SRC=$(call rwildcard, ../../src/, *.cpp) $(call rwildcard, ../../src/, *.c) \
../../../../../../src/Utils/ArduinoToLinux/Module.cpp \
../../../../../../src/Utils/ArduinoToLinux/CommunicationDriver.cpp \
../../../../../../src/Utils/ArduinoComponents/LED.cpp

LIBS=../../../../../../bin/Component/arduino/atmega328p/robotengine.a ../../../../../../bin/Module/arduino/atmega328p/robotengine.a $(ARDUINO_PATH)bin/atmega328p/arduino.a

all: compile upload

compile:
	avr-gcc -D__AVR_ATmega328p__ -DF_CPU=16000000UL -mmcu=atmega328p -o main.elf $(SRC) -Os $(INC) -DRE_PLATFORM_ARDUINO $(LIBS)
	objcopy -O ihex -R .eeprom main.elf main.hex

upload:
	avrdude -p m328p -c stk500v1 \
  -P /dev/ttyACM0 \
  -c arduino \
 -e -U flash:w:main.hex

uploadisp:
	avrdude -p m328p \
  -P usb \
  -c avrispmkII \
  -e -U flash:w:main.hex

clean:
	rm main.elf
	rm main.hex

# -P /dev/serial/by-id/usb-Arduino__www.arduino.cc__Arduino_Uno_64935343633351800161-if00 \

#atmega328p

