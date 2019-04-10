/*
* \file main.c
* \brief Programa principal para prueba del ejercicio 8.3
* \details Esta programa sirve para calcular la diferencia en dias, horas, minutos y segundos de una fecha introducidad por el usuario con la fecha actual
* \return 0 si termino OK
* \Para compilar < gcc -c -g main.c -Wall >
* \Para linkear < gcc -g main.o funciones.o -o main -Wall > 
* \Author Daniel Andres Jimenez Barnique e-mail: barnique2802@gmail.com
* \date 19.02.26
* \version 1.0 Le hace falta verificar los datos de entrada de la fecha y hora/

 struct tm {
   int tm_sec;         seconds,  range 0 to 59         
   int tm_min;          minutes, range 0 to 59           
   int tm_hour;         hours, range 0 to 23            
   int tm_mday;         day of the month, range 1 to 31  
   int tm_mon;        month, range 0 to 11             
   int tm_year;        The number of years since 1900   
   int tm_wday;        day of the week, range 0 to 6    
   int tm_yday;        day in the year, range 0 to 365  
   int tm_isdst;       daylight saving time             
};

1	size_t 			This is the unsigned integral type and is the result of the sizeof keyword.

2	clock_t 	This is a type suitable for storing the processor time.

3	time_t		This is a type suitable for storing the calendar time.

4	struct tm 	This is a structure used to hold the time and date.


time_t time(time_t *t) returns the time since the Epoch (00:00:00 UTC, January 1, 1970), measured in seconds
struct tm *localtime(const time_t *timer)
size_t strftime(char *str, size_t maxsize, const char *format, const struct tm *timeptr)
time_t mktime(struct tm *timeptr)
double difftime(time_t time1, time_t time2)


*/ 


#include "myheader.h"


int main(void)
{
	time_t mytime, usertime;

	char actualdate[BUFFER_size],userdate[BUFFER_size];//ddate1[BUFFER_size],ddate2[BUFFER_size];
	struct tm *pt, *ptuser;// *ptdif1, *ptdif2;

	pt=(struct tm*)malloc(sizeof(struct tm));

	ptuser=(struct tm*)malloc(sizeof(struct tm)); //asigno un tamanio al puntero ya que no le asigno una estructura a la cual apuntar
	
	if ((ptuser == NULL)||(pt == NULL))
	{
		puts("Error en la asignacion de memoria");
		return -1;
	}




	
	printime(&mytime,pt,actualdate);
	getusertime(&usertime,ptuser,userdate);
	difference(usertime,mytime);
	
/* FORMA BASICA
	printf("Fecha y hora actual en formato dd:mm:yyyy hh:mm:ss\n%d:%d:%d\t%d:%d:%d\n",pt->tm_mday,(pt->tm_mon) + 1,pt->tm_year + 1900,pt->tm_hour,pt->tm_min,pt->tm_sec);
*/


//CALCULO DE DIFERENCIA



	


/*	if (usertime>=mytime)
		difference=(time_t)difftime(mytime,usertime);
	else
		difference=(time_t)difftime(usertime,mytime);

	ptdif1 = localtime (&difference);
	strftime(ddate1,BUFFER_size,"%d:%m:%Y %H:%M:%S",ptdif1);
	printf("FECHA Y HORA de DIFERENCIA (usando localtime):\t%s\n",ddate1);

	ptdif2 = gmtime (&difference);
	strftime(ddate2,BUFFER_size,"%d:%m:%Y %H:%M:%S",ptdif2);
	printf("FECHA Y HORA de DIFERENCIA (usando gmtime):\t%s\n",ddate2);*/

	return 0;
}
