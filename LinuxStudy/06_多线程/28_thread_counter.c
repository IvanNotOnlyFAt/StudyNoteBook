/*************************************************************************
  > File Name: 28_thread_counter.c
  > Author: IvanLxy
  > Mail: yoyiyyo@163.com 
  > Created Time: Wed 12 Aug 2020 11:18:31 AM CST
************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NLOOP 500

int counter;

void *doit(void *);

int main(void)
{
    pthread_t tidA, tidB;
    /* int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);*/
    pthread_create(&tidA, NULL, &doit, NULL);
    pthread_create(&tidB, NULL, &doit, NULL);

    /*wait for both threads to terminate*/
    pthread_join(tidA, NULL);
    pthread_join(tidB, NULL);

    return 0;
}

void *doit(void *vpter)
{
    /*
     * Each thread fetches, prints, and increment the counter NLOOP times
     * The value of the counter should increase monotonically
     */
    int i, val;
    
    for(i = 0; i < NLOOP; i++)
    {
        val = counter;
        printf("-------1---------\n");
        printf("%x: %d\n", (unsigned int)pthread_self(),val + 1 );
        printf("-------2---------\n");
        counter = val + 1;
        printf("-------3---------\n");
    }
    //printf("-----------------------------------------\n");
    return NULL;



}

