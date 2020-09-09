#include <stdio.h>
#include "stack.h"

int main()
{
    int arr[10] = {0} , i = 0;
    SeqStack *stack = SeqStack_Create(20);
    for(i = 0; i < 10; i++)
    {
        arr[i] = i + 1;
        SeqStack_Push(stack, arr + i);
    }

    while(SeqStack_Size(stack) > 0)
    {
        int *p = SeqStack_Pop(stack);
        printf("%d  ", *p);
    }
    printf("\n");

    return 0;
}
