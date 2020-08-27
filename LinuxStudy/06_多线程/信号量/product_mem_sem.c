#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <time.h>
#include <sys/stat.h>

#define NBUFF             4      //槽位的个数


int nitems;  //条目的个数
//缓冲区结构
struct
{
    int buff[NBUFF];
    sem_t mutex;	//创建二元信号量
	sem_t nempty; 	//创建nempty信号量
	sem_t nstored;	//创建nstored信号量
}shared;



void *produce(void *arg);
void *consume(void *arg);

int main(int argc,char *argv[])
{
    pthread_t   tid_produce,tid_consume;
    if(argc != 2)
    {
        printf("usage: prodcons <#itmes>");
        exit(0);
    }
    nitems = atoi(argv[1]);  //获取条目数目

	
	//创建基于内存的无名信号量		 
    if(sem_init(&shared.mutex,0,1) == -1)
    {
        perror("sem_open() error");
        exit(-1);
    }
    if(sem_init(&shared.nempty,0,NBUFF) == -1)
    {
        perror("sem_open() error");
        exit(-1);
    }
    if(sem_init(&shared.nstored,0,0) == -1)
    {
        perror("sem_open() error");
        exit(-1);
    }

    //生产者线程
    pthread_create(&tid_produce,NULL,produce,NULL);
    //消费者线程
    pthread_create(&tid_consume,NULL,consume,NULL);
    pthread_join(tid_produce,NULL);
    pthread_join(tid_consume,NULL);
    //摧毁信号量
    sem_destroy(&shared.mutex);
    sem_destroy(&shared.nempty);
    sem_destroy(&shared.nstored);
    exit(0);
}

void *produce(void *arg)
{
    int i;
    printf("produce is called.\n");
    for(i=0;i<nitems;i++)
    {
        //判断是否有空槽，有的将其减少1
        sem_wait(&shared.nempty);
        //锁住槽位，对于多个生产者的时候有必要，单个生产者没有必要
        sem_wait(&shared.mutex); 
        shared.buff[i%NBUFF] = i;
        printf("produced a new item: %d\n",shared.buff[i%NBUFF]);
        sem_post(&shared.mutex);  //释放锁
        sem_post(&shared.nstored);  //缓冲区中条目数加1
        srandom(time(NULL));
        usleep(random()%1000);
    }
    return NULL;
}

void *consume(void *arg)
{
    int   i;
    printf("consumer is called.\n");
    for(i=0;i<nitems;i++)
    {
        //判断缓冲区中是否有条目，有的话将条目数减少1
        sem_wait(&shared.nstored); 
        //锁住缓冲区，对多个消费者有必要，对单个消费者没必要
        sem_wait(&shared.mutex);
        
        printf("remove: buff[%d] = %d\n",i % NBUFF,shared.buff[i % NBUFF]);
        
        sem_post(&shared.mutex);  //释放锁
        sem_post(&shared.nempty); //将缓冲区中的空槽数目加1
        srandom(time(NULL));
        sleep((random()%3)+1);
    }
    return NULL;
}
