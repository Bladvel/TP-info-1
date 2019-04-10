#include "cli-serv.h"

int main ()
{
	int sockfd, rawfilefd; 
	int readed=1;
	struct sockaddr_in my_addr;	/* contendrá la dirección IP y el número de puerto local */
	int sockdup; 
	char *music = calloc (buffsize,sizeof(char));

	if ((sockfd = Open_conection (&my_addr)) == -1)
	{
		perror ("Falló la creación de la conexión"); 
		exit (1);
	}
#ifdef DEBUG	
	printf ("Conexión creada. Nro socket: %d. \n",sockfd);
#endif
	while(1)
	{
		sockdup = Aceptar_pedidos (sockfd);
		if ((rawfilefd = open ("/home/alejandro/Music/PinkFloyd/Money.raw",O_RDONLY)) == -1)
		{
			perror ("Error open");
			close (sockdup);
			continue;
		}
#ifdef DEBUG	
	printf ("Conexión aceptada. Nro socket: %d.",sockdup);
#endif
		while (readed > 0)
		{
			if ((readed=read(rawfilefd,music,sizeof(music)))==-1)
			{
				perror ("Error lectura archivo raw");
				close (sockdup);
				continue;
			}
			if (write (sockdup, music , readed) == -1)
			{
				perror("Error escribiendo mensaje en socket");
				close (sockdup);
				continue;
			}
		}// fin ciclo de lectura de audio.
		close(sockdup);
	}
	free (music);
	exit(0);
}
