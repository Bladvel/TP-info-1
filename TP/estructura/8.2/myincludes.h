/*
* \file mycinludes.h
* \brief Header para prueba del ejercicio 8.2
* \details Incluyo las librerias, las estructuras y los prototipos de funciones que 
*utilizare en este ejemplo.
* \Author Daniel Andres Jimenez Barnique e-mail: barnique2802@gmail.com
* \date 19.02.26
*/


#include <stdio.h>
#include <math.h>

/* 
* \struct z
* \details Define una estructura de tipo complejo que se compone de una parte real "x" y una parte imaginaria "y". Usamos del tipo
*float
*/

struct z
{
	float x;
	float y;
};

/*
* \var point
* \details Por medio de la sentencia typedef, creamos la variable complex
que es lo mismo que una estructura z.
*/

typedef struct z complex;


/*
* \fn void setcomplex (complex*)
* \brief Prototipo de funcion que define la componente real e imaginaria de un numero complejo
* \arg complex* Recibe por referencia una estructura de tipo complex
* \return No retorna por valor, sino que modifica los valores que apunta el complex* z 
* \Author Daniel Andres Jimenez Barnique e-mail: barnique2802@gmail.com
* \date 19.02.26
*/ 

void setcomplex (complex*);

/*
* \fn complex suma (complex*)
* \brief Prototipo de funcion que Calcula la suma de dos numeros complejos.
* \arg complex* Recibe por referencia una estructura de tipo complex
* \return estructura tipo complex
* \Author Daniel Andres Jimenez Barnique e-mail: barnique2802@gmail.com
* \date 19.02.26
*/

complex add (complex*, complex*);

/*
* \fn complex subt (complex*)
* \brief Prototipo de funcion que Calcula la resta de dos numeros complejos.
* \arg complex* Recibe por referencia 2 estructuras de tipo complex
* \return estructura tipo complex
* \Author Daniel Andres Jimenez Barnique e-mail: barnique2802@gmail.com
* \date 19.02.26
*/

complex subt (complex*, complex*);	

/*
* \fn complex subt (complex*)
* \brief Prototipo de funcion que Calcula la resta de dos numeros complejos.
* \arg complex* Recibe por referencia una estructura de tipo complex
* \return estructura tipo complex
* \Author Daniel Andres Jimenez Barnique e-mail: barnique2802@gmail.com
* \date 19.02.26
*/

complex mult (complex*, complex*);	

/*
* \fn void diag (rect*)
* \brief Prototipo de funcion que Calcula la diagonal de un rectangulo.
* \arg rect* Recibe por referencia una estructura de tipo rect
* \return No retorna por valor, sino que modifica el valor tipo "diag" que apunta el rect* r 
* \Author Daniel Andres Jimenez Barnique e-mail: barnique2802@gmail.com
* \date 19.02.26
*/

complex div (complex*, complex*);

/*
* \fn void descrect (rect*)
* \brief Prototipo de funcion que Inicializa un valor tipo "rect".
* \arg rect*bRecibe por referencia una estructura de tipo rect
* \return No retorna por valor, sino que inicializa todos los valores que apunta el rect* r
*dentro de su estructura 
* \Author Daniel Andres Jimenez Barnique e-mail: barnique2802@gmail.com
* \date 19.02.26
*/

complex conju (complex*);

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

void printcomplex (complex);

void menu (complex*,complex*,int);
