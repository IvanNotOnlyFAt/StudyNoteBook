/*************************************************************************
    > File Name: threadTree.cpp
    > Author: Nfh
    > Mail: 1024222310@qq.com
    > Created Time: 2020年08月10日 星期一 09时15分23秒
 ************************************************************************/

#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>

using namespace std;

typedef char DType;

enum PointerTag
{
    Link,       // Link = 0，表示指针
    Thread      // Thread = 1, 表示线索
};
typedef struct BiThrNode
{
    DType data;
    struct BiThrNode *lchild;
    struct BiThrNode *rchild;
    PointerTag LTag;    // 左，前驱
    PointerTag RTag;    // 右，后继
}BiThrNode, *BiThrTree;

// 创建节点
BiThrNode *createNode(DType data)
{
    BiThrNode *node = (BiThrNode *)malloc(sizeof(BiThrNode));
    assert(node != NULL);
    memset(node, 0, sizeof(BiThrNode));
    node->data = data;
    node->lchild = NULL;
    node->rchild = NULL;

    return node;
}

// 先序创建二叉树
int preCreateTree(BiThrTree *t)
{
    DType data;
    scanf("%c", &data);
    if(data == ' ')
        (*t) = NULL;
    else
    {
        (*t) = createNode(data);
        preCreateTree(&((*t)->lchild));
        preCreateTree(&((*t)->rchild));
    }
    return 1;
}

// 中序线索化
void inThreading(BiThrTree p, BiThrNode **pre)
{
    if(p != NULL)
    {
        inThreading(p->lchild, pre);   // 左子树线索化
        if(p->lchild == NULL)           // 前驱线索
        {
            p->LTag = Thread;
            p->lchild = (*pre);
        }
        if((*pre)->rchild == NULL)      // 后驱线索
        {
            (*pre)->RTag = Thread;
            (*pre)->rchild = p;
        }
        (*pre) = p;                     // 保持pre指向p的前驱
        inThreading(p->rchild, pre);   // 右子树线索化
    }
}

BiThrTree inOrderThreadTree(BiThrTree t)
{   // 中序遍历二叉树，并将其中中序线索化，thrt指向头结点
    BiThrTree thrt = (BiThrTree)malloc(sizeof(BiThrNode));
    assert(thrt != NULL);
    BiThrNode *pre = NULL;
    thrt->LTag = Link;
    thrt->RTag = Thread;
    thrt->rchild = thrt;        // 右指针回指
    if(t == NULL)               // 若二叉树为空，则左指针回指
        thrt->lchild = thrt;
    else
    {
        thrt->lchild = t;
        pre = thrt;
        inThreading(t, &pre);   // 中序遍历 进行中序线索化
        pre->rchild = thrt;     // 最后一个节点线索化
        pre->RTag = Thread;
        thrt->lchild = pre;
    }
    return thrt;
}



// 打印中序线索二叉树
void inPrintThreadTree(BiThrTree t)
{
    BiThrNode *p = t->lchild;
    while (p != t) {
        while(p->LTag == Link)
            p = p->lchild;
        printf("%c ", p->data);
        while(p->RTag == Thread && p->rchild != t)
        {
            p = p->rchild;
            printf("%c ", p->data);
        }
        p = p->rchild;
    }
    printf("\n");
}

int main()
{
    BiThrTree tree = NULL;
    // 两个测试案例
    // "ABC  DE G  F   "
    // "-+a  *b  -c  d  /e  f  "
    printf("给出两个测试案例( 注意:<>里面的是测试数据，不包括<> )：\n");
    printf("<ABC  DE G  F   >\n");
    printf("<-+a  *b  -c  d  /e  f  >\n");
    printf("=============> 请输入：\n");
    // 创建二叉树
    int ret = preCreateTree(&tree);
    BiThrTree intree = inOrderThreadTree(tree);     // 中序线索化
    printf("打印中序线索化二叉树：");
    inPrintThreadTree(intree);

    return 0;
}

