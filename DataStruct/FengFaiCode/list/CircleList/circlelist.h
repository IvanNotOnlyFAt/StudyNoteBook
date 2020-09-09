#ifndef CIRCLELIST_H
#define CIRCLELIST_H

typedef void CircleList;

typedef struct _tag_CircleListNode
{
    struct _tag_CircleListNode * next;
}CircleListNode;

CircleList* CircleList_Create();

void CircleList_Destroy(CircleList* list);

void CircleList_Clear(CircleList* list);

int CircleList_Length(CircleList* list);

int CircleList_Insert(CircleList* list, CircleListNode* node, int pos);

CircleListNode* CircleList_Get(CircleList* list, int pos);

CircleListNode* CircleList_Delete(CircleList* list, int pos);

//add

//直接指定删除链表中的某个数据元素
CircleListNode* CircleList_DeleteNode(CircleList* list, CircleListNode* node);

//将游标重置指向链表中的第一个元素
CircleListNode* CircleList_Reset(CircleList* list);

//获取当前游标指向的数据元素
CircleListNode* CircleList_Current(CircleList* list);

//将游标移动指向链表中的下一个数据元素
CircleListNode* CircleList_Next(CircleList* list);

#endif // CIRCLELIST_H
