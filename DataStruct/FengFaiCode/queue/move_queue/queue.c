#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"
#include "queue.h"

typedef struct _tag_LinkQueueNode
{
    LinkListNode node;
    void *item;
}TLinkQueueNode;

LinkQueue *LinkQueue_Create()
{
    return (LinkQueue *)linkListCreate();
}

void LinkQueue_Destroy(LinkQueue *queue)
{
    LinkQueue_Clear(queue);
    linkListDestroy(queue);
}

void LinkQueue_Clear(LinkQueue *queue)
{
    while (LinkQueue_Length(queue) > 0)
    {
        LinkQueue_Retrieve(queue);
    }
    linkListClear(queue);
}

int LinkQueue_Append(LinkQueue *queue, void *item)
{
    TLinkQueueNode *node = (TLinkQueueNode *)malloc(sizeof(TLinkQueueNode));
    assert(node != NULL);
    memset(node, 0, sizeof(TLinkQueueNode));
    node->item = item;

    return linkListInsert(queue, (LinkListNode *)node, LinkQueue_Length(queue));
}

void *LinkQueue_Retrieve(LinkQueue *queue)
{
    int ret = 0;
    void *item = NULL;
    TLinkQueueNode *node = NULL;
    node = (TLinkQueueNode *)linkListDelete(queue, 0);
    if (node == NULL)
    {
        ret = -1;
        return ret;
    }
    item = node->item;
    if (node != NULL)
    {
        free(node);
        node = NULL;
    }
    return item;
}

void *LinkQueue_Header(LinkQueue *queue)
{
    int ret = 0;
    void *item = NULL;
    TLinkQueueNode *node = NULL;
    node = (TLinkQueueNode *)linkListGet(queue, 0);
    if (node == NULL)
    {
        return NULL;
    }
    item = node->item;
    return item;
}

int LinkQueue_Length(LinkQueue *queue)
{
    return linkListLength(queue);
}
