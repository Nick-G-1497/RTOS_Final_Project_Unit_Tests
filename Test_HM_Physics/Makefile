UNAME=$(shell uname)

CCFLAGS=-Wall -O3 -std=gnu99 -c 
CC=gcc



DEPS = ctest.h config_types.h config.h
OBJ = main.o hm_physics.o hm_physics_tests.o

all: hm_physics

hm_physics: $(OBJ) $(DEPS)
	$(CC) $(LDFLAGS) $(OBJ) -o hm_physics -lm 

remake: clean all

%.o: %.c $(DEPS)
	$(CC) $(CCFLAGS) -c -o $@ $< -lm 

clean:
	rm -f hm_physics *.o
