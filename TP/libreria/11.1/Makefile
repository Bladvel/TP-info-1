slib=libinfo1sock.a
SO=libinfo1sock.so
MAJOR=1
MINOR=0
PATCH=1
SONAME=$(SO).$(MAJOR)
dlib=$(SONAME).$(MINOR).$(PATCH)
STATICPATH=./estatica/
DYNAMICPATH=./dinamica/
SHAREDPATH=./dinamica/shared/
CC=gcc
CFLAGS=-c -fPIC -g -Wall
LDFLAGS=-shared -Wl,-soname,$(SONAME) -lc -Wall
OBJS=sock-lib.o
DEPS=sock-lib.h


INSTALL_PATH=$(HOME)/Info1libs/
INSTALL_INC_PATH=$(HOME)/Info1includes/
empty:.......
	@echo "Error"
	@echo "Invocar como make estatica | dinamica | all"
all: dinamica estatica
estatica: $(slib)
$(slib):$(STATICPATH)$(OBJS)
	ar rcs $(STATICPATH)$@ $<
%.o:%.c $(DEPS)
	$(CC) $(CFLAGS) -o $@ $<
dinamica: $(dlib)
$(dlib):$(DYNAMICPATH)$(OBJS)
	@mkdir $(SHAREDPATH) 2>/dev/null
	$(CC) $(LDFLAGS) -o $(SHAREDPATH)$@ $< 
	sudo ldconfig -n $(SHAREDPATH)
	ln -sfvn $(SONAME) $(SHAREDPATH)libsock.so
clean:
	rm -f $(STATICPATH)*.o $(STATICPATH)*.a
	rm -f $(DYNAMICPATH)*.o
	rm -rf $(SHAREDPATH)
new: clean all
install:
	install -d $(INSTALL_PATH)
	install -d $(INSTALL_INC_PATH)
	cp $(STATICPATH)$(slib) $(INSTALL_PATH)
	cp $(SHAREDPATH)$(dlib) $(INSTALL_PATH)
	sudo ldconfig -n $(INSTALL_PATH)
	ln -sfvn $(SONAME) $(INSTALL_PATH)libsock.so
	cp $(STATICPATH)$(DEPS) $(INSTALL_INC_PATH)