/*************************************************************************
  > File Name: 34_conductor_pro.c
  > Author: IvanLxy
  > Mail: yoyiyyo@163.com 
  > Created Time: Thu 13 Aug 2020 05:33:50 PM CST
************************************************************************/
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
/**********************/
#include <semaphore.h>
#define STAT 1
sem_t door, bus;
/**********************/

void *conductor(void *arg) 
{
	int p = 0;
    printf ("start: door closed\n");
	while (1) 
	{
        sem_wait(&door);    //阻塞直到door>0
        /*--------------------*/
        printf("open door\n");
	    printf("up and down ...\n");
		sleep(rand()%5);
        printf("close door\n");
		sleep(rand()%5);
        /*--------------------*/
        sem_post(&bus);     //bus+1=1
	}
}

void *driver(void *arg) 
{
	int c = 0;
    printf("start:bus stopped\n");
	while (1) 
	{
        sem_wait(&bus);     //阻塞直到bus>0
        /*--------------------*/
        printf ("bus start\n");
	    printf ("bus driving ...\n");
		sleep(rand()%5);
        printf ("bus stop\n");
		sleep(rand()%5);
        /*--------------------*/
        sem_post(&door);    //door+1=0
	}
}

int main(int argc, char *argv[]) 
{
    // int sem_init(sem_t *sem, int pshared, unsigned int value);
    //value参数指定信号量的初始值
    //pshared 的值为 0，那么信号量将被进程内的线程共享,非0在进程间共享
    /*--------------------*/
    sem_init(&door, 0, STAT);
    sem_init(&bus, 0, 0);
    /*--------------------*/
	pthread_t conductor_id, driver_id;  
	
	pthread_create(&conductor_id, NULL, conductor, NULL);
	pthread_create(&driver_id, NULL, driver, NULL);
	
	pthread_join(conductor_id, NULL);
	pthread_join(driver_id, NULL);
	
    /*--------------------*/
    sem_destroy(&door);
    sem_destroy(&bus);
    /*--------------------*/
	return 0;
}
/*
 * 解析：初始状态，door = 1 ，bus = 0；
 * 此时售票员正常处理，而司机阻塞，
 * 售票员处理完，bus+1=1，door-1=0，
 * 售票员阻塞，而司机正常进行
 */

