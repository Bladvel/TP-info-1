#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct p
{
	double x;
	double y;
}point;

/*
* \var point
* \details Por medio de la sentencia typedef, creamos la variable point 
que es lo mismo que una estructura p.
*/



/*
* \fn void setpoint (point*)
* \brief Prototipo de funcion que Asigna valores para un punto de dos dimensiones
* \arg point* Recibe por referencia una estructura de tipo point
* \return No retorna por valor, sino que modifica los valores que apunta el point* p 
* \Author Daniel Andres Jimenez Barnique e-mail: barnique2802@gmail.com
* \date 19.02.26
*/ 

void setpoint (point* p[],int);


/*
* \fn void printrect (rect)
* \brief Prototipo de funcion que Imprime un pantalla todos los valores de un elemento tipo "rect"
* \arg rect Recibe por valor una estructura de tipo rect
* \return No devuelve nada. Solo imprime en pantalla su resultado
* \Author Daniel Andres Jimenez Barnique e-mail: barnique2802@gmail.com
* \date 19.02.26
*/

void printpoint (point *p[],int,FILE*); //Presenta en pantalla los datos punto


void stdoutprint (FILE* fd);

void swap (point* a, point* b);

void sort(point* p[], int n);

void menu (FILE*,int,point* p[],int);