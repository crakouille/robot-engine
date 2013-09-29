# Recursive Wildcard Function
rwildcard=$(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2) $(filter $(subst *,%,$2),$d))

ARDUINOSRC=../../external/arduino-1.0.5/hardware/arduino/cores/arduino

INC=-I /usr/lib/gcc/avr/4.7.2/include -I ../../include -I $(ARDUINOSRC) -I $(ARDUINOSRC)/../../variants/standard/

SRCCPP=$(call rwildcard, ../../src/, *.cpp) $(call rwildcard, $(ARDUINOSRC), *.cpp)
SRCC=$(call rwildcard, $(ARDUINOSRC), *.c)
OBJ=$(SRCCPP:.cpp=.o) $(SRCC:.c=.o)
DEST=../../bin/atmega328p/arduino.a
CCONSTANTS=-D__AVR_ATmega328p__ -DF_CPU=16000000UL
MMCU=-mmcu=atmega328p

oacl: $(OBJ)
	mkdir -p ../../bin/atmega328p/
	avr-ar rcsv $(DEST) $(OBJ)

%.o: %.cpp
	avr-gcc -c $(CCONSTANTS) $(MMCU) $^ $(INC) -Os -o $@

%.o: %.c
	avr-gcc -c $(CCONSTANTS) $(MMCU) $^ $(INC) -Os -o $@

clean:
	rm -f $(OBJ)

