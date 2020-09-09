#include "list.h"
#include "stack.h"

SeqStack *SeqStack_Create(int capacity)
{
    SeqStack *stack = (SeqStack *)seqListCreate(capacity);
    return stack;
}

void SeqStack_Destroy(SeqStack *stack)
{
    seqListDestroy((SeqList *)stack);
}

void SeqStack_Clear(SeqStack *stack)
{
    seqListClear((SeqList *)stack);
}

int SeqStack_Push(SeqStack *stack, void *item)
{
    return seqListInsert((SeqList *)stack, item, seqListLength((SeqList *)stack));
}

void *SeqStack_Pop(SeqStack *stack)
{
    return seqListDelete(stack, seqListLength(stack) - 1);
}

void *SeqStack_Top(SeqStack *stack)
{
    return seqListGet((SeqList *)stack, seqListLength((SeqList *)stack));
}

int SeqStack_Size(SeqStack *stack)
{
    int size = seqListLength((SeqList *)stack);
}

int SeqStack_Capacity(SeqStack *stack)
{
    int capacity = seqListCapacity((SeqList *)stack);
    return capacity;
}
