/*
* \file main.c
* \brief Programa principal para prueba del ejercicio 8.1
* \return 0 si termino OK
* \Para compilar < gcc -c -g main.c -Wall >
* \Para linkear < gcc -g main.o funciones.o -o main -Wall -lm > 
* \Author Daniel Andres Jimenez Barnique e-mail: barnique2802@gmail.com
* \date 19.02.26
*/


#include "myincludes.h"

int main()
{
	rect r;
	descrect(&r);
	printrect(r);
	return 0;
}

