#include "myheader.h"


void sign_handler(int n)
{
	while((waitpid(-1,NULL,WNOHANG))>0);
	sleep(15);

}


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

	signal(SIGCHLD,sign_handler);

	sleep(15);
	fprintf(stderr, "i=%d I am the OG %ld, my parent is %ld\n",i,(long)getpid(), (long)getppid());

}
