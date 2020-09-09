/*************************************************************************
  > File Name: queue.c
  > Author: IvanLxy
  > Mail: yoyiyyo@163.com 
  > Created Time: Mon 31 Aug 2020 11:21:19 PM CST
  > 这个队列是一次性的，所以不能二次使用
************************************************************************/
#include <stdio.h>

#define QUE_SIZE 5

int stack[QUE_SIZE];
int front = 0;
int rear = 0;

int is_full()
{
	return rear == QUE_SIZE;
}

int is_empty()
{
	return rear == front;
}

void push(int item)
{
	if(!is_full())
	{
		stack[rear++] = item;
	}
}

int pop()
{
	return stack[front++];
}

int main()
{
	push(1);
	push(2);
	push(3);
	push(4);
	push(5);
	push(6);
	push(7);

	while (!is_empty())
	{
		printf("%d  ",  pop());
	}
	printf("\n");

	/*这个队列是一次性的，所以不能二次使用*/
	push(1);
	push(2);
	push(3);
	push(4);
	push(5);
	push(6);
	push(7);

	while (!is_empty())
	{
		printf("%d  ",  pop());
	}
	printf("\n");
	return 0;
	/**********************
	> 1  2  3  4  5  
	> 
	> [Finished in 0.1s]
	**********************/
}