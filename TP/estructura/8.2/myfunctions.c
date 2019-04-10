/*
* \file funciones.c
* \brief Archivo de funciones para prueba del ejercicio 8.2
* \Para compilar < gcc -c -g funciones.c -Wall > 
* \Author Daniel Andres Jimenez Barnique e-mail: barnique2802@gmail.com
* \date 19.02.26
*/



#include "myincludes.h"

/*
* \fn void setcomplex (complex*)
* \brief Asigna valores para un punto de dos dimensiones
* \details Pide al usuario el valor que guardara en cada punto de una coordenada y lo almacena.
* \arg Recibe por referencia una estructura de tipo point
* \return No retorna por valor, sino que modifica los valores que apunta el point* p 
* \Author Daniel Andres Jimenez Barnique e-mail: barnique2802@gmail.com
* \date 19.02.26
*/

void setcomplex (complex* z)
{

	printf("\nPor favor introduzca la parte real:\t");
	scanf("%f",&z->x);
	printf("\nPor favor introduzca la parte imaginaria:\t");
	scanf("%f",&z->y);
}

/*
* \fn void base (rect*)
* \brief Calcula la base de un rectangulo
* \details Dado la coordenada "X" de dos puntos distintos, calcula el tamano de la base de 
*un rectangulo formado por ambos, y debido a que es una magnitud, utilizamos la funcion "fabs" 
*(encontrada cmath.h) para obtener su valor absoluto.
* \arg Recibe por referencia una estructura de tipo rect
* \return No retorna por valor, sino que modifica el valor tipo "base" que apunta rect* r 
* \Author Daniel Andres Jimenez Barnique e-mail: barnique2802@gmail.com
* \date 19.02.26
*/

complex add (complex* z1, complex* z2)
{
	complex temp;
	temp.x = z1->x + z2->x;
	temp.y = z1->y + z2->y;
	return temp;
}

/*
* \fn void height (rect*)
* \brief Calcula la altura de un rectangulo.
* \details Dado la coordenada "Y" de dos puntos distintos, calcula el tamano de la altura de 
*un rectangulo formado por ambos, y debido a que es una magnitud, utilizamos la funcion "fabs" 
*(encontrada math.h) para obtener su valor absoluto.
* \arg Recibe por referencia una estructura de tipo rect
* \return No retorna por valor, sino que modifica el valor tipo "height" que apunta rect* r 
* \Author Daniel Andres Jimenez Barnique e-mail: barnique2802@gmail.com
* \date 19.02.26
*/

complex subt (complex* z1, complex* z2)
{
	complex temp;
	temp.x = z1->x - z2->x;
	temp.y = z1->y - z2->y;
	return temp;
}

/*
* \fn void area (rect*)
* \brief Calcula el area de un rectangulo
* \details Dada la base (b) y la altura (h) de un rectangulo se calcula el tamano de su area (a)
*siguiendo: a = b*h.
* \arg Recibe por referencia una estructura de tipo rect
* \return No retorna por valor, sino que modifica el valor tipo "area" que apunta el rect* r 
* \Author Daniel Andres Jimenez Barnique e-mail: barnique2802@gmail.com
* \date 19.02.26
*/

complex mult (complex* z1, complex* z2)
{
	complex temp;
	temp.x = (z1->x)*(z2->x) - (z1->y)*(z2->y);
	temp.y = (z1->x)*(z2->y) + (z1->y)*(z2->x);
	return temp;
}

/*
* \fn void diag (rect*)
* \brief Calcula la diagonal de un rectangulo
* \details Dada la base (b) y la altura (h) de un rectangulo se calcula el tamano de su diagonal (d)
*siguiendo el teorema de pitagoras: d = (b^2 + h^2)^(1/2). Utilizamos la funcion "sqrtf" encontrada
*en math.h).
* \arg Recibe por referencia una estructura de tipo rect
* \return No retorna por valor, sino que modifica el valor tipo "diag" que apunta el rect* r 
* \Author Daniel Andres Jimenez Barnique e-mail: barnique2802@gmail.com
* \date 19.02.26
*/

complex div (complex* z1, complex* z2)
{
	complex temp;
	temp.x = ((z1->x)*(z2->x) + (z1->y)*(z2->y))/((z2->x)*(z2->x)+(z2->y)*(z2->y));
	temp.y = ((z1->y)*(z2->x) - (z1->x)*(z2->y))/((z2->x)*(z2->x)+(z2->y)*(z2->y));
	return temp;
}


/*
* \fn void descrect (rect*)
* \brief Inicializa un valor tipo "rect"
* \details Pide al usuario que escriba las coordenadas dos puntos de dos dimensiones y con
*eso, define un rectangulo, utilizando las funciones "setpoint", "base", "height", "area"
*y "diagonal".
* \arg Recibe por referencia una estructura de tipo rect
* \return No retorna por valor, sino que inicializa todos los valores que apunta el rect* r
*dentro de su estructura 
* \Author Daniel Andres Jimenez Barnique e-mail: barnique2802@gmail.com
* \date 19.02.26
*/

complex conju (complex* z)
{
	complex temp;
	temp.x = z->x;
	temp.y = -(z->y);
	return temp;
}

/*
* \fn void printrect (rect)
* \brief Imprime un pantalla todos los valores de un elemento tipo "rect"
* \details Muestra en pantalla (a traves de "printf") los valores (p1,p2,base,altura,area,diagonal) de un elemento 
*tipo "rect" incializado anteriormente.
* \arg Recibe por valor una estructura de tipo rect
* \return No devuelve nada. Solo imprime en pantalla su resultado
* \Author Daniel Andres Jimenez Barnique e-mail: barnique2802@gmail.com
* \date 19.02.26
*/

void printcomplex(complex z)
{
	printf("\nParte real:\t%.2f\nParte imaginaria:\t%.2f\n",z.x,z.y);
}

void menu(complex* z1, complex* z2, int n)
{
	complex resultado1;
	complex resultado2;

	switch (n)
	{
		case 0: 
			resultado1 = add (z1,z2);
			puts("Resultado de la Suma:");
			printcomplex(resultado1);
			break;
		case 1:
			resultado1 = subt (z1,z2);
			puts("Resultado de la Resta (z1 - z2):");
			printcomplex(resultado1);
			break;
		case 2:
			resultado1 = mult (z1,z2);
			puts("Resultado de la multiplicacion:");
			printcomplex(resultado1);
			break;
		case 3:
			if (((z2->x) == 0) && ((z2->y)==0))
			{
				puts ("No se puede realizar la division porque el denominador es 0");
				break;
			}
			else
			{
				resultado1 = div (z1,z2);
				puts("Resultado de la division z1/z2:");
				printcomplex(resultado1);
				break;
			}
		case 4:
			resultado1 = conju (z1);
			resultado2 = conju (z2);
			puts ("Conjugada de z1:");
			printcomplex (resultado1);
			puts ("Conjugada de z2:");
			printcomplex (resultado2);
			break;

	}

}
