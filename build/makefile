# Recursive Wildcard Function
rwildcard=$(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2) $(filter $(subst *,%,$2),$d))

OBJ=$(call rwildcard, ../, *.o)

all:
	cd Component && $(MAKE)
	cd Module && $(MAKE)

clean:
	rm -f $(OBJ)

mrproper: clean
	rm -rf ../bin

