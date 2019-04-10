all: main
new: clean main
CC=gcc

CFLAGS=-g -c -I. -Wall
LDFLAGS=-g -Wall
OBJS=main.o myfunction.o
DEPS=myheader.h

main: $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@
%.o:%.c $(DEPS)
	$(CC) $(CFLAGS) $< -o $@
.PHONY: clean
clean:
	rm -f ./*.o
	rm -f main
new: clean main