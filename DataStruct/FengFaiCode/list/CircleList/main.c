#include "circlelist.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct ValueInt
{
    CircleListNode node;
    int v;
}ValueInt;

void testCircleList()
{
    int i = 0;
    CircleList *tlist = CircleList_Create();
    for(i = 0; i < 10; i++)
    {
        ValueInt *vi = (ValueInt *)malloc(sizeof(ValueInt));
        vi->v = i;
        CircleList_Insert(tlist, (CircleListNode *)vi, 0);
    }

    for(i = 0; i < 2*CircleList_Length(tlist); i++) //怎么样证明是循环链表
    {
        ValueInt* pv = (ValueInt*)CircleList_Get(tlist, i);
        if(i == CircleList_Length(tlist))
            printf("\n");
        printf("%d  ", pv->v);
    }
    printf("\n");

    CircleList_Destroy(tlist);
    return ;
}

// 约瑟夫环
void ysfQuetion()
{
    int i = 0;
    CircleList* list = CircleList_Create();

    ValueInt v1, v2, v3, v4, v5, v6, v7, v8;

    v1.v = 1;	v2.v = 2;	v3.v = 3;	v4.v = 4;
    v5.v = 5;	v6.v = 6;	v7.v = 7;	v8.v = 8;

    CircleList_Insert(list, (CircleListNode*)&v1, CircleList_Length(list));
    CircleList_Insert(list, (CircleListNode*)&v2, CircleList_Length(list));
    CircleList_Insert(list, (CircleListNode*)&v3, CircleList_Length(list));
    CircleList_Insert(list, (CircleListNode*)&v4, CircleList_Length(list));
    CircleList_Insert(list, (CircleListNode*)&v5, CircleList_Length(list));
    CircleList_Insert(list, (CircleListNode*)&v6, CircleList_Length(list));
    CircleList_Insert(list, (CircleListNode*)&v7, CircleList_Length(list));
    CircleList_Insert(list, (CircleListNode*)&v8, CircleList_Length(list));


    for(i=0; i<CircleList_Length(list); i++)
    {
        //获取游标所指元素,然后游标下移
        ValueInt* pv = (ValueInt*)CircleList_Next(list);
        printf("%d\n", pv->v);
    }

    printf("\n");


    //重置游标
    CircleList_Reset(list);

    while( CircleList_Length(list) > 0 )
    {
        ValueInt *pv = NULL;
        for(i=1; i<3; i++)
        {
            CircleList_Next(list);
        }
        pv = (ValueInt*)CircleList_Current(list);
        printf("%d\n", pv->v);
        CircleList_DeleteNode(list, (CircleListNode*)pv);
    }

    free(list);

    return ;
}

int main()
{
    //testCircleList();
    printf("--------------------------------------\n");
    ysfQuetion();

    return 0;
}
