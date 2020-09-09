#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "circlelist.h"

typedef struct _tag_CircleList
{
    CircleListNode header;
    CircleListNode* slider;     // 游标
    int length;
} TCircleList;

// 创建一个循环链表
CircleList *CircleList_Create()
{
    TCircleList *tmp = (TCircleList *)malloc(sizeof(TCircleList));
    if(tmp == NULL)
    {
        printf("CircleList_Create errno\n");
        return NULL;
    }
    tmp->header.next = NULL;
    tmp->slider = NULL;
    tmp->length = 0;

    return (CircleList *)tmp;
}

void CircleList_Destroy(CircleList *list)
{
    int i = 0;
    TCircleList *tlist = (TCircleList *)list;
    if(list != NULL)
    {
        CircleListNode *pre = &(tlist->header);
        for(i = 0; i < tlist->length; i++)
        {
            CircleListNode *node = pre->next;
            pre = pre->next;
            free(node);
        }
        CircleList_Clear((CircleList *)tlist);
        free(list);
    }
    return ;
}

void CircleList_Clear(CircleList *list)
{
    TCircleList *tlist = (TCircleList *)list;
    if(list != NULL)
    {
        tlist->length = 0;
        tlist->header.next = NULL;
        tlist->slider = NULL;
    }
    return;
}

int CircleList_Length(CircleList *list)
{
    TCircleList *tlist = (TCircleList *)list;
    if(list != NULL)
        return tlist->length;
    else
        return -1;
}

// 向链表中添加元素
int CircleList_Insert(CircleList *list, CircleListNode *node, int pos)
{
    int i = 0;
    TCircleList *tlist = (TCircleList *)list;
    if(tlist == NULL || node == NULL || pos < 0)
    {
        return -1;
    }
    CircleListNode* current = &(tlist->header);

    for(i = 0; (i < pos) && (current->next != NULL); i++)
    {
        current = current->next;
    }
    //current->next 0号节点的地址
    node->next = current->next;
    current->next = node;

    // 如果第一次插入节点
    if(tlist->length == 0)
    {
        tlist->slider = node;
        node->next = node;
    }

    tlist->length++;

    //若头插法 current仍然指向头部
    //（原因是：跳0步，没有跳走）
    if( current == &(tlist->header) )
    {
        //获取最后一个元素
        CircleListNode* last = CircleList_Get(tlist, tlist->length - 1);
        last->next = current->next; //3
    }
    return 1;
}

CircleListNode *CircleList_Get(CircleList *list, int pos)
{
    TCircleList *tlist = (TCircleList *)list;
    if(list == NULL || pos < 0)
    {
        return NULL;
    }
    int i = 0;
    CircleListNode *pre = &(tlist->header);
    for(i = 0; i < pos; i++)
    {
        pre = pre->next;
    }

    return pre->next;
}

CircleListNode *CircleList_Delete(CircleList *list, int pos)
{
    CircleListNode * node = NULL;
    CircleListNode* last = NULL;
    TCircleList *tlist = (TCircleList *)list;
    if(list == NULL || pos < 0 || tlist->length <= 0)
    {
        return NULL;
    }
    int i = 0;
    CircleListNode * pre = &(tlist->header);
    for(i = 0; i < pos; i++)
    {
        pre = pre->next;
    }

    node = pre->next;
    pre->next = node->next;
    tlist->length--;

    // 如果删除的是头结点
    if(pre == &(tlist->header))
    {
        //获取最后一个元素
        last = CircleList_Get(tlist, tlist->length - 1);
        last->next = node->next;
    }

    // 如果删除的是游标所指的
    if(node == tlist->slider)
    {
        tlist->slider = node->next;
    }

    // 如果链表为空
    if(tlist->length == 0)
    {
        tlist->header.next = NULL;
        tlist->slider = NULL;
    }

    return node;
}

//add

CircleListNode *CircleList_DeleteNode(CircleList *list, CircleListNode *node)
{
    TCircleList* sList = (TCircleList*)list;
    CircleListNode* ret = NULL;
    int i = 0;

    if( sList != NULL )
    {
        CircleListNode* current = (CircleListNode*)sList;

        //查找node在循环链表中的位置i
        for(i=0; i<sList->length; i++)
        {
            if( current->next == node )
            {
                ret = current->next;
                break;
            }

            current = current->next;
        }

        //如果ret找到，根据i去删除
        if( ret != NULL )
        {
            CircleList_Delete(sList, i);
        }
    }

    return ret;
}

// 重置游标
CircleListNode *CircleList_Reset(CircleList *list)
{
    TCircleList* sList = (TCircleList*)list;
    CircleListNode* ret = NULL;

    if( sList != NULL )
    {
        sList->slider = sList->header.next;
        ret = sList->slider;
    }

    return ret;
}

// 返回游标所指向的节点
CircleListNode *CircleList_Current(CircleList *list)
{
    TCircleList* sList = (TCircleList*)list;
    CircleListNode* ret = NULL;

    if( sList != NULL )
    {
        ret = sList->slider;
    }

    return ret;
}

// 把当前位置返回，游标后移
CircleListNode *CircleList_Next(CircleList *list)
{
    TCircleList* sList = (TCircleList*)list;
    CircleListNode* ret = NULL;

    if( (sList != NULL) && (sList->slider != NULL) )
    {
        ret = sList->slider;
        sList->slider = ret->next;
    }

    return ret;
}
