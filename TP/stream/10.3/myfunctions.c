#include "myheader.h"


void sepyconv (char* token[],double lista [],char buff[BUFSIZ])
{
	const char s[2] = "\n";
	int i=0;
	token[0] = strtok(buff, s);
	

	while(token[i])
	{
		//printf("token[%d]=%s\n",i,token[i] );
		lista[i]=atof(token[i]);
		i++;
		token[i]=token[i-1];
		token[i]=strtok(NULL,s);
		

	}
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

