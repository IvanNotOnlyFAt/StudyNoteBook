#include "list.h"
#include "queue.h"

SeqQueue *SeqQueue_Create(int capacity)
{
    return (SeqQueue *)seqListCreate(capacity);
}

void SeqQueue_Destroy(SeqQueue *queue)
{
    seqListDestroy(queue);
}

void SeqQueue_Clear(SeqQueue *queue)
{
    seqListClear(queue);
}

int SeqQueue_Append(SeqQueue *queue, void *item)
{
    return seqListInsert(queue, (SeqListNode *)item, SeqQueue_Length(queue));
}

void *SeqQueue_Retrieve(SeqQueue *queue)
{
    return (void *)seqListDelete(queue, 0);
}

void *SeqQueue_Header(SeqQueue *queue)
{
    return (void *)seqListGet(queue, 0);
}

int SeqQueue_Length(SeqQueue *queue)
{
    return seqListLength((SeqList *)queue);
}

int SeqQueue_Capacity(SeqQueue *queue)
{
    return seqListCapacity((SeqList *)queue);
}
