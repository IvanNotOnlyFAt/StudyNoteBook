#include "list.h"
#include "stack.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct _tag_LinkStackNode
{
    LinkListNode node;
    void *item;
}TLinkStackNode;


LinkStack *LinkStack_Create()
{
    return linkListCreate();
}

void LinkStack_Destroy(LinkStack *stack)
{
    LinkStack_Clear(stack);
    linkListDestroy(stack);
}

void LinkStack_Clear(LinkStack *stack)
{
    while(LinkStack_Size(stack) > 0)
    {
        LinkStack_Pop(stack);
    }
    return ;
}

int LinkStack_Push(LinkStack *stack, void *item)
{
    TLinkStackNode *tmp = (TLinkStackNode *)malloc(sizeof(TLinkStackNode));
    assert(tmp != NULL);
    memset(tmp, 0, sizeof(TLinkStackNode));
    tmp->item = item;
    linkListInsert(stack, (LinkListNode *)tmp, 0);

    return 1;
}

void *LinkStack_Pop(LinkStack *stack)
{
    void *item = NULL;
    TLinkStackNode *tmp = NULL;

    tmp = linkListDelete(stack, 0);
    if(tmp != NULL)
    {
        item = tmp->item;
        free(tmp);
        return item;
    }
    return NULL;
}

void *LinkStack_Top(LinkStack *stack)
{
    void *item = NULL;
    TLinkStackNode *tmp = NULL;

    tmp = linkListGet(stack, 0);
    if(tmp != NULL)
    {
        item = tmp->item;
        return item;
    }
    return NULL;
}

int LinkStack_Size(LinkStack *stack)
{
    return linkListLength(stack);
}
