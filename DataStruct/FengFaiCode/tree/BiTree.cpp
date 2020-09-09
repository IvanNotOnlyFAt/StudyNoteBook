/*************************************************************************
    > File Name: BiTree.c
    > Author: Nfh
    > Mail: 1024222310@qq.com
    > Created Time: 2020年08月07日 星期五 14时48分57秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stack>
#include <queue>

using namespace std;

typedef char DType;

typedef struct BiNode
{
    DType data;
    struct BiNode *lchild;
    struct BiNode *rchild;
}BiNode, *BiTree;

// 创建节点
BiNode *createNode(DType data)
{
    BiNode *node = (BiNode *)malloc(sizeof(BiNode));
    assert(node != NULL);
    memset(node, 0, sizeof(BiNode));
    node->data = data;
    node->lchild = NULL;
    node->rchild = NULL;

    return node;
}

// 先序创建二叉树
int createBiTree(BiTree *t)
{
    DType data;
    scanf("%c", &data);
    if(data == ' ')
        *t = NULL;
    else
    {
        (*t) = createNode(data);
        createBiTree(&((*t)->lchild));
        createBiTree(&((*t)->rchild));
    }
    return 1;
}

// 后序销毁二叉树
void destroyTree(BiTree t)
{
    if(t == NULL)
        return ;
    if(t->lchild != NULL)
    {
        destroyTree(t->lchild);
        t->lchild = NULL;
    }
    if(t->rchild != NULL)
    {
        destroyTree(t->rchild);
    }
    free(t);
    t = NULL;
}
//=====================递归打印======================//
// 先序遍历打印二叉树
void prePrintTree(BiTree t)
{
    if(t == NULL)
    {
        return ;
    }
    printf("%c ", t->data);
    prePrintTree(t->lchild);
    prePrintTree(t->rchild);
}

// 中序打印二叉树
void inPrintTree(BiTree t)
{
    if(t == NULL)
    {
        return ;
    }
    inPrintTree(t->lchild);
    printf("%c ", t->data);
    inPrintTree(t->rchild);
}

// 后序打印二叉树
void nextPrintTree(BiTree t)
{
    if(t == NULL)
    {
        return ;
    }
    nextPrintTree(t->lchild);
    nextPrintTree(t->rchild);
    printf("%c ", t->data);
}

//=====================迭代打印======================//
// 先序遍历
void prePrintTreeWhile(BiTree t)
{
    if(t == NULL)
        return ;
    BiNode *p = t;
    BiNode *rchild = NULL;
    stack<BiNode *> stack_;
    do{
        printf("%c ", p->data);
        rchild = p->rchild;
        if(rchild != NULL)
        {
            stack_.push(rchild);
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

    printf("\n");
    return ;
}

// 中序遍历
void inPrintTreeWhile(BiTree t)
{
    if(t == NULL)
        return;
    BiNode *p = t;
    stack<BiNode *> stack_;
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
            printf("%c ", p->data);
            p = p->rchild;
        }
    }while(!stack_.empty());
    printf("\n");
}

// 后序遍历
void nextPrintTreeWhile(BiTree t)
{
    if(t == NULL)
        return ;

    typedef struct
    {
        BiNode *node;
        int flag;
    }BiNodeF;   // 封装这个结构体的目的是为了保证在遍历树的每个节点时不会被重复访问

    BiNode *p = t;
    stack<BiNodeF> stack_;
    do{
        while(p != NULL)
        {
            BiNodeF pf = {p, 1};
            stack_.push(pf);
            p = p->lchild;
        }
        if(!stack_.empty())
        {
            BiNodeF *pfn = &(stack_.top());
            p = pfn->node;
            if(p->rchild != NULL && pfn->flag != 0)
            {
                p = p->rchild;
                pfn->flag = 0;
            }else
            {
                printf("%c ", p->data);
                stack_.pop();
                p = NULL;
            }
        }
    }while(!stack_.empty());
    printf("\n");
}

// 层次遍历
void levelPrintTree(BiTree t)
{
    if(t == NULL)
        return ;
    BiNode *p = t;
    queue<BiNode *> queue_;
    queue_.push(p);
    while(!queue_.empty())
    {
        p = queue_.front();
        queue_.pop();
        printf("%c ", p->data);
        if(p->lchild != NULL)
        {
            queue_.push(p->lchild);
        }
        if(p->rchild != NULL)
        {
            queue_.push(p->rchild);
        }
    }
    printf("\n");
}

// 计算二叉树节点的个数,2种方法
// 如果二叉树为空，节点个数为0
// 如果二叉树不为空，二叉树节点个数 = 左子树节点个数 + 右子树节点个数 + 1
int countToTree1(BiTree t)
{
   if(t == NULL)
       return 0;
   else
       return countToTree1(t->lchild) + countToTree1(t->rchild) + 1;
}

void countToTree2(BiTree t, int *sum)
{
    if(t != NULL)
        (*sum)++;
    else
        return;
    countToTree2(t->lchild, sum);
    countToTree2(t->rchild, sum);
}

// 计算叶子节点的个数,2种方法
void countLeaf1(BiTree t, int *sum)
{
    if(t == NULL)
        return ;
    if(t->lchild == NULL && t->rchild == NULL)
    {
        (*sum)++;
    }
    if(t->lchild != NULL)
    {
        countLeaf1(t->lchild, sum);
    }
    if(t->rchild != NULL)
    {
        countLeaf1(t->rchild, sum);
    }
}

// 如果二叉树为空，返回0；
// 如果二叉树不为空且左右子树为空，返回1；
// 如果二叉树不为空，且左右子树不同时为空，返回左子树中叶子节点个数加上右子树中叶子节点个数。
int countLeaf2(BiTree t)
{
    if(t == NULL)
        return 0;
    if(t->lchild == NULL && t->rchild == NULL)
        return 1;
    int lc = countLeaf2(t->lchild);
    int rc = countLeaf2(t->rchild);
    return lc + rc;
}

// 求二叉树第k层节点的数
// 如果二叉树为空或者k<1返回0
// 如果二叉树不为空并且k==1，返回1
// 如果二叉树不为空且k>1，返回左子树中k-1层的节点个数与右子树k-1层节点个数之和
int getKCount(BiTree t, int k)
{
    if(t == NULL || k <= 0)
        return 0;
    if(k == 1)
        return 1;

    int LeftNum = getKCount(t->lchild, k-1);
    int RightNum = getKCount(t->rchild, k-1);
    
    int ret = LeftNum+RightNum;
    return ret;
}

// 计算树的深度
// 如果二叉树为空，二叉树的深度为0
// 如果二叉树不为空，二叉树的深度 = max(左子树深度， 右子树深度) + 1
int depthToTree(BiTree t)
{
    if(t == NULL)
        return 0;
    int maxdepth = depthToTree(t->lchild) > depthToTree(t->rchild) 
            ? depthToTree(t->lchild) 
            : depthToTree(t->rchild);
    return maxdepth + 1;
}


// 拷贝二叉树
BiTree copyTree(BiTree tp)
{
    if(tp == NULL)
        return NULL;
    BiNode *newtp = NULL;
    BiNode *newlp = NULL;
    BiNode *newrp = NULL;

    if(tp->lchild != NULL)
    {
        newlp = copyTree(tp->lchild);
    }
    if(tp->rchild != NULL)
    {
        newrp = copyTree(tp->rchild);
    }
    newtp = createNode(tp->data);
    newtp->lchild = newlp;
    newtp->rchild = newrp;
    return newtp;
}

int main()
{
    BiTree tree = NULL;
    // 两个测试案例
    // "ABC  DE G  F   "
    // "-+a  *b  -c  d  /e  f  "
    printf("给出两个测试案例( 注意:<>里面的是测试数据，不包括<> )：\n");
	printf("<ABC  DE G  F   >\n");
	printf("<-+a  *b  -c  d  /e  f  >\n");
	printf("=============> 请输入：\n");
	// 创建二叉树
    int ret = createBiTree(&tree);

    printf("==============递归遍历================\n");
	printf("前序遍历：");
    prePrintTree(tree);     // 前序遍历
    printf("\n");
	printf("中序遍历：");
    inPrintTree(tree);      // 中序遍历
    printf("\n");
	printf("后序遍历：");
    nextPrintTree(tree);    // 后序遍历
    printf("\n");

    printf("==============迭代遍历================\n");
	printf("前序遍历：");
    prePrintTreeWhile(tree);    // 前序遍历
	printf("中序遍历：");
    inPrintTreeWhile(tree);     // 中序遍历
	printf("后序遍历：");
    nextPrintTreeWhile(tree);	// 后序遍历
	printf("层次遍历：");
    levelPrintTree(tree);       // 层次遍历
    if(tree != NULL)
    {
        int sum = 0;
        
        sum = countToTree1(tree);
        printf("(1)节点的个数为：%d\n", sum);
        sum = 0;
        countToTree2(tree, &sum);
        printf("(2)节点的个数为：%d\n", sum);
        
        sum = 0;
        countLeaf1(tree, &sum);
        printf("(1)叶子节点的个数为：%d\n", sum);
        sum = countLeaf2(tree);
        printf("(2)叶子节点的个数为：%d\n", sum);
        
        sum = depthToTree(tree);
        printf("(1)树的度为：%d\n", sum);
    }

    BiTree copy_tree = copyTree(tree);  // 拷贝二叉树
    printf("copy后的二叉树前序遍历结果：");
	prePrintTree(copy_tree);
    printf("\n");

    int k;
    printf("请输入需要查找节点数目的层数：\n");
    scanf("%d", &k);
    printf("第[ %d ]层的节点数为：%d\n", k, getKCount(tree, k));

    // 销毁二叉树
    destroyTree(tree);
    destroyTree(copy_tree);
    return 0;
}

