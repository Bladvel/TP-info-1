CC=gcc

OBJS=server.o
OBJC=client.o
DEPS=sock-lib.h
LIB_PATH=$(HOME)/Info1libs/
INC_PATH=$(HOME)/Info1includes/
CFLAGS=-c -fPIC -g -I$(INC_PATH) -Wall
LFLAGS= -g -Wl,-R$(LIB_PATH) -Wl,--enable-new-dtags -L$(LIB_PATH) -lsock -Wall


all: client server

client: $(OBJC)
	$(CC) $< -o $@ $(LFLAGS)
server: $(OBJS)
	$(CC) $< -o $@ $(LFLAGS)
%.o:%.c $(DEPS)
	$(CC) $< $(CFLAGS) -o $@ 
clean:
	rm -f *.o *.a client server
new: clean all

