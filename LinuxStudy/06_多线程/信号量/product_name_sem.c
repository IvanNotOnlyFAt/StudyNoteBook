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

//文件模式
/*
*S_IRUSR：文件所有者的读权限	100
*S_IWUSR：文件所有者的写权限	010
*S_IRGRP：文件所有者同组用户的读权限 000 100
*S_IROTH：其他用户的读权限		000 100
*/
#define FILE_MODE  (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)	//0644
#define NBUFF             4      //槽位的个数
#define SEM_MUTEX         "mutex1" 		//锁mutex有名信号量的名字
#define SEM_NEMPTY         "nemtpy1"	//空盘数量n_empty有名信号量的名字
#define SEM_NSTORED     "nstored1"		//库存数量n_stored有名信号量的名字

int nitems;  //条目的个数
//缓冲区结构
struct  
{
    int buff[NBUFF];   
    sem_t *mutex,*nempty,*nstored;   //信号量
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
	
	//sem_t *sem_open(const char *name, int oflag,mode_t mode, unsigned int value);
	//mode = (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)	//0644
    //创建二元信号量---锁初始化为1，因为锁一开始是释放状态--对于多个生成消费者来说有必要
    if((shared.mutex = sem_open(SEM_MUTEX,O_CREAT,FILE_MODE,1)) == SEM_FAILED)
    {
        perror("sem_open() error");
        exit(-1);
    }
	
    //创建nempty信号量--空盘子初始化为4
    if((shared.nempty =  sem_open(SEM_NEMPTY,O_CREAT,FILE_MODE,NBUFF)) == SEM_FAILED)
    {
        perror("sem_open() error");
        exit(-1);
    }
	
    //创建nstored信号量--库存一开始是0
    if((shared.nstored = sem_open(SEM_NSTORED,O_CREAT,FILE_MODE,0)) == SEM_FAILED)
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
    sem_unlink(SEM_MUTEX);
    sem_unlink(SEM_NEMPTY);
    sem_unlink(SEM_NSTORED);
    exit(0);
}

void *produce(void *arg)
{
    int i;
    printf("produce is called.\n");
    for(i=0;i<nitems;i++)
    {
		/*****************************/
        //判断是否有空槽，有的将其减少1
        sem_wait(shared.nempty);
        //锁住槽位，对于多个生产者的时候有必要，单个生产者没有必要
        sem_wait(shared.mutex); 
		/*****************************/
		shared.buff[i%NBUFF] = i;
        printf("produced a new item: %d\n",shared.buff[i%NBUFF]);
		
		/*****************************/
        sem_post(shared.mutex);  //释放锁
        sem_post(shared.nstored);  //缓冲区中条目数加1
		/*****************************/
        srandom(time(NULL));	//随机数种子
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
		/*****************************/
        /*判断缓冲区中是否有条目，有的话将条目数减少1*/
        sem_wait(shared.nstored); 
        /*锁住缓冲区，对多个消费者有必要，对单个消费者没必要*/
        sem_wait(shared.mutex);
		/*****************************/
        printf("remove: buff[%d] = %d\n",i % NBUFF,shared.buff[i % NBUFF]);
		/*****************************/
        sem_post(shared.mutex);  //释放锁
        sem_post(shared.nempty); //将缓冲区中的空槽数目加1
		/*****************************/
        srandom(time(NULL));	//随机数种子
        sleep((random()%3)+1);
    }
    return NULL;
}
