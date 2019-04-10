/*
* \file myfunctions.c
* \brief Archivo de funciones para prueba del ejercicio 8.3
* \Para compilar < gcc -c -g funciones.c -Wall > 
* \Author Daniel Andres Jimenez Barnique e-mail: barnique2802@gmail.com
* \date 19.02.26
*/

#include "myheader.h"

/*
* \fn void printime (time_t *, struct tm* ,char *) 
* \brief Imprime en pantalla la fecha y hora actual, y la cantidad de segundos que han pasado en Tiempo Unix
* \details Haciendo uso de las funciones definidas en la cabecera time.h (time,localtime y strftime), obtiene la cantidad de segundos que han pasado desde Epoch,
*		   los guarda en una estructura tm y formatea los datos dentro de una string. Esta se presentara en pantalla al usuario.
* \arg time_t *mytime Variable creada en el main de tipo time_t (tipo de dato definido en el header time.h) para almacenar los segundos que han pasado desde Epoch (01-01-1970)
* \arg struct tm* pt En esta estructura definida en time.h se almacena el tiempo de manera formateada segun dicha estructura
* \arg char actualdate[] Aqui se guarda en forma de string la fecha y hora formateada
* \return No retorna por valor. Imprime en pantalla la fecha y hora obtenida. Y guarda los valores en las variables que recibio
* \Author Daniel Andres Jimenez Barnique e-mail: barnique2802@gmail.com
* \date 19.02.26
*/

void printime(time_t *mytime, struct tm* pt,char actualdate[]) 
{
	time(mytime);											//Guarda la cantidad de segundos que han pasado en tiempo Unix(01/01/1970) en mytime
	pt = localtime (mytime); 								//Llena de datos la estructura del puntero usando los segundos dados por time()
	strftime(actualdate,BUFFER_size,"%d:%m:%Y %H:%M:%S",pt);/*Aqui se guarda en actualdate, la fecha y hora siguiendo el formato dado en su tercer campo
															 *Obtiene los valores a formatear de pt
															 *	"%d" indica dia de mes (01-31) 
															 *	"%m" indica mes en decimal (01-12)
															 *	"%Y" indica el a~no en 4 digitos
															 *	"%H" indica hora (0-23)
															 *	"%M" indica minutos (0-59)
															 *	"%S" indica segundos (00-60)
															 *BUFFER_size es una constante global para indicar el tama~no maximo que tendra el string
															*/
	printf("FECHA Y HORA ACTUAL:\t%s\nsegundos de mytime: %ld\n",actualdate,*mytime);

}

/*
* \fn void getusertime(time_t* ,struct tm *,char *)
* \brief Imprime en pantalla la fecha y hora dada por el usuario, y la cantidad de segundos que han pasado en Tiempo Unix hasta dicha fecha
* \details Esta funcion hace lo inverso que printime: Recibe una fecha y hora formateada en forma de diversos valores long individuales para cada dato dada por el usuario,
*		   ellos son almacenados manualmente dentro de una estructura tm, y finalmente son guardados en el formato querido dentro de una string. 
*		   Adicional a las funciones anteriores, se hace uso de mktime() para convertir los datos guardados en la estructura tm a la cantidad de segundos que han pasado 
*		   desde el Epoch hasta esa fecha.
* \arg time_t *usertime Variable creada en el main de tipo time_t (tipo de dato definido en el header time.h) para almacenar 
						los segundos que han pasado desde Epoch (01-01-1970) hasta la fecha introducida por el usuario.
* \arg struct tm* ptuser En esta estructura definida en time.h se almacena el tiempo de manera formateada segun dicha estructura.
* \arg char userdate[] Aqui se guarda en forma de string la fecha y hora formateada.
* \return No retorna por valor. Imprime en pantalla la fecha y hora obtenida. Y guarda los valores en las variables que recibio.
* \Author Daniel Andres Jimenez Barnique e-mail: barnique2802@gmail.com
* \date 19.02.26
*/

void getusertime(time_t* usertime,struct tm *ptuser,char userdate[])
{
	long uday,umonth,uyear,uhour,umin,usec;
	printf("Introduzca alguna fecha y hora en formato \"dd:mm:yyyy hh:mm:ss\" (respetando los espacios)\n");
	scanf("%ld:%ld:%ld %ld:%ld:%ld",&uday,&umonth,&uyear,&uhour,&umin,&usec);
//ASIGNACION DE ESTRUCTURA TM DEL USUARIO
	ptuser->tm_sec = usec;        
  	ptuser->tm_min = umin;                
  	ptuser->tm_hour = uhour;                     
 	ptuser->tm_mday = uday;         
 	ptuser->tm_mon = umonth - 1;			//El rango de mes es de 0-11            
  	ptuser->tm_year = uyear - 1900;			//Numero de a~nos desde 1900

//VERIFICACION
	strftime(userdate,BUFFER_size,"%d:%m:%Y %H:%M:%S",ptuser);
	printf("FECHA Y HORA INTRODUCIDA:\t%s\n",userdate);

	*usertime=mktime(ptuser);
	printf("segundos de usertime:%ld\n",*usertime);

}

/*
* \fn void difference(time_t usertime, time_t mytime)
* \brief Calcula en imprime la diferencia en Dias, horas, minutos y segundos entre la fecha actual y la fecha dada por el usuario.
* \details Dada la cantidad de segundos de la fecha actual y de la fecha dada, calcula la diferencia en dias, horas, minutos, segundos entre ambas
		   de forma aproximada (No se consideran los bisiestos). Se utilizan constantes definidas en myheader.h  que contienen la cantidad de segundos en un dia (seg_day),
		   la cantidad de segundos en una hora (seg_hour), y la cantidad de segundos en un minuto (seg_min).
* \arg time_t usertime Variable creada en el main de tipo time_t (tipo de dato definido en el header time.h) para almacenar 
					   los segundos que han pasado desde Epoch (01-01-1970) hasta la fecha introducida por el usuario.
* \arg time_t *mytime Variable creada en el main de tipo time_t (tipo de dato definido en el header time.h) para almacenar los segundos que han pasado desde Epoch (01-01-1970)
* \return No retorna por valor. Imprime en pantalla la fecha y hora obtenida.
* \Author Daniel Andres Jimenez Barnique e-mail: barnique2802@gmail.com
* \date 19.02.26
*/

void difference(time_t usertime, time_t mytime)
{
	long dday,dhour,dmin,dsec,resto,diff;

	diff=fabs(usertime-mytime);

	dday = diff/seg_day;
	resto = diff%seg_day;

	dhour = resto/seg_hour;
	resto = resto%seg_hour;

	dmin = resto/seg_min;
	dsec = resto%seg_min;

	printf("La diferencia entre las fechas es de:\nDias: %ld\tHoras: %ld\tMinutos: %ld\tSegundos: %ld\n",dday,dhour,dmin,dsec); 

}