#include<stdio.h>
#include<dirent.h>
#include<sys/types.h>
#include<stdlib.h>
int main()
{	char dirname[10];
	DIR *p;
	struct dirent *d;
	printf("\nEnter directory name :");
	scanf("%s",dirname);
	p=opendir(dirname);
	if(p==NULL)
	{	perror("Cannot find dir");

		exit(-1);
	}
	while(d=readdir(p))
		printf("%s\n",d->d_name);
}
