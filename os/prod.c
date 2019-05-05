#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#define size 3
pthread_t tid;
sem_t empty,full;
pthread_mutex_t mutx;

int count=0;
int buffer[size];

void produceitem(int n)
{	int item;
	pthread_mutex_lock(&mutx);
	if(count<size)
	{	item=rand();
		buffer[++count]=item;
		printf("\nProducer %d produceitem %d",n,item);
	}
	pthread_mutex_unlock(&mutx);
}
void consumeitem(int n)
{	int item;
	pthread_mutex_lock(&mutx);
	if(count>0)
	{	item=buffer[count];
		count--;
		printf("\nConsumer %d consumeitem %d",n,item);
	}
	pthread_mutex_unlock(&mutx);
}
void *prod(int n)
{	while(1)
	{	sem_wait(&empty);
		produceitem(n);
		sem_post(&full);
		sleep(1);
	}
}
void *cons(int n)
{	while(1)
	{	sem_wait(&full);
		consumeitem(n);
		sem_post(&empty);
		sleep(1);
	}




}
int main(int argc, char *argv[])
{	int cno,pno,i;
	pno=atoi(argv[1]);
	cno=atoi(argv[2]);
	sem_init(&full,0,0);
	sem_init(&empty,0,size);
	for(i=1;i<=pno;i++)
		pthread_create(&tid,0,(void*)prod,(void*)i);
	for(i=1;i<=cno;i++)
		pthread_create(&tid,0,(void*)cons,(void*)i);
	sleep(50);
}
