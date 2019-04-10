#include "myheader.h"

void stdoutprint (FILE* fd)
{	
	char c;
	while (1)
	{
		c = fgetc(fd);
		if (feof(fd))
			break;
		printf("%c",c);
	}

}