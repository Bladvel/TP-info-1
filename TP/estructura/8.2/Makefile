all: main

CC=gcc

CFLAGS=-g -c -O0 -Wall
LDFLAGS=-g -lm -Wall
OBJS=main.o myfunctions.o
DEPS= myincludes.h

main: $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)
%.o:%.c $(DEPS)
	$(CC) $(CFLAGS) $< -o $@
.PHONY: clean
clean:
	rm -f ./*.o
	rm -f main myfunctions
new: clean main
