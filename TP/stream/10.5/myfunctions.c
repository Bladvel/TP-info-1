#include "myheader.h"

void sepyconv (char* token[],double lista [], FILE* fd)
{
	int i=0;
	do
	{
		if((token[i]=(char*)malloc(20*sizeof(char)))==NULL)
		{
			puts("error al asignar memoria el archivo");
			break;
		}	

		if ((fgets(token[i],20,fd))==NULL)
			break;
			
		lista[i]=atof(token[i]);

	//	printf("lista[%d]=%lf\n",i,lista[i]);
		i++;
	}while (1);
}

double promedio (double lista[],int n)
{
	double suma=0;
	for (int i = 0; i < n; ++i)
		suma += lista[i];
	return suma/n;

}

double varianza (double lista[], int n, double prom)
{
	double suma=0;
	for (int i = 0; i < n; ++i)
		suma += pow(lista[i]-prom,2);
	return suma/(n-1); //En algunas formulas sale sin el -1, pero si lo omito me da un valor distinto que la comprobacion que hice en Excel
}
