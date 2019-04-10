/*
* \file funciones.c
* \brief Archivo de funciones para prueba del ejercicio 8.1
* \Para compilar < gcc -c -g funciones.c -Wall > 
* \Author Daniel Andres Jimenez Barnique e-mail: barnique2802@gmail.com
* \date 19.02.26
*/



#include "myincludes.h"

/*
* \fn void setpoint (point*)
* \brief Asigna valores para un punto de dos dimensiones
* \details Pide al usuario el valor que guardara en cada punto de una coordenada y lo almacena.
* \arg Recibe por referencia una estructura de tipo point
* \return No retorna por valor, sino que modifica los valores que apunta el point* p 
* \Author Daniel Andres Jimenez Barnique e-mail: barnique2802@gmail.com
* \date 19.02.26
*/

void setpoint (point* p)
{

	printf("\nPor favor introduzca la coordenada x:\t");
	scanf("%f",&p->x);
	printf("\nPor favor introduzca la coordenada y:\t");
	scanf("%f",&p->y);
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

void base (rect* r)
{
	r->base = fabs(r->p1.x - r->p2.x);
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

void height (rect* r)
{
	r->height = fabs(r->p1.y - r->p2.y);
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

void area (rect* r)
{
	r->area = (r->base)*(r->height);
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

void diag (rect* r)
{
	r->diag = sqrtf((r->base)*(r->base)+(r->height)*(r->height));
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

void descrect(rect* r)
{
	printf("\nEscribe las coordenadas de un punto de dos dimensiones");
	setpoint(&(r->p1));
	printf("\nEscribe las coordenadas de otro punto de dos dimensiones");
	setpoint(&(r->p2));
	base(r);
	height(r);
	area(r);
	diag(r);
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

void printrect(rect r)
{
	printf("\nPuntos escogidos para armar un rectangulo:\nP1=(%.2f,%.2f)\tP2=(%.2f,%.2f)",r.p1.x,r.p1.y,r.p2.x,r.p2.y);
	printf("\nBase: %.2f \tAltura: %.2f",r.base,r.height);
	printf("\nArea: %.2f",r.area);
	printf("\nDiagonal: %.2f\n",r.diag);
}