#include "myheader.h"

/*
*	write(int fildes, const void *buf, size_t nbytes)
*	read(int fildes, void *buf, size_t nbytes)*/

int main()
{
	int fd;
	char buff[BUFSIZ];
	if ((fd= open("main.c",O_RDWR,0))==-1)
	{
		write(2,"error al abrir el archivo",25);
		return (-1);	
	}
	size_t nbytes;
	if ((nbytes= read(fd,buff,BUFSIZ))==-1)
	{
		write(2,"error al leer el archivo",24);
		return (-1);	
	}

	write(1,buff,nbytes);
	return 0;
}