/*
* \file main.c
* \brief Programa principal para prueba del ejercicio 8.2
* \return 0 si termino OK
* \Para compilar < gcc -c -g main.c -Wall >
* \Para linkear < gcc -g main.o funciones.o -o main -Wall > 
* \Author Daniel Andres Jimenez Barnique e-mail: barnique2802@gmail.com
* \date 19.02.26
*/


#include "myincludes.h"

int main()
{
	complex z1,z2;
	int n;
	printf("\nIntroduzca un numero complejo en representacion binomica");
	setcomplex(&z1);
	printf("\nIntroduzca otro numero complejo en representacion binomica");
	setcomplex(&z2);
	do
	{
		printf("\nSeleccione que operacion desea realizar:\nSuma (0)\tResta (1)\tMultiplicacion (2)\nDivision (3)\tConjugada (4)\n");
		scanf("%d",&n);
	}while (!(n>= 0 && n <=4));
	menu(&z1,&z2,n);
	return 0;
}

