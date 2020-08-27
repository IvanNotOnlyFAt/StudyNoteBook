/*************************************************************************
  > File Name: 35_producer_semaphore.c
  > Author: IvanLxy
  > Mail: yoyiyyo@163.com 
  > Created Time: Thu 13 Aug 2020 04:26:22 PM CST
************************************************************************/
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
/*--------------------*/
#include <semaphore.h> 

#define NUM 5
int queue[NUM];
sem_t blank_number, product_number;
/*--------------------*/


void *consumer(void *arg)
{
    int c = 0;
	while(1)
	{
		/*-------------------------------*/
	    sem_wait(&product_number);    //空盘子-1
		/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
		printf("Consume %d\n", queue[c]);	//消费者消费当前这个，并置0
        queue[c] = 0;    
        /*-------------------------------*/
		sem_post(&blank_number);  //成品装盘+1
		/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
        c = (c+1)%NUM;              //c不能超过NUM
        sleep(rand()%5);

	}
}

void *producer(void *arg)
{
    int p = 0;
	while(1)
	{
		/*-------------------------------*/
	    sem_wait(&blank_number);    //空盘子-1
		/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
		queue[p] = rand() % 1000 + 1;
        printf("Produce %d\n", queue[p]);
        /*-------------------------------*/
		sem_post(&product_number);  //成品装盘+1
		/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
        p = (p+1)%NUM;              //p不能超过NUM
        sleep(rand()%5);
	}
}

int main(int argc, char *argv[])
{
	pthread_t pid, cid;

    sem_init(&blank_number, 0, NUM);    //空盘子初始化为5
    sem_init(&product_number, 0, 0);

	pthread_create(&pid, NULL, producer, NULL);
	pthread_create(&cid, NULL, consumer, NULL);
	pthread_join(pid, NULL);
	pthread_join(cid, NULL);

    sem_destroy(&blank_number);
    sem_destroy(&product_number);

	return 0;
}

