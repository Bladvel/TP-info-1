slib=libinfo1sound.a
SO=libinfo1sound.so
INSTALL_INC_PATH=$(HOME)/Info1includes/
INSTALL_PATH=$(HOME)/Info1libs/
STATICPATH=./estatica/
DYNAMICPATH=./dinamica/
CC=gcc
CFLAGS=-c -fPIC -I$(INSTALL_INC_PATH) -g -Wall
LSFLAGS=-g -L$(INSTALL_PATH) -linfo1sound -lc -Wall
LDFLAGS=-g -Wl,-R$(INSTALL_PATH) -Wl,--enable-new-dtags -L$(INSTALL_PATH) -lsound -Wall
OBJ1=sound.o
DEPS=sock-lib.h sound-lib.h

empty:.......
	@echo "Error"
	@echo "Invocar como make new | sounddynamic | soundstatic"
soundstatic:$(OBJ1)
	$(CC) -o $@ $< $(LSFLAGS)
sounddynamic:$(OBJ1)
	$(CC) -o $@ $< $(LDFLAGS)
%.o:%.c $(DEPS)
	$(CC) -o $@ $< $(CFLAGS)
new: clean soundstatic sounddynamic install
clean:
	rm -rf ./obj/ $(STATICPATH) $(DYNAMICPATH)
install:
	install -d ./obj/ $(STATICPATH) $(DYNAMICPATH)
	mv -t ./obj/ *.o 
	mv -t $(STATICPATH) *static
	mv -t $(DYNAMICPATH) *dynamic