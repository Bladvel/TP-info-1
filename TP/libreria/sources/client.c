#include "cli-serv.h"

int main(int argc, char * argv[])
{
	int sockfd, dspfd;  /*File Descriptor para sockets*/
	int numbytes =1, escritos;/*Contendrá el número de bytes recibidos por read () */
	char * buf = (char *)calloc (buffsize,sizeof (char));  /* Buffer donde se reciben los datos de read ()*/

/* Tratamiento de la línea de comandos. */
	if (argc < 2)
	{
		fprintf(stderr,"uso: %s hostname [port]\n",argv [0]);
		exit(1);
    }

	/* abrimos el dispositivo de audio*/
	if ((dspfd = open("/dev/dsp", O_RDWR))<0)
	{ 
		fprintf(stderr,"Error en función open, Código de error: %s\n",strerror (dspfd)); 
		exit(1);
	}

	/*Seteamos parámetros de audio*/
	set_audio_params (dspfd,RATE,CHANNELS,SIZE);

	sockfd = conectar (argc, argv);

	while (numbytes !=0 )
	{
		/* Recibimos los datos del servidor */
		if ((numbytes = read (sockfd, buf, buffsize)) == -1)
		{
			perror("error de lectura en el socket");
			exit(1);
		}

		if ((escritos = write (dspfd,buf,numbytes)) == -1)
		{
			perror ("Error en write en dsp");
			exit (1);
		}
		ioctl (dspfd, SOUND_PCM_SYNC,0); // duerme el proceso hasta terminar de reproducir
	}// cierra el while
/* Devolvemos recursos al sistema */
	free (buf);
	close (dspfd);
	close(sockfd);
	return 0;
}
