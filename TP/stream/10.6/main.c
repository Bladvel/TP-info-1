#include "myheader.h"

int main(int argc, char const *argv[])
{
	int n, o;
	

	if (argv[1]==NULL)
	{
		puts("NO INTRODUJO EL NUMERO DE PUNTOS. ERROR");
		return (-1);
	}
		
	n=atoi(argv[1]);

	point *arreglop[n];
	setpoint(arreglop,n);

	FILE* fd;
	if ((fd= fopen("puntos.dp","w+"))==NULL)
	{
		puts("error al crear el archivo");
		return (-1);
	}
	printpoint(arreglop,n,fd);
	rewind(fd);

	do
	{
		printf("\nSeleccione que operacion desea realizar:\nImprimir en pantalla el archivo (0)\nOrdenar los puntos por su coordenada x (1)\n");
		scanf("%d",&o);
	}while (!(o== 0 || o ==1));

	menu(fd,o,arreglop,n);

	fclose(fd);
	
	
	return 0;
}