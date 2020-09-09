#include<stdio.h>

#define STACK_SIZE 10

int stack[STACK_SIZE];
int top = 0;

int is_full()
{
	return top == STACK_SIZE;
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

int is_empty()
{
	return top == 0;
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
       printf("%d ",pop());
	}
	printf("\n");

	return 0;
}
