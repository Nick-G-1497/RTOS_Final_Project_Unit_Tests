UNAME=$(shell uname)

CCFLAGS=-Wall -O3 -std=gnu99 -c
CC=gcc



DEPS = ctest.h config_types.h config.h
OBJ = main.o shield_physics.o shield_physics_tests.o

all: shield_physics

shield_physics: $(OBJ) $(DEPS)
	$(CC) $(LDFLAGS) $(OBJ) -o shield_physics

remake: clean all

%.o: %.c $(DEPS)
	$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	rm -f shield_physics *.o
