#include<stdio.h>
#define SIZE 10

int stack[SIZE];
int top = 0;

int is_full()
{
	return top == SIZE;
}

int is_empty()
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
	int x = 4;
	int i;

   while(x != 0)
   {
   	 i = x % 2;
   	 push(i);
   	 x = x / 2;
   }

   while(!is_empty())
   {
   	 printf("%d ",pop());
   }
   printf("\n");
   return 0;
}
