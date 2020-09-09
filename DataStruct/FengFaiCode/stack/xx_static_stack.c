/*************************************************************************
    > File Name: xx_static_stack.c
    > Author: Nfh
    > Mail: 1024222310@qq.com 
    > Created Time: 2020年08月04日 星期二 09时53分20秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX 30              // 栈的基础长度
#define INSERTNUM 10        // 分配增量

typedef int SType;

typedef struct 
{
    SType *base;         // 栈底指针
    SType *top;          // 栈顶指针
    int stacksize;      // 栈的存储空间
}Stack;

// 初始化栈
int initStack(Stack *sp)
{
    sp->base = (SType *)malloc(MAX * sizeof(SType));
    assert(sp->base != NULL);
    sp->top = sp->base;
    sp->stacksize = MAX;
    return 1;
}

// 返回栈顶元素 
int getTop(Stack *sp, SType *e)
{
    if(sp->top == sp->base)
    {
        return 0;
    }
    *e = *(sp->top - 1);
    return 1;
}

// 向栈内添加元素
int push(Stack *sp, SType e)
{
    if(sp->top - sp->base >= sp->stacksize)
    {
        sp->base = (SType *)realloc(sp->base ,sizeof(SType) * (sp->stacksize + INSERTNUM));
        assert(sp->base != NULL);
        sp->top = sp->base + sp->stacksize;
        sp->stacksize += INSERTNUM;
    }
    *sp->top++ = e;
    return 1;
}

// 弹出栈顶元素
int pop(Stack *sp, SType *e)
{
    if(sp->top == sp->base)
        return 0;
    *e = *--sp->top;
    return 1;
}

// 清空栈
int clearStack(Stack *sp)
{
    sp->top = sp->base;
    return 1;
}

// 判断栈是否为空
int stackEmpty(Stack *sp)
{
    if(sp->top == sp->base)
        return 1;
    return 0;
}

// 销毁栈
int destoryStack(Stack *sp)
{
    if(sp->base != NULL)
    {
        sp->top = sp->base;
        sp->stacksize = 0;
        free(sp->base);
        return 1;
    }
    return 0;
}

// 返回栈内元素的个数
int stackLength(Stack *sp)
{
    if(sp->base != NULL)
    {
        return (sp->top - sp->base);
    }
    return -1;
}

int main()
{
    Stack sp;
    int arr[10] = {0}, i = 0;
    initStack(&sp);
    for(i = 0; i < 10; i++)
    {
        arr[i] = i + 1;
        push(&sp, arr[i]);
    }
    
    while(sp.base != sp.top)
    {
        int e;
        pop(&sp, &e);
        printf("%d  ", e);
    }
    printf("\n");

    return 0;
}
