#ifndef LIST_H
#define LIST_H

typedef void SeqList;
typedef void SeqListNode;

SeqList* seqListCreate(int capacity);   // 创建一个线性表

void seqListDestroy(SeqList* list);     // 销毁线性表

void seqListClear(SeqList* list);       // 清空线性表

int seqListLength(SeqList* list);       // 返回线性表长度

int seqListCapacity(SeqList* list);     // 返回线性表容量

int seqListInsert(SeqList* list, SeqListNode* node, int pos);  //向线性表中添加元素

SeqListNode* seqListGet(SeqList* list, int pos);    // 获取pos位置的节点

SeqListNode* seqListDelete(SeqList* list, int pos); // 删除pos位置的节点并返回

#endif // LIST_H
