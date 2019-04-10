INSTALL_INC_PATH=$(HOME)/Info1includes/
INSTALL_PATH=$(HOME)/Info1libs/
STATICPATH=./estatica/
DYNAMICPATH=./dinamica/
CC=gcc
CFLAGS=-c -fPIC -I$(INSTALL_INC_PATH) -g -Wall
LSFLAGS=-g -L$(INSTALL_PATH) -linfo1sock -lc -Wall
LDFLAGS=-g -Wl,-R$(INSTALL_PATH) -Wl,--enable-new-dtags -L$(INSTALL_PATH) -lsock -Wall
#LDFLAGS=-g -L$(INSTALL_PATH) -lsock -Wall
OBJ1=client.o
OBJ2=server.o
DEPS=sock-lib.h

empty:.......
	@echo "Error"
	@echo "Invocar como make clientdynamic | serverstatic | serverdynamic| clientstatic"
	@echo "Si es la primera vez, invocar como make new"
clientstatic:$(OBJ1)
	$(CC) -o $@ $< $(LSFLAGS)
clientdynamic:$(OBJ1)
	$(CC) -o $@ $< $(LDFLAGS)
serverstatic:$(OBJ2)
	$(CC) -o $@ $< $(LSFLAGS)
serverdynamic:$(OBJ2)
	$(CC) -o $@ $< $(LDFLAGS)
%.o:%.c $(DEPS)
	$(CC) -o $@ $< $(CFLAGS)
new: clean clientstatic clientdynamic serverstatic serverdynamic install
clean:
	rm -rf ./obj/ $(STATICPATH) $(DYNAMICPATH)
install:
	install -d ./obj/ $(STATICPATH) $(DYNAMICPATH)
	mv -t ./obj/ *.o 
	mv -t $(STATICPATH) *static
	mv -t $(DYNAMICPATH) *dynamic