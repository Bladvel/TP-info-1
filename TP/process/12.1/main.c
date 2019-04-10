#include "myheader.h"

int main(int argc, char const *argv[])
{
	int n;

	if(argc!=2){
		fprintf(stderr, "Indicar el numero de instancias child a crear: \"%s <procesos>\"\n", argv[0] );
		return 1;
	}
	n=atoi(argv[1]);
	fan(n);
	return 0;
}