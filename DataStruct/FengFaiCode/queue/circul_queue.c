/*************************************************************************
    > File Name: circul_queue.c
    > Author: Nfh
    > Mail: 1024222310@qq.com 
    > Created Time: 2020年08月04日 星期二 14时46分15秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX 10

typedef int QType;

// 循环队列结构体
typedef struct
{
    QType *base;
    int front;
    int rear;
} CirQueue;

// 初始化循环队列
int initQueue(CirQueue *queue)
{
    queue->base = (QType *)malloc(sizeof(QType) * MAX);
    assert(queue->base != NULL);
    queue->front = queue->rear = 0;
    return 1;
}

// 获取循环队列的长度
int queueLength(CirQueue *queue)
{
    return (queue->rear - queue->front + MAX) % MAX;
}

// 向循环队列里添加元素
int push(CirQueue *queue, QType e)
{
    if((queue->rear + 1) % MAX == queue->front)     // 队满
        return 0;
    queue->base[queue->rear] = e;
    queue->rear = (queue->rear + 1) % MAX;          // 调整队尾位置
    return 1;
}

// 弹出循环队列里的元素
int pop(CirQueue *queue, QType *e)
{
    if(queue->front == queue->rear)                 // 队空
        return 0;
    *e = queue->base[queue->front];
    queue->front = (queue->front + 1) % MAX;        // 调整队首位置
    return 1;
}

// 获取循环队列的头部元素
int getHead(CirQueue *queue, QType *e)
{
    if(queue->front == queue->rear)                 // 队空
        return 0;
    *e = queue->base[queue->front];
    return 1;
}

// 清空循环队列
int clearQueue(CirQueue *queue)
{
    queue->front = queue->rear = 0;
    return 1;
}

// 销毁循环队列
int destoryQueue(CirQueue *queue)
{
    queue->front = queue->rear = 0;
    free(queue->base);
    return 1;
}

int main()
{
    int arr[10] = {0}, i = 0;
    CirQueue queue;
    initQueue(&queue);

    for(i = 0; i < 10; i++)
    {
        arr[i] = i + 1;
        push(&queue, arr[i]);
    }
    printf("Cirqueue length: %d\n", queueLength(&queue));
    while(queue.front != queue.rear)
    {
        QType e;
        pop(&queue, &e);
        printf("%d  ", e);
    }
    printf("\n");
    printf("Cirqueue length: %d\n", queueLength(&queue));
    destoryQueue(&queue);

    return 0;
}
