# Recursive Wildcard Function
rwildcard=$(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2) $(filter $(subst *,%,$2),$d))

DEST=../../../bin/Component/linux/robotengine.a
 
SRCPATH=../../../src/Component
SRCPATH2=../../../src/Common
INC=-I ../../../include/

CCONSTANTS=-std=gnu++11 -DRE_PLATFORM_LINUX

SRCC=$(call rwildcard, $(SRCPATH), *.c) $(call rwildcard, $(SRCPATH2), *.c)
SRCCPP=$(call rwildcard, $(SRCPATH), *.cpp) $(call rwildcard, $(SRCPATH2), *.cpp)
OBJ=$(SRCC:.c=.o) $(SRCCPP:.cpp=.o)

all: linux clean

linux: $(OBJ)
	mkdir -p ../../../bin/Component/linux/
	ar -rv $(DEST) $(OBJ)

%.o: %.cpp
	gcc -c $(CCONSTANTS) $^ $(INC) -Os -o $@

%.o: %.c
	gcc -c $(CCONSTANTS) $^ $(INC) -Os -o $@

clean:
	rm -f $(OBJ)

