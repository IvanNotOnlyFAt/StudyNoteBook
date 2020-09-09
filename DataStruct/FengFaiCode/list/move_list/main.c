#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

typedef struct Teacher
{
    LinkListNode node;
    char name[64];
    int age;
}Teacher;

int main()
{
    Teacher	t1, t2, t3;
    int	i = 0, len;

    LinkList *list = NULL;
    t1.age = 31;
    t2.age = 32;
    t3.age = 33;

    list = linkListCreate();
    len = linkListLength(list);

    //业务节点是teacher和算法分类的。。。。思想
    linkListInsert(list, &t1.node, 0);
    linkListInsert(list, &t2.node, 0);
    linkListInsert(list, &t3.node, 0);

    //遍历链表
    for (i = 0; i < linkListLength(list); i++)
    {
        Teacher *tmp = (Teacher *)linkListGet(list, i);
        if (tmp != NULL)
        {
            printf("age:%d\n", tmp->age);
        }
    }

    while (linkListLength(list) > 0)
    {
        Teacher *tmp = (Teacher *)linkListDelete(list, 0);
        if (tmp != NULL)
        {
            printf("age:%d ", tmp->age);
        }
    }
    printf("\n");
    linkListDestroy(list);

    return 0;
}
