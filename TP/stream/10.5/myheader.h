#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <math.h>

#define LMAX 200

void sepyconv (char* token[],double lista [], FILE* fd);

double promedio (double lista[],int);
double varianza (double lista[], int n, double prom);