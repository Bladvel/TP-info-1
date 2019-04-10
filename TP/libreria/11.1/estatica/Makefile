slib=libinfo1sock.a
CC=gcc
SCFLAGS=-c -g -Wall
OBJS=sock-lib.o
DEPS=sock-lib.h
DIRSTATIC=./static/
INSTALL_PATH=~/Info1libs/
INSTALL_INC_PATH=~/Info1includes/

empty:
	@echo "Error"
	@echo "Invocar como make estática"

all: estatica
estatica: $(slib)
$(slib):$(OBJS)
	ar rcs $(DIRSTATIC)$@ $(DIRSTATIC)$<
%.o:%.c $(DEPS)
	@mkdir static 2>/dev/null
	$(CC) $(SCFLAGS) $< -o $(DIRSTATIC)$@

clean:
	rm -f *.o *.a
	rm -rf $(DIRSTATIC)

install:
	install -d $(INSTALL_PATH)
	install -d $(INSTALL_INC_PATH)
	install $(slib) $(INSTALL_PATH)
	install *.h $(INSTALL_INC_PATH)
