/*************************************************************************
  > File Name: total_queue.c
  > Author: IvanLxy
  > Mail: yoyiyyo@163.com 
  > Created Time: Mon 31 Aug 2020 11:21:19 PM CST
  > total 负责记录是否已满
************************************************************************/
#include <stdio.h>

#define QUE_SIZE 5

int queue[QUE_SIZE];
int front = 0;
int rear = 0;
int total = 0;	//负责记录是否已满

int is_full()
{
	return total == QUE_SIZE;
}

int is_empty()
{
	return total == 0;
}

void enqueue(int item)
{
	if(!is_full())
	{
		queue[rear++] = item;
		rear = rear % QUE_SIZE;	//环形队列
		total++;
	}
}

int dequeue()
{
	/*交给主函数判断是否为空*/
	/*
	if(!is_empty())
	{
	*/
		int item = queue[front++];
		front = front % QUE_SIZE;		//环形队列
		total--;
		return item;
	/*
	}else
	{
		return NULL;
	}
	*/
}

int main()
{
	enqueue(1);
	enqueue(2);
	enqueue(3);
	enqueue(4);
	enqueue(1);
	enqueue(2);
	enqueue(3);
	enqueue(4);

	dequeue();
	enqueue(8);
	while(!is_empty())
    	{
    		printf("%d ",dequeue());
   	 }
   	 printf("\n");

    	return 0;
	/**********************
	>  2 3 4 1 8
	> [Finished in 0.1s]
	**********************/
}