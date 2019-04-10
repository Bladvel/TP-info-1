all: main

CC=gcc

CFLAGS=-g -c -O0 -Wall
LDFLAGS=-g -lm -Wall
OBJS=main.o myfunctions.o

main: $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)
%.o:%.c
	$(CC) $(CFLAGS) $< -o $@
.PHONY: clean
clean:
	rm -f ./*.o
	rm -f main
new: clean main