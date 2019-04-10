#include "myheader.h"
/*
*	write(int fildes, const void *buf, size_t nbytes)
*	read(int fildes, void *buf, size_t nbytes)*/

int main(int argc, char const *argv[])
{
	int fd;
	char buff[BUFSIZ];

	if (argv[1]==NULL)
	{
		write(2,"NO INDICO NINGUN ARCHIVO PARA ABRIR. ERROR",42);
		return (-1);
	}
		
	if ((fd= open(argv[1],O_RDWR,0))==-1)
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