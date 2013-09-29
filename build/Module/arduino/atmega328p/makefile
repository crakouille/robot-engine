# Recursive Wildcard Function
rwildcard=$(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2) $(filter $(subst *,%,$2),$d))

DEST=../../../../bin/Module/arduino/atmega328p/robotengine.a
 
SRCPATH=../../../../src/Module
SRCPATH2=../../../../src/Common
INC=-I ../../../../include/

CCONSTANTS=-D__AVR_ATmega328p__ -DF_CPU=16000000UL -DRE_PLATFORM_ARDUINO
MMCU=-mmcu=atmega328p

SRCC=$(call rwildcard, $(SRCPATH), *.c) $(call rwildcard, $(SRCPATH2), *.c)
SRCCPP=$(call rwildcard, $(SRCPATH), *.cpp) $(call rwildcard, $(SRCPATH2), *.cpp)
OBJ=$(SRCC:.c=.o) $(SRCCPP:.cpp=.o)

all: arduino clean

arduino: $(OBJ)
	mkdir -p ../../../../bin/Module/arduino/atmega328p/
	avr-ar rcsv $(DEST) $(OBJ)

%.o: %.cpp
	avr-gcc -c $(CCONSTANTS) $(MMCU) $^ $(INC) -Os -o $@

%.o: %.c
	avr-gcc -c $(CCONSTANTS) $(MMCU) $^ $(INC) -Os -o $@

clean:
	rm -f $(OBJ)

