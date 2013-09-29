# Recursive Wildcard Function
rwildcard=$(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2) $(filter $(subst *,%,$2),$d))

INC=-I ../../../../../include/

SRC=$(call rwildcard, ../src/, *.cpp) $(call rwildcard, ../src/, *.c) \
../../../../../src/Utils/LinuxToArduino/LTACommunicationDriver.cpp \
../../../../../src/Utils/LinuxToArduino/Module.cpp
LIBS=../../../../../bin/robotengine.component.linux.a ../../../../../bin/robotengine.module.linux.a

all: compile

compile:
	g++ -std=gnu++11 -o example -DRE_PLATFORM_LINUX $(SRC) $(INC) $(LIBS)

clean:
	rm example

