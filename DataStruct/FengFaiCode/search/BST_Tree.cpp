/*************************************************************************
    > File Name: BST_Tree.cpp
    > Author: Nfh
    > Mail: 1024222310@qq.com
    > Created Time: 2020年08月11日 星期二 09时22分07秒
 ************************************************************************/

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <stack>
#include <queue>

using namespace std;

typedef struct BstNode
{
    int data;
    struct BstNode *lchild;
    struct BstNode *rchild;
}BstNode, *BstTree;

// 创建节点
BstNode *createNode(int data)
{
    BstNode *node = (BstNode *)malloc(sizeof(BstNode));
    assert(node != NULL);
    node->data = data;
    node->lchild = NULL;
    node->rchild = NULL;
    return node;
}

// 向BST树添加元素(递归)
void insertToBstTree1(BstTree t, BstNode *node)
{
    if(node->data < t->data)
    {
        if(t->lchild == NULL)
        {
            t->lchild = node;
        }else
        {
            insertToBstTree1(t->lchild, node);
        }
    }else if(node->data > t->data)
    {
        if(t->rchild == NULL)
        {
            t->rchild = node;
        }else
        {
            insertToBstTree1(t->rchild, node);
        }
    }else
    {
        free(node);
        node = NULL;
    }
}

// 向BST树添加元素(迭代)
void insertToBstTree2(BstTree t, BstNode *node)
{
    BstNode *p = t;
    BstNode *pre = NULL;
    while(p != NULL)
    {
        pre = p;
        if(node->data < p->data)
        {
            p = p->lchild;
        }else if(node->data > p->data)
        {
            p = p->rchild;
        }else
        {
            free(node);
            node = NULL;
            return ;
        }
    }
    if(node->data < pre->data)
        pre->lchild = node;
    else
        pre->rchild = node;
}

// 创建BST树
void initBstTree(BstTree *t)
{
    int i = 0, n, num;
    printf("请输入初始化树的大小[0 - 100]：");
    scanf("%d", &n);
    if(n <= 0)
        return ;
    printf("请输入树的每个元素(需输入[%d]个)：\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &num);
        BstNode *node = createNode(num);
        if((*t) == NULL)
        {
            (*t) = node;
        }else
        {
            insertToBstTree2(*t, node);
        }
    }
}

//=========================递归===========================//
// 先序遍历
void prePrintBST1(BstTree t)
{
    if(t == NULL)
        return;
    printf("%d ", t->data);
    prePrintBST1(t->lchild);
    prePrintBST1(t->rchild);
}

// 中序遍历
void inPrintBST1(BstTree t)
{
    if(t == NULL)
        return;
    inPrintBST1(t->lchild);
    printf("%d ", t->data);
    inPrintBST1(t->rchild);
}

// 后序遍历
void nextPrintBST1(BstTree t)
{
    if(t == NULL)
        return;
    nextPrintBST1(t->lchild);
    nextPrintBST1(t->rchild);
    printf("%d ", t->data);
}

//=========================迭代===========================//
// 先序遍历
void prePrintBST2(BstTree t)
{
    if(t == NULL)
        return ;
    stack<BstNode *> stack_;
    BstNode *p = t;
    do{
        printf("%d ", p->data);
        if(p->rchild != NULL)
        {
            stack_.push(p->rchild);
        }
        p = p->lchild;
        if(p == NULL)
        {
            if(!stack_.empty())
            {
                p = stack_.top();
                stack_.pop();
            }
        }
    }while(p != NULL);
    return ;
}

// 中序遍历
void inPrintBST2(BstTree t)
{
    if(t == NULL)
        return ;
    stack<BstNode *> stack_;
    BstNode *p = t;
    stack_.push(p);
    do{
        if(!stack_.empty())
            stack_.pop();
        while(p != NULL)
        {
            stack_.push(p);
            p = p->lchild;
        }
        if(!stack_.empty())
        {
            p = stack_.top();
            printf("%d ", p->data);
            p = p->rchild;
        }
    }while(!stack_.empty());
    return ;
}

// 后序遍历
void nextPrintBST2(BstTree t)
{
    if(t == NULL)
        return ;
    typedef struct BstNodeF
    {
        BstNode *node;
        int flag;
    }BstNodeF;

    BstNode *p = t;
    stack<BstNodeF> stack_;

    do{
        while(p != NULL)
        {
            BstNodeF nf = {p, 1};
            stack_.push(nf);
            p = p->lchild;
        }
        if(!stack_.empty())
        {
            BstNodeF *nfp = &(stack_.top());
            p = nfp->node;
            if(p->rchild != NULL && nfp->flag != 0)
            {
                p = p->rchild;
                nfp->flag = 0;
            }else
            {
                printf("%d ", p->data);
                stack_.pop();
                p = NULL;
            }
        }
    }while(!stack_.empty());
}

// 层次遍历
void levelPrintBST(BstTree t)
{
    if(t == NULL)
        return ;
    queue<BstNode *> queue_;
    BstNode *p = t;
    queue_.push(p);

    while(!queue_.empty())
    {
        p = queue_.front();
        queue_.pop();
        printf("%d ", p->data);
        if(p->lchild != NULL)
        {
            queue_.push(p->lchild);
        }
        if(p->rchild != NULL)
        {
            queue_.push(p->rchild);
        }
    }
}

// 二叉树的查找
BstNode *searchToBST(BstTree t, int value)
{
    if(t == NULL)
        return NULL;
    if(value == t->data)
    {
        return t;
    }else if(value < t->data)
    {
        return searchToBST(t->lchild, value);
    }else
    {
        return searchToBST(t->rchild, value);
    }
}

/*
    二叉节点的删除
*/
// 查找需要删除的节点的父节点
BstNode *searchFatherNode(BstTree t, int value, int *pos)
{
    BstNode *p = t;
    BstNode *pre = p;
    *pos = 0;

    while(p != NULL)
    {
        if(value == p->data)
        {
            return pre;
        }else
        {
            pre = p;
            if(value < p->data)
            {
                p = p->lchild;
                *pos = 1;
            }else if(value > p->data)
            {
                p = p->rchild;
                *pos = -1;
            }
        }
    }
    return NULL;
}

// 删除值为value的节点
void deleteNodeToBST(BstTree t, int value)
{
    BstNode *backfather = NULL;
    BstNode *pr = t;
    BstNode *next = NULL;
    int pos;    // 用来判断删除的节点是左子树还是右子树还是根节点

    backfather = searchFatherNode(t, value, &pos);
    if(backfather == NULL)
        return ;

    switch(pos)
    {
    case 1: pr = backfather->lchild; break;
    case -1: pr = backfather->rchild; break;
    case 0: break;
    }

    /*左子树为空或右子树为空*/
    if(pr->lchild == NULL || pr->rchild == NULL)
    {
        if(pos == 0)	// 删除根节点
        {
            if(pr->rchild != NULL)
            {
                t = t->rchild;
            }else
            {
                t = t->lchild;
            }
        }else if(pos < 0)
        {
            if(pr->lchild == NULL)
            {
                backfather->lchild = pr->rchild;
            }else
            {
                backfather->lchild = pr->lchild;
            }
        }else
        {
            if(pr->lchild == NULL)
            {
                backfather->rchild = pr->rchild;
            }else
            {
                backfather->rchild = pr->lchild;
            }
        }

        free(pr);
        return;
    }

    /*有左子树也有右子树的情况 */
    backfather = pr;  //父节点指向当前节点
    next = pr->lchild;   //设置子节点
    while (next->rchild != NULL)	// 在左子树中找到最大的值的节点
    {
        backfather = next;
        next = next->rchild;
    }
    pr->data = next->data;  //替换数据

    //把最右面的结点删除
    if (backfather->lchild == next)
    {
        backfather->lchild = next->lchild;
    }
    else
    {
        backfather->rchild = next->lchild;
    }

    free(next);

    return;
}

// 求二叉树叶子节点的数量
int leavesToTree(BstTree t)
{
    if(t == NULL)
        return 0;
    int sum = 0;
    BstNode *p = t;
    stack<BstNode *> stack_;

    do{
        if(p->lchild == NULL && p->rchild == NULL)
        {
            sum++;
        }
        if(p->rchild != NULL)
        {
            stack_.push(p->rchild);
        }
        p = p->lchild;
        if(p == NULL)
        {
            if(!stack_.empty())
            {
                p = stack_.top();
                stack_.pop();
            }
        }
    }while(p != NULL);

    return sum;
}

// 求二叉树的深度
int depthToTree(BstTree t)
{
    if(t == NULL)
        return 0;
    int sum = 0;
    BstNode *p = t;
    BstNode *bl = p;    // 用来追踪树中节点的变化
    BstNode *re = p;    // 用来表示本层的最后一个节点
    queue<BstNode *> queue_;
    queue_.push(p);
    while(!queue_.empty())
    {
        p = queue_.front();
        queue_.pop();
        if(p->lchild != NULL)
        {
            queue_.push(p->lchild);
            bl = p->lchild;
        }
        if(p->rchild != NULL)
        {
            queue_.push(p->rchild);
            bl = p->rchild;
        }

        if(p == re)
        {
            sum++;
            re = bl;
        }
    }

	return sum;
}


// 销毁二叉树（后序销毁）
void destoryTree(BstTree t)
{
    if(t == NULL)
        return ;
    else
    {
        destoryTree(t->lchild);
        destoryTree(t->rchild);
        free(t);
        t = NULL;
    }
}


int main()
{
    BstTree tree = NULL;
    initBstTree(&tree);
    printf("//=========================递归打印===========================//\n");
    printf("先序遍历：");
    prePrintBST1(tree);
    printf("\n");
    printf("中序遍历：");
    inPrintBST1(tree);
    printf("\n");
    printf("后序遍历：");
    nextPrintBST1(tree);
    printf("\n");

    printf("//=========================迭代打印===========================//\n");
    printf("先序遍历：");
    prePrintBST2(tree);
    printf("\n");
    printf("中序遍历：");
    inPrintBST2(tree);
    printf("\n");
    printf("后序遍历：");
    nextPrintBST2(tree);
    printf("\n");
    printf("层次遍历：");
    levelPrintBST(tree);
    printf("\n");
    printf("//=========================树的一些属性=========================//\n"); 
    printf("树的叶子节点的个数：");
    printf("%d\n", leavesToTree(tree));
    printf("树的深度为：");
    printf("%d\n", depthToTree(tree));

    int value;
    printf("请输入需要查找的元素：");
    scanf("%d", &value);
    BstNode *node = searchToBST(tree, value);
    if(node != NULL)
        printf("查找成功：[value] = %d\n", node->data);
    else
        printf("查找失败！\n");
    
    destoryTree(tree);
    return 0;
}

