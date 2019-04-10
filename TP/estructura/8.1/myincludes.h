/*
* \file mycinludes.h
* \brief Header para prueba del ejercicio 8.1
* \details Incluyo las librerias, las estructuras y los prototipos de funciones que 
*utilizare en este ejemplo.
* \Author Daniel Andres Jimenez Barnique e-mail: barnique2802@gmail.com
* \date 19.02.26
*/


#include <stdio.h>
#include <math.h>

/* 
* \struct p
* \details Define una estructura de tipo punto que se compone de dos coordenadas x e y. Usamos del tipo
*float
*/

struct p
{
	float x;
	float y;
};

/*
* \var point
* \details Por medio de la sentencia typedef, creamos la variable point 
que es lo mismo que una estructura p.
*/

typedef struct p point;

/* 
* \struct r
* \details Define una estructura de tipo r que se compone de dos puntos que definen a un rectangulo. 
*Cada punto es del tipo "point". Ademas guarda datos derivados de los dos puntos, como su base, altura, 
*area y diagonal. Almacenados como datos tipo "float".
*/

struct r
{
	point p1;
	point p2;
	float base;
	float height;
	float area;
	float diag;
};

/*
* \var rect
* \details Por medio de la sentencia typedef, creamos la variable rect 
que es lo mismo que una estructura r.
*/

typedef struct r rect;


/*
* \fn void setpoint (point*)
* \brief Prototipo de funcion que Asigna valores para un punto de dos dimensiones
* \arg point* Recibe por referencia una estructura de tipo point
* \return No retorna por valor, sino que modifica los valores que apunta el point* p 
* \Author Daniel Andres Jimenez Barnique e-mail: barnique2802@gmail.com
* \date 19.02.26
*/ 

void setpoint (point*);

/*
* \fn void base (rect*)
* \brief Prototipo de funcion que Calcula la base de un rectangulo
* \arg rect* Recibe por referencia una estructura de tipo rect
* \return No retorna por valor, sino que modifica el valor tipo "base" que apunta rect* r 
* \Author Daniel Andres Jimenez Barnique e-mail: barnique2802@gmail.com
* \date 19.02.26
*/

void base (rect*);

/*
* \fn void height (rect*)
* \brief Prototipo de funcion que Calcula la altura de un rectangulo.
* \arg rect* Recibe por referencia una estructura de tipo rect
* \return No retorna por valor, sino que modifica el valor tipo "height" que apunta rect* r 
* \Author Daniel Andres Jimenez Barnique e-mail: barnique2802@gmail.com
* \date 19.02.26
*/

void height(rect*);	

/*
* \fn void area (rect*)
* \brief Prototipo de funcion que Calcula el area de un rectangulo
* \arg rect* Recibe por referencia una estructura de tipo rect
* \return No retorna por valor, sino que modifica el valor tipo "area" que apunta el rect* r 
* \Author Daniel Andres Jimenez Barnique e-mail: barnique2802@gmail.com
* \date 19.02.26
*/

void area (rect*);

/*
* \fn void diag (rect*)
* \brief Prototipo de funcion que Calcula la diagonal de un rectangulo.
* \arg rect* Recibe por referencia una estructura de tipo rect
* \return No retorna por valor, sino que modifica el valor tipo "diag" que apunta el rect* r 
* \Author Daniel Andres Jimenez Barnique e-mail: barnique2802@gmail.com
* \date 19.02.26
*/

void diag (rect*); 

/*
* \fn void descrect (rect*)
* \brief Prototipo de funcion que Inicializa un valor tipo "rect".
* \arg rect*bRecibe por referencia una estructura de tipo rect
* \return No retorna por valor, sino que inicializa todos los valores que apunta el rect* r
*dentro de su estructura 
* \Author Daniel Andres Jimenez Barnique e-mail: barnique2802@gmail.com
* \date 19.02.26
*/

void descrect (rect*); 

/*
* \fn void printrect (rect)
* \brief Prototipo de funcion que Imprime un pantalla todos los valores de un elemento tipo "rect"
* \arg rect Recibe por valor una estructura de tipo rect
* \return No devuelve nada. Solo imprime en pantalla su resultado
* \Author Daniel Andres Jimenez Barnique e-mail: barnique2802@gmail.com
* \date 19.02.26
*/

void printrect (rect); //Presenta en pantalla los datos del rectangulo.