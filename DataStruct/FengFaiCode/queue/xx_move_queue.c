/*************************************************************************
    > File Name: xx_move_queue.c
    > Author: Nfh
    > Mail: 1024222310@qq.com 
    > Created Time: 2020年08月04日 星期二 11时04分09秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int QType;

// 队列节点
typedef struct QNode
{
    QType data;
    struct QNode *next;
}QNode, *QueuePtr;

// 队列结构体
typedef struct
{
    int length;
    QueuePtr front;     // 队头指针
    QueuePtr rear;      // 队尾指针
}LinkQueue;

// 初始化队列
int initQueue(LinkQueue *queue)
{
    queue->front = (QueuePtr)malloc(sizeof(QNode));
    assert(queue->front != NULL);
    queue->rear = queue->front;
    queue->front->next =NULL;
    queue->length = 0;

    return 1;
}

// 销毁队列
int destroyQueue(LinkQueue *queue)
{
    while(queue->front != NULL)
    {
        queue->rear = queue->front->next;
        free(queue->front);
        queue->front = queue->rear;
    }

    return 1;
}

// 向队列添加元素
int push(LinkQueue *queue, QType e)
{
    QNode *node = (QueuePtr)malloc(sizeof(QNode));
    assert(node != NULL);
    node->data = e;
    node->next = NULL;
    queue->rear->next = node;
    queue->rear = node;
    queue->length++;
    return 1;
}

// 弹出队列中的元素
int pop(LinkQueue *queue, QType *e)
{
    if(queue->front == queue->rear)
        return 0;
    QueuePtr p = queue->front->next;
    *e = p->data;
    queue->front->next = p->next;
    if(p == queue->rear)
        queue->rear = queue->front;
    free(p);
    queue->length--;
    return 1;
}

// 获取队列头部元素
int getHead(LinkQueue *queue, QType *e)
{
    if(queue->front == queue->rear)
        return 0;
    QueuePtr p = queue->front->next;
    *e = p->data;

    return 1;
}

// 清空队列
int clearQueue(LinkQueue *queue)
{
    QueuePtr p = queue->front->next;
    while(queue->front->next != NULL)
    {
        queue->front->next = p->next;
        free(p);
        p = queue->front->next;
    }
    queue->rear = queue->front;
    queue->length = 0;
    return 1;
}

// 返回队列的长度
int queueLength(LinkQueue *queue)
{
    return queue->length;
}

int main()
{
    int arr[10] = {0}, i = 0;
    LinkQueue queue;
    initQueue(&queue);

    for(i = 0; i < 10; i++)
    {
        arr[i] = i + 1;
        push(&queue, arr[i]);
    }

    while(queue.length > 0)
    {
        QType e;
        pop(&queue, &e);
        printf("%d  ", e);
    }
    printf("\n");
    destroyQueue(&queue);

    return 0;
}
