/*************************************************************************
  > File Name: loop_queue.c
  > Author: IvanLxy
  > Mail: yoyiyyo@163.com 
  > Created Time: Mon 31 Aug 2020 11:21:19 PM CST
  > 环形队列，没有用total，而是用rear == front;与(rear+1) % SIZE == front;分辨
  > rear与front在满的时候，之间有空一格的距离，为了与空队状态区分
************************************************************************/
#include<stdio.h>
#define SIZE 5

int queue[SIZE];
int front = 0;
int rear = 0;

int is_full()
{
	/*rear+1 就是为了与front空一格距离，不然rear == front就是空队*/
	return (rear+1) % SIZE == front;
}

int is_empty()
{
	return rear == front;
}

void enqueue(int item)
{
	if(!is_full())
	{
		queue[rear++] = item;
		rear = rear % SIZE;
	}
}

int dequeue()
{
	int item = queue[front++];
	front = front % SIZE; 
	return item;
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
	>  2 3 4 8 
	> [Finished in 0.1s]
	**********************/
}