# Recursive Wildcard Function
rwildcard=$(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2) $(filter $(subst *,%,$2),$d))

DEST=../../../../bin/Component/arduino/atmega2560/robotengine.a
 
SRCPATH=../../../../src/Component
SRCPATH2=../../../../src/Common
INC=-I ../../../../include/

CCONSTANTS=-D__AVR_ATmega2560__ -DF_CPU=16000000UL -DRE_PLATFORM_ARDUINO
MMCU=-mmcu=atmega2560

SRCC=$(call rwildcard, $(SRCPATH), *.c) $(call rwildcard, $(SRCPATH2), *.c)
SRCCPP=$(call rwildcard, $(SRCPATH), *.cpp) $(call rwildcard, $(SRCPATH2), *.cpp)
OBJ=$(SRCC:.c=.o) $(SRCCPP:.cpp=.o)

all: arduino clean

arduino: $(OBJ)
	mkdir -p ../../../../bin/Component/arduino/atmega2560/
	avr-ar rcsv $(DEST) $(OBJ)

%.o: %.cpp
	avr-gcc -c $(CCONSTANTS) $(MMCU) $^ $(INC) -Os -o $@

%.o: %.c
	avr-gcc -c $(CCONSTANTS) $(MMCU) $^ $(INC) -Os -o $@

clean:
	rm -f $(OBJ)

