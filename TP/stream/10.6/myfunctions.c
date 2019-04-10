#include "myheader.h"

/*
* \fn void setpoint (point*)
* \brief Asigna valores para un punto de dos dimensiones
* \details Pide al usuario el valor que guardara en cada punto de una coordenada y lo almacena.
* \arg Recibe por referencia una estructura de tipo point
* \return No retorna por valor, sino que modifica los valores que apunta el point* p 
* \Author Daniel Andres Jimenez Barnique e-mail: barnique2802@gmail.com
* \date 19.02.26
*/

void setpoint (point* p[],int n)
{
	for (int i = 0; i < n; ++i)
	{
		if((p[i]=(point*)malloc(sizeof(point)))==NULL)
		{
			puts("error al asignar memoria el archivo");
			return;
		}	
		printf("\nPor favor introduzca la coordenada %dx:\t",i+1);
		scanf("%lf",&p[i]->x);
		printf("\nPor favor introduzca la coordenada %dy:\t",i+1);
		scanf("%lf",&p[i]->y);
		
	}
	
}

void printpoint (point* p[],int n, FILE* fd)
{
	for (int i = 0; i < n; ++i)
	{
		//printf("P%d=(%lf,%lf)\n",i+1,p[i]->x,p[i]->y );
		fprintf(fd,"P%d=(%lf,%lf)\n",i+1,p[i]->x,p[i]->y);
	}
}

void stdoutprint (FILE* fd)
{	
	char c;
	while (1)
	{
		c = fgetc(fd);
		if (feof(fd))
			break;
		printf("%c",c);
	}

}

void swap (point* a, point* b)
{
	point* aux=(point*)malloc(sizeof(point));
	aux->x = a->x;
	a->x = b->x;
	b->x = aux->x;

}

void sort(point* p[], int n)
{
	for (int i = n-1; i > 0; i--)
		for (int j = 0; j < i;j++)
			if (p[j]->x > p[j+1]->x)
				swap(p[j], p[j+1]);
}

void menu(FILE* fd, int o, point* p[],int n)
{
	switch (o)
	{
		case 0:
			printf("\nLos valores guardados en el archivo son:\n");
			stdoutprint(fd);
			break;

		case 1:
			printf("\nLos valores guardados sin ordenar en el archivo son:\n");
			stdoutprint(fd);
			rewind(fd);
			sort(p,n);
			printpoint(p,n,fd);
			rewind(fd);
			printf("\nLos valores guardados ya ordenados en el archivo son:\n");
			stdoutprint(fd);

			break;
	}
}