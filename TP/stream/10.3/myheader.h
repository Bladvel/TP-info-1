#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <math.h>


#define LMAX 200

void sepyconv (char* token[],double lista [], char Buff[BUFSIZ]);

double promedio (double lista[],int);
double varianza (double lista[], int n, double prom);

