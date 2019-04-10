#include "myheader.h"

/**
* \fn void fan(int);
* \brief Genera una cantidad de procesos child simultaneos
* \details La funcion crea una cantidad especifica de instancias child dada por el usuario
* Se logra mediante la estructura de control "for". Dentro de su modulo, se hace el llamado
* de fork para crear un child en cada iteracion. La instancia padre se crea en la primera vuelta,
* y no termina hasta la finalizacion del programa. Se utiliza un if para determinar las funciones
* que cumplira cada child, y estos mismos moriran apenas dentro de su bloque de ejecucion luego de
* imprimir en pantalla su PID, su PPID y el numero de iteracion.
* \arg Recibe un entero n que indica el numero de childs que creara
* \return No retorna ningun valor, solo imprime en pantalla.
* \author Daniel Jimenez. E-mail: barnique2802@gmail.com
* \date 19.03.24
*/


void fan (int n)
{
	pid_t childpid;
	int i;
	for (i = 1; i < n+1; ++i)
	{
		
		if((childpid=fork())==-1)
		{
			fprintf(stderr, "Error\n");
			exit(1);
		}	

		if(childpid==0)
		{
			fprintf(stderr, "i=%d I am process %ld, my parent is %ld\n",i,(long)getpid(), (long)getppid());
			sleep(5);
			exit(0);
		}
	
	}
	sleep(30);

	fprintf(stderr, "i=%d I am the OG %ld, my parent is %ld\n",i,(long)getpid(), (long)getppid());

}