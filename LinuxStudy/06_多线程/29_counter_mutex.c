/*************************************************************************
  > File Name: 29_thread_counter_mutex.c
  > Author: IvanLxy
  > Mail: yoyiyyo@163.com 
  > Created Time: Wed 12 Aug 2020 11:18:31 AM CST
************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NLOOP 500

int counter;
/*********/
pthread_mutex_t counter_mutex = PTHREAD_MUTEX_INITIALIZER;
/*********/
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
        pthread_mutex_lock(&counter_mutex);
        /*---------------------------------*/
        val = counter;
        printf("%x: %d\n", (unsigned int)pthread_self(),val + 1 );
        counter = val + 1;
        /*---------------------------------*/
        pthread_mutex_unlock(&counter_mutex);
    }
    //printf("-----------------------------------------\n");
    return NULL;



}

