#include <stdio.h>

int main(int argc, char const *argv[])
{
	int a = 4,b=5,c;
	float f;

	c=a/b;
	f=(float)a/b;
	printf("%d %f\n",c,f );

	return 0;
}