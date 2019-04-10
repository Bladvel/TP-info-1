#include <fcntl.h>
#include <sock-lib.h>
#include <sound-lib.h>

int main()
{
	int fd;		/* sound device file descriptor */
	int status;	/* return status de system calls */
/* segundos de audio a grabar */
	int LENGTH=5;
/* sampling rate = velocidad de muestreo del audio a la entrada*/
	int RATE=8000;
/* sample size = Tamaño de muestra. Típicamente 8 o 16 bits */
	int SIZE=8;
/* 1 = mono 2 = stereo */
	int CHANNELS=1;
/*Calcula dinámicamente el tamaño del buffer de audio*/
	int buffsize=LENGTH*RATE*SIZE*CHANNELS/8;
	/* bufer para el audio */
 	unsigned char *buf;
	/* abrimos el dispositivo de audio*/
	if ((fd = open("/dev/dsp", O_RDWR))<0)
	{ 
		fprintf(stderr,"Error en función open, Código de error: %s\n",strerror (fd)); 
		exit(1);
	}
	/*Seteamos parámetros de audio*/
 	set_audio_params (fd,RATE,CHANNELS,SIZE);

 	while (1) 
 	{       /* termina con Control-C */
		printf("Hablale al microfono ;):\n");
		buf = malloc(buffsize);
		/* La siguiente función bloquea al proceso hasta que se llene el buffer.
		Esto con archivos comunes no se nota, pero con un dispositivo de audio
		en donde se leen RATE muestras por segundo.....si. */
		status = read (fd, buf, buffsize); /* lee */
		if (status ==-1)
		{
			fprintf(stderr,"Error en función read, Código de error: %s\n",strerror (errno));
			free (buf);
			exit (1);
		}
		printf("Dijiste :\n");
		/* Write generalmente no bloquea hasta que termina. Sino que envía la 
		información presente en el buffer al kernel. Por eso luego de enviar, 
		vamos a sincronizar con ioctl ()*/
		status = write(fd, buf, buffsize); /* reproduce */
		if (status == -1)
			fprintf(stderr,"Error en función write, Código de error: %s\n",strerror (errno)); 
		/* Espera a que termine de hacer el playback antes de volver a grabar */
  		status = ioctl(fd, SOUND_PCM_SYNC, 0);
  		if (status == -1) 
  			perror("Error en comando SOUND_PCM_SYNC");
		free (buf);
 	}
}
