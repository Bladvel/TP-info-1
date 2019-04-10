slib=libinfo1sound.a
SO=libinfo1sound.so
MAJOR=1
MINOR=0
PATCH=1
SONAME=$(SO).$(MAJOR)
dlib=$(SONAME).$(MINOR).$(PATCH)
CC=gcc
CFLAGS=-c -fPIC -g -Wall
LDFLAGS=-shared -Wl,-soname,$(SONAME) -lc -Wall
OBJS=sound-lib.o
DEPS=sound-lib.h
INSTALL_PATH=$(HOME)/Info1libs/
INSTALL_INC_PATH=$(HOME)/Info1includes/
STATICPATH=./estatica/
DYNAMICPATH=./dinamica/
SHAREDPATH=./dinamica/shared/
empty:
	@echo "Error"
	@echo "Invocar como make estática | dinámica | all"

all: preinstall clean dinamica estatica install
preinstall:
	install -d $(STATICPATH)
	install -d $(SHAREDPATH)
	cp sound-lib.c $(STATICPATH)
	cp sound-lib.h $(STATICPATH)
	cp sound-lib.c $(DYNAMICPATH)
	cp sound-lib.h $(DYNAMICPATH)
estatica: $(slib)
$(slib):$(STATICPATH)$(OBJS)
	ar rcs $(STATICPATH)$@ $<
%.o:%.c $(DEPS)
	$(CC) $(CFLAGS) -o $@ $<
dinamica: $(dlib)
$(dlib):$(DYNAMICPATH)$(OBJS)
	$(CC) $(LDFLAGS) -o $(SHAREDPATH)$@ $< 
	sudo ldconfig -n $(SHAREDPATH)
	ln -sfvn $(SONAME) $(SHAREDPATH)libsound.so
clean:
	rm -rf $(SHAREDPATH) $(STATICPATH) $(DYNAMICPATH)
new: clean preinstall all
install:
	install -d $(INSTALL_PATH)
	install -d $(INSTALL_INC_PATH)
	cp $(STATICPATH)$(slib) $(INSTALL_PATH)
	cp $(SHAREDPATH)$(dlib) $(INSTALL_PATH)
	sudo ldconfig -n $(INSTALL_PATH)
	ln -sfvn $(SONAME) $(INSTALL_PATH)libsound.so
	cp $(STATICPATH)$(DEPS) $(INSTALL_INC_PATH)
