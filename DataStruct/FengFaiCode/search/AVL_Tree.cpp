#include <iostream>
#include <cstdlib>
#include <queue>

#define LH +1       //左高
#define EH 0        //等高
#define RH -1       //右高

using namespace std;

typedef struct AVLNode{
	int item;
	int bf;                         //结点的平衡因子
	struct AVLNode *lchild, *rchild;
}AVLNode;

//右旋
void RightRotate(AVLNode **p)
{
	AVLNode *lc = (*p)->lchild;
	(*p)->lchild = lc->rchild;
	lc->rchild = *p;
	*p = lc;
}

//左旋
void LeftRotate(AVLNode **p)
{
	AVLNode *rc = (*p)->rchild;
	(*p)->rchild = rc->lchild;
	rc->lchild = *p;
	*p = rc;
}

//左平衡处理
void LeftBalance(AVLNode **p)
{
	//对以指针p为根节点的二叉树做左平衡处理，本算法结束后
	//指针p指向新的结点
	AVLNode *lc = (*p)->lchild;
	AVLNode *rd = NULL;
	switch (lc->bf)					// 检查*p的左子树的平衡度，并作相应的处理
	{
	case LH:						// 新结点插入在*p的左孩子的左子树上，要做单右旋处理
		(*p)->bf = lc->bf = EH;
		RightRotate(p); break;
	case RH:						// 新结点插入在*p的左孩子的右子树上，要做双旋处理
		rd = lc->rchild;
		switch (rd->bf)				// 修改*p及其左孩子的平衡因子
		{
		case LH: (*p)->bf = RH; lc->bf = EH; break;
		case EH: (*p)->bf = lc->bf = EH;     break;
		case RH: (*p)->bf = EH; lc->bf = LH; break;
		}
		rd->bf = EH;
		LeftRotate(&((*p)->lchild));	// 对*p的左子树做左旋平衡处理
		RightRotate(p);					// 对*p做右旋平衡处理
	}
}

//右平衡处理
void RightBalance(AVLNode **p)
{
	AVLNode *rc = (*p)->rchild;
	AVLNode *ld = NULL;
	switch (rc->bf)
	{
	case RH:
		(*p)->bf = rc->bf = EH;
		LeftRotate(p); break;
	case LH:
		ld = rc->lchild;
		switch (ld->bf)
		{
		case LH: (*p)->bf = EH; rc->bf = RH; break;
		case EH: (*p)->bf = rc->bf = EH; break;
		case RH: (*p)->bf = LH; rc->bf = EH; break;
		}
		ld->bf = EH;
		RightRotate(&((*p)->rchild));
		LeftRotate(p);
	}
}

//创建节点
AVLNode *CreateNode(int item)
{
	AVLNode *node = (AVLNode *)malloc(sizeof(AVLNode));
	if (node == NULL)
	{
		cout << "malloc failed!" << endl;
		exit(1);
	}
	node->item = item;
	node->lchild = NULL;
	node->rchild = NULL;
	node->bf = EH;

	return node;
}

//插入结点
int InsertAVL(AVLNode **p, int item, bool *taller)
{
	//p指目前AVL树的树根
	//item为新节点的数据元素
	//taller用作旋转处理，反应p的长高与否
	if (*p == NULL)   //插入节点，树长高，置taller为true
	{
		*p = CreateNode(item);
		*taller = true;
	}
	else
	{
		AVLNode *pr = *p;
		if (item == pr->item)		// 树种已存在和item相同关键字的节点则不插入
		{
			*taller = false;
			return 0;
		}
		else if (item < pr->item)	// 否则搜索左子树
		{
			if (!InsertAVL(&(pr->lchild), item, taller))
				return 0;	
			if (*taller)			// 已插入到*p的左子树且左子树长高
			{
				switch (pr->bf)		// 检查*p的平衡度
				{
				case LH:			// 原来左子树比右子树高，需要左平衡处理
					LeftBalance(&pr); *taller = false; break;
				case EH:			// 原来左、右子树等高，现因左子树增高而使树增高
					pr->bf = LH; *taller = true; break;
				case RH:			// 原来右子树比左子树高，现在左右子树等高
					pr->bf = EH; *taller = false; break;
				}
			}
		}
		else
		{
			if (!InsertAVL(&(pr->rchild), item, taller))
				return 0;
			if (*taller)
			{
				switch (pr->bf)
				{
				case LH:			// 原来左子树比右子树高，现在左右子树等高
					pr->bf = EH; *taller = false; break;
				case EH:			// 原来左、右子树等高，现因右子树增高而使树增高
					pr->bf = RH; *taller = true; break;
				case RH:			// 原来右子树比左子树高，需要右平衡处理
					RightBalance(&pr); *taller = false; break;
				}
			}
		}
		*p = pr;
	}

	return 1;
}

//层次遍历
void indexPrint(AVLNode *p)
{
	if (p == NULL)
	{
		cout << "tree is NULL" << endl;
		return;
	}

	AVLNode *pr = p;
	queue<AVLNode *> qa;
	qa.push(p);
	cout << "元素\t平衡因子" << endl;
	do
	{
		if (!qa.empty())
		{
			pr = qa.front();
			qa.pop();
		}
		cout << pr->item << "\t" << pr->bf << endl;

		if (pr->lchild != NULL)
		{
			qa.push(pr->lchild);
		}
		if (pr->rchild != NULL)
		{
			qa.push(pr->rchild);
		}

	} while (!qa.empty());
}

// 计算树的深度
int depthToTree(AVLNode *node)
{
    if(node == NULL)
        return 0;
    int maxdepth = depthToTree(node->lchild) > depthToTree(node->rchild) 
            ? depthToTree(node->lchild) 
            : depthToTree(node->rchild);
    return maxdepth + 1;
}

// 判读一棵树是否为平衡二叉树
// 第一种方法：重复遍历
bool isAVLTree(AVLNode *t)
{
	if(t == NULL)
		return true;
	int lnum = depthToTree(t->lchild);
	int rnum = depthToTree(t->rchild);
	int num = lnum - rnum;
	if(num > 1 || num < -1)
		return false;

 	return isAVLTree(t->lchild)
	&& isAVLTree(t->rchild);
}

// 第二种方法：后序遍历每一个节点，并保存下深度
bool isAVLTree2(AVLNode *t, int *dept)
{
	if(t == NULL)
	{
		*dept = 0;
		return true;
	}
	int left, right;
	if(isAVLTree2(t->lchild, &left) 
			&& isAVLTree2(t->rchild, &right))
	{
		int num = left - right;
		if(num <= 1 && num >= -1)
		{
			*dept = 1 + (left > right ? left : right);
			return true;
		}
	}
	return false;
}

int main()
{
	AVLNode *tree = NULL;
	bool taller;
	int arr[] = { 13, 24, 37, 90, 53, 53, 12, 20, 15};
	int len = sizeof(arr) / sizeof(int);

	for (int i = 0; i < len; i++)
	{
		InsertAVL(&tree, arr[i], &taller);
	}
	/*树的结构：
	 *
	 *			 24
	 *			/  \
	 *		  13	53
	 *		 /  \  /  \
	 *     12   20 37  90
	 *          /
	 *         15
	 *
	 * */
	indexPrint(tree);
	if(isAVLTree(tree))
		printf("It is true\n");
	else
		printf("It is false\n");
	int dept = 0;
	if(isAVLTree2(tree, &dept))
		printf("It is true\n");
	else
		printf("It is false\n");
	return 0;
}

