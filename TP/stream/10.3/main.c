#include "myheader.h"
/*
*	write(int fildes, const void *buf, size_t nbytes)
*	read(int fildes, void *buf, size_t nbytes)*/

int main(int argc, char const *argv[])
{
	int fd;
	char buff[BUFSIZ];

	char* token[LMAX];
	double lista[LMAX];

	if (argv[1]==NULL)
	{
		printf("NO INDICO NINGUN ARCHIVO PARA ABRIR. ERROR\n");
		return (-1);
	}

	if ((fd= open(argv[1],O_RDWR,0))==-1)
	{
		write(1,"error al abrir el archivo",25);
		return (-1);
	}
	size_t nbytes;



	if ((nbytes= read(fd,buff,BUFSIZ))==-1)
	{
		write(1,"error al leer el archivo",25);
		return (-1);
	}
	
	sepyconv(token,lista,buff);
	//SEPARAMOS LA CADENA BUFF EN SUBCADENAS DE CARACTERES



	double prom,var;
	prom=promedio(lista,100);
	var=varianza(lista,100,prom);

	char *rprom, *rvar;
	rprom = (char*)malloc(25);
	rvar = (char*)malloc(25);

	sprintf(rprom,"Promedio: %lf\n",prom);
	sprintf(rvar, "varianza: %lf\n",var);

	write(1,"Para los primeros 100 valores de la lista tenemos:\n",51);
	write(1,rprom,strlen(rprom));
	write(1,rvar,strlen(rvar));

	write(1,"Si incluimos todos valores de la lista tenemos:\n",50);

	prom=promedio(lista,128);
	var=varianza(lista,128,prom);

	sprintf(rprom,"Promedio: %lf\n",prom);
	sprintf(rvar, "varianza: %lf\n",var);
	write(1,rprom,strlen(rprom));
	write(1,rvar,strlen(rvar));

	return 0;
}

	
