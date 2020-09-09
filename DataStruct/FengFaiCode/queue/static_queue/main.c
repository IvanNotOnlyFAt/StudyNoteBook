#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

int main()
{
    int arr[10] = {0}, i = 0;
    SeqQueue *queue = SeqQueue_Create(20);
    for(i = 0; i < 10; i++)
    {
        arr[i] = i + 1;
        SeqQueue_Append(queue, arr + i);
    }

    printf("queue length: %d\n", SeqQueue_Length(queue));
    printf("queue capacity: %d\n", SeqQueue_Capacity(queue));

    while(SeqQueue_Length(queue) > 0)
    {
        printf("%d  ", *(int *)SeqQueue_Retrieve(queue));
    }
    printf("\n");

    return 0;
}
