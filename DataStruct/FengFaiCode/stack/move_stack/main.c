#include <stdio.h>

#include "stack.h"

int main()
{
    LinkStack *stack = LinkStack_Create();
    int arr[10] = {0}, i = 0;
    for(i = 0; i < 10; i++)
    {
        arr[i] = i + 1;
        LinkStack_Push(stack, arr + i);
    }
    while(LinkStack_Size(stack) > 0)
    {
        int *p = (int *)LinkStack_Pop(stack);
        printf("%d  ", *p);
    }
    printf("\n");

    return 0;
}
