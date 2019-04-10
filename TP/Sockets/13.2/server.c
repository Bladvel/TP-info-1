#include <sock-lib.h>
#include <signal.h>

void sigchld_handler(int s)
{
	int saved_errno = errno;
	while(waitpid(-1,NULL,WNOHANG)>0);
	errno = saved_errno;
}

int main ()
{
	int sockfd; /* File Descriptor del socket por el que el servidor "escuchará" conexiones*/
	char message[] = "Hello, world!";
	struct sockaddr_in my_addr;	/* contendrá la dirección IP y el número de puerto local */
	struct sigaction sa;
	int sockdup; 

	if ((sockfd = Open_conection (&my_addr)) == -1)
	{
		perror ("Falló la creación de la conexión"); 
		exit (1);
	}

	sa.sa_handler = sigchld_handler; // reap all dead processes
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	if (sigaction(SIGCHLD, &sa, NULL) == -1) {
		perror("sigaction");
		exit(1);
	}

	while(1)
	{
		sockdup = Aceptar_pedidos (sockfd);
// Aca se pone un fork () y se lo convierte en un server concurrente
// En tal caso, lo que sigue es el child process
// El padre vuelve a Aceptar_pedidos
		if(!fork()) //Child
		{
			close(sockfd);//Cierra el socket original
			if (write (sockdup, message , sizeof (message)) == -1)
			{
				perror("Error escribiendo mensaje en socket");
				exit (1);
			}
			exit(0);
		}

		close(sockdup); //El padre cierra el socket duplicado
	}

	exit(0);
}
