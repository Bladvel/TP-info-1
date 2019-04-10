#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <sock-lib.h>
#include <sound-lib.h>

/* segundos de audio a grabar */
#define MSEG 100
/* sampling rate = velocidad de muestreo del audio a la entrada*/
#define RATE 48000
/* sample size = Tamaño de muestra. Típicamente 8 o 16 bits */
#define SIZE 16
/* 1 = mono 2 = stereo */
#define CHANNELS 2
/*Calcula dinámicamente el tamaño del buffer de audio*/
#define buffsize MSEG*RATE*SIZE*CHANNELS/8/1000
