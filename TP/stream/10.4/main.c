#include "myheader.h"

/*
*	write(int fildes, const void *buf, size_t nbytes)
*	read(int fildes, void *buf, size_t nbytes)*/

int main(int argc, char const *argv[])
{
	if (argv[1]==NULL)
	{
		printf("NO INDICO NINGUN ARCHIVO PARA ABRIR. ERROR\n");
		return (-1);
	}

	FILE* fd;
	if ((fd= fopen(argv[1],"r"))==NULL)
	{
		puts("error al abrir el archivo");
		return(-1);
	}
	stdoutprint(fd);

	fclose(fd);
	return 0;

}




