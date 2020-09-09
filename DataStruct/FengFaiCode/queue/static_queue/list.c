#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "list.h"

typedef struct _tag_SeqList
{
    int length;
    int capacity;
    SeqListNode** node;
}TSeqList;

SeqList *seqListCreate(int capacity)
{
    TSeqList* tmp = (TSeqList* )malloc(sizeof(TSeqList));
    if(tmp == NULL)
    {
        printf("seqListCreate errno\n");
        return NULL;
    }
    memset(tmp, 0, sizeof(TSeqList));
    tmp->node = (SeqListNode**)malloc(sizeof(SeqListNode*) * capacity);
    if(tmp->node == NULL)
    {
        printf("seqListCreate tmp->node errno\n");
        return NULL;
    }

    tmp->capacity = capacity;
    tmp->length = 0;
    return (SeqList*)tmp;
}

void seqListDestroy(SeqList *list)
{
    TSeqList* tlist = (TSeqList*)list;
    if(list == NULL)
    {
        printf("seqListDestroy errno \n");
        return ;
    }
    if(tlist->node != NULL)
    {
        free(tlist->node);
    }
    free(tlist);

    return ;
}

void seqListClear(SeqList *list)
{
    TSeqList* tlist = (TSeqList*)list;
    if(list == NULL)
    {
        printf("seqListDestroy errno \n");
        return ;
    }
    tlist->length = 0;
    return ;
}

int seqListLength(SeqList *list)
{
    TSeqList* tlist = (TSeqList*)list;
    if(list == NULL)
    {
        printf("seqListLength errno \n");
        return -1;
    }
    return tlist->length;
}

int seqListCapacity(SeqList *list)
{
    TSeqList* tlist = (TSeqList*)list;
    if(list == NULL)
    {
        printf("seqListCapacity errno \n");
        return -1;
    }
    return tlist->capacity;
}

int seqListInsert(SeqList *list, SeqListNode *node, int pos)
{
    int i;
    TSeqList* tlist = (TSeqList*)list;
    if(list == NULL || node == NULL || pos < 0)
    {
        printf("seqListInsert errno\n");
        return -1;
    }
    if(tlist->length >= tlist->capacity)
    {
        printf("seqListInsert errno\n");
        return -2;
    }
    if(pos >= tlist->length)
    {
        pos = tlist->length;
    }
    for(i = tlist->length; i > pos; i--)
    {
        tlist->node[i] = tlist->node[i - 1];
    }
    tlist->node[pos] = node;
    tlist->length++;
    return 0;
}

SeqListNode *seqListGet(SeqList *list, int pos)
{
    SeqListNode* ret = NULL;
    TSeqList* tlist = (TSeqList*)list;
    if(list == NULL || pos < 0)
    {
        printf("seqListGet errno\n");
        return NULL;
    }

    ret = tlist->node[pos];
    return ret;
}

SeqListNode *seqListDelete(SeqList *list, int pos)
{
    int i = 0;
    SeqListNode* ret = NULL;
    TSeqList* tlist = (TSeqList*)list;
    if(list == NULL || pos < 0)
    {
        printf("seqListDelete errno\n");
        return NULL;
    }

    ret = tlist->node[pos];

    for(i = pos + 1; i < tlist->length; i++)
    {
        tlist->node[i - 1] = tlist->node[i];
    }
    tlist->length--;
    return ret;
}


