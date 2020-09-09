#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

typedef struct _tag_LinkList
{
    LinkListNode header;
    int length;
}TLinkList;

LinkList *linkListCreate()
{
    TLinkList* tmp = (TLinkList *)malloc(sizeof(TLinkList));
    if(tmp == NULL)
    {
        return NULL;
    }
    tmp->length = 0;
    tmp->header.next = NULL;
    return (LinkList*)tmp;
}

void linkListDestroy(LinkList *list)
{
    if (list == NULL)
    {
        return;
    }
    free(list);
    return;
}

void linkListClear(LinkList *list)
{
    TLinkList *tlist = NULL;
    if (list == NULL)
    {
        return;
    }
    tlist = (TLinkList *)list;
    tlist->header.next = NULL;
    tlist->length = 0;
    return;
}

int linkListLength(LinkList *list)
{
    TLinkList *tlist = NULL;
    if (list == NULL)
    {
        return -1;
    }
    tlist = (TLinkList *)list;

    return tlist->length;
}

int linkListInsert(LinkList *list, LinkListNode *node, int pos)
{
    TLinkList* tlist = (TLinkList *)list;
    LinkListNode* pre = &tlist->header;
    int i = 0;

    for(i = 0; i < pos && (pre->next != NULL); i++)
    {
        pre = pre->next;
    }

    node->next = pre->next;
    pre->next = node;
    tlist->length++;
    return 0;
}

LinkListNode *linkListGet(LinkList *list, int pos)
{
    TLinkList* tlist = (TLinkList*)list;
    LinkListNode* node = &tlist->header;
    LinkListNode* ret = NULL;
    int i = 0;
    if (list == NULL || pos < 0 || pos >= tlist->length)
    {
        return NULL;
    }

    for(i = 0; i < pos && (node->next != NULL); i++)
    {
        node = node->next;
    }
    ret = node->next;

    return ret;
}

LinkListNode *linkListDelete(LinkList *list, int pos)
{
    int i = 0;

    TLinkList *tList = NULL;
    LinkListNode *current = NULL;
    LinkListNode *ret = NULL;
    tList = (TLinkList *)list;

    if (list == NULL || pos <0 || pos >= tList->length)
    {
        return NULL;
    }
    //准备环境让辅助指针变量 指向链表头节点
    current = &tList->header;
    for (i = 0; i<pos && (current->next != NULL); i++)
    {
        current = current->next;
    }
    ret = current->next;

    //删除算法
    current->next = ret->next;
    tList->length--;

    return ret;
}
