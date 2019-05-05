


#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
void main()
{	int pid,pid1,pid2;
	pid=fork();
	if(pid== -1)
	{	printf("Error in process creation\n");
		exit(1);
	}
	if(pid!=0)
	{	pid1=getpid();
		printf("\nThe process id of parent is %d\n",pid1);
	}
	else
	{	pid2=getpid();
		printf("\nThe process id of child is %d\n",pid2);
	
	}
}
