all: main

CC=gcc

CFLAGS=-g -c -O0 -Wall
LDFLAGS=-g -Wall
OBJS=main.o 

main: $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@
%.o:%.c
	$(CC) $(CFLAGS) $< -o $@
.PHONY: clean
clean:
	rm -f ./*.o
	rm -f main
new: clean main