/*************************************************************************
  > File Name: stack.c
  > Author: IvanLxy
  > Mail: yoyiyyo@163.com 
  > Created Time: Mon 31 Aug 2020 08:09:59 PM CST
************************************************************************/
#include <stdio.h>

#define STACK_SIZE 5

int stack[STACK_SIZE];
int top = 0;

int is_full()
{
	return top == STACK_SIZE;
}

int  is_empty()
{
	return top == 0;
}

void push(int item)
{
	if(!is_full())
	{
		stack[top++] = item;
	}
}

int pop()
{
	return stack[--top];
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

	while(!is_empty())
	{
		printf("%d  ", pop());
	}
	printf("\n");

	push(7);
	push(6);
	push(5);
	push(4);
	push(3);
	push(2);
	push(1);

	while (!is_empty())
	{
		printf("%d  ",  pop());
	}
	printf("\n");
	return 0;

/*******结果********
* 	5  4  3  2  1  
* 	3  4  5  6  7  
*******************/

}