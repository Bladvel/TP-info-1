#include "myheader.h"


/*
*	write(int fildes, const void *buf, size_t nbytes)
*	read(int fildes, void *buf, size_t nbytes)*/

int main(int argc, char const *argv[])
{
	FILE* fd;
	char* token[LMAX];
	double lista[LMAX];

	if (argv[1]==NULL)
	{
		printf("NO INDICO NINGUN ARCHIVO PARA ABRIR. ERROR\n");
		return (-1);
	}

	
	if ((fd= fopen(argv[1],"r"))==NULL)
		puts("error al abrir el archivo");
	
	sepyconv(token,lista,fd);


	double prom,var;
	prom=promedio(lista,100);
	var=varianza(lista,100,prom);
	printf("Para los primeros 100 valores de la lista tenemos:\n");
	printf("promedio=%lf\nvarianza=%lf\n", prom,var);

	prom=promedio(lista,128);
	var=varianza(lista,128,prom);

	printf("Si tomamos todos valores de la lista tenemos:\n");
	printf("promedio=%lf\nvarianza=%lf\n", prom,var);
	fclose(fd);
	return 0;

}



/*#include <stdio.h>

int main () {
   FILE *fp;
   int c;

   fp = fopen("file.txt","r");
   while(1) {
      c = fgetc(fp);
      if( feof(fp) ) {
         break;
      }
      printf("%c", c);
   }
   fclose(fp);
   return(0);
}*/