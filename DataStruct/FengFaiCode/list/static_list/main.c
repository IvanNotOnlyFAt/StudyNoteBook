#include "list.h"

typedef struct node
{
    int id;
    char name[20];
} Node;

typedef struct Person
{
    int id;
    int sex;
} Person;

int main()
{
    SeqList* list = seqListCreate(10);

    int ret, i;
    Node arr_node[2] = {{1, "xiao"}, {2, "da"}};
    Person arr_person[2] = {{3, 1}, {4, 0}};
    int arr_int[2] = {10, 8};

    for(i = 0; i < 2; i++)
    {
        ret = seqListInsert(list, (SeqListNode*)(arr_node + i), 0);
    }
    for(i = 0; i < 2; i++)
    {
        ret = seqListInsert(list, (SeqListNode*)(arr_person + i), 0);
    }
    for(i = 0; i < 2; i++)
    {
        ret = seqListInsert(list, (SeqListNode*)(arr_int + i), 0);
    }

    printf("list len: %d\n", seqListLength(list));
    printf("list capacity: %d\n", seqListCapacity(list));


    for(i = 0; i < 2; i++)
    {
        int *p = (int *)seqListGet(list, i);
        printf("arr_int: %d\n", *p);
    }
    for(; i < seqListLength(list) - 2; i++)
    {
        Person* node = (Person*)seqListGet(list, i);
        printf("Pnode id: %d, sex: %d\n", node->id, node->sex);
    }

    for(; i < seqListLength(list); i++)
    {
        Node* node = (Node*)seqListGet(list, i);
        printf("Node id: %d, name: %s\n", node->id, node->name);
    }

    seqListDestroy(list);

    return 0;
}
