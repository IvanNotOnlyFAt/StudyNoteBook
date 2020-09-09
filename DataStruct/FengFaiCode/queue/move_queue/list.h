#ifndef LIST_H
#define LIST_H

typedef void LinkList;

typedef struct _tag_LinkListNode
{
    struct _tag_LinkListNode* next;
}LinkListNode;

LinkList* linkListCreate();

void linkListDestroy(LinkList* list);

void linkListClear(LinkList* list);

int linkListLength(LinkList* list);

int linkListInsert(LinkList* list, LinkListNode* node, int pos);

LinkListNode* linkListGet(LinkList* list, int pos);

LinkListNode* linkListDelete(LinkList* list, int pos);

#endif // LIST_H
