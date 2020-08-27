/*************************************************************************
  > File Name: 32_producer.c
  > Author: IvanLxy
  > Mail: yoyiyyo@163.com 
  > Created Time: Thu 13 Aug 2020 04:26:22 PM CST
************************************************************************/
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>

//队列的结构体
struct msg
{
    int num;
	struct msg *next;
};


struct msg *head;	//队列的起点
pthread_cond_t has_product = PTHREAD_COND_INITIALIZER;	//条件变量初始化
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;		//锁的初始化

void *consumer(void *p)
{
	struct msg *mp;
	/*
	*for(;;)和while（1）两种死循环的区别：
	*for式死循环更加高效：";;"两个空语句一般编译器会优化掉直接进入循环体。
	*while(1)里的1被看成表达式，每循环一次都要判断常量1是不是等于零。
	*/
	for (;;)
	{
		/*-------------------------------*/
		pthread_mutex_lock(&lock);
		while (head == NULL)
		{
			//int pthread_cond_wait(pthread_cond_t *restrict cond,
            //                      pthread_mutex_t *restrict mutex);
			pthread_cond_wait(&has_product, &lock);
		}
		//队列向右消耗：{(*head)[3] -> [2] -> [1] -> NULL}
		mp = head;			//mp指向当前节点
		head = mp->next;	//head指向下一个
		pthread_mutex_unlock(&lock);
		/*-------------------------------*/
		printf("Consume %d\n", mp->num);	//消费者消费当前这个，并free	
		free(mp);
	}
}

void *producer(void *p)
{
	struct msg *mp;
	for (;;)
	{
		mp = malloc(sizeof(struct msg));	//生成者进行生成
		mp->num = rand() % 1000 + 1;		//生成产品内容是个（随机数）（0~1000）
		printf("Produce %d\n", mp->num);	//打印生成者生产出的产品
		
		/*-------------------------------*/
		pthread_mutex_lock(&lock);	
		//队列向左增加：{(*head)[3] -> [2] -> [1] -> NULL}
		mp->next = head;					//队列的尾插法，最后节点->next是head
		head = mp;							//插完新的节点变成head,
		pthread_mutex_unlock(&lock);
		/*-------------------------------*/
		
		pthread_cond_signal(&has_product);	//唤醒--相当于条件变量+1，唤醒等待队列
		sleep(rand() % 5);					//挂起（0~5）秒
	}
}

int main(int argc, char *argv[])
{
	pthread_t pid, cid;

	pthread_create(&pid, NULL, producer, NULL);
	pthread_create(&cid, NULL, consumer, NULL);
	pthread_join(pid, NULL);
	pthread_join(cid, NULL);
	return 0;
}

