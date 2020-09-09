/*************************************************************************
	> File Name: AVL.cpp
	> Author: Nfh
	> Mail: 1024222310@qq.com 
	> Created Time: 2020年08月13日 星期四 20时18分39秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include <queue>
using namespace std;
 
typedef struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
}BTNode;
 
int max(int a, int b);
 
// 返回节点的高度
int height(struct Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

// 返回最大值
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// 创建节点
BTNode* newNode(int key)
{
    struct Node* node = (BTNode*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return(node);
}

// 右旋
BTNode* ll_rotate(BTNode* y)
{
    BTNode *x = y->left;
    y->left = x->right;
    x->right = y;

    // 调整节点的高度
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
 
    return x;
}
 
// 左旋
BTNode* rr_rotate(BTNode* y)
{
    BTNode *x = y->right;
    y->right = x->left;
    x->left = y;

    // 调整节点的高度
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
 
    return x;
}

// 获取平衡因子
int getBalance(BTNode* N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

// 插入节点
BTNode* insert(BTNode* node, int key)
{
    if (node == NULL)
        return newNode(key);

    // 对需插入的节点进行比较
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;
 
    node->height = 1 + max(height(node->left), height(node->right));    // 设置节点的深度
  
    int balance = getBalance(node);                                     // 计算节点的平衡因子         

    if (balance > 1 && key < node->left->key)                           //LL型
        return ll_rotate(node);
    
    if (balance < -1 && key > node->right->key)                         //RR型
        return rr_rotate(node);
    
    if (balance > 1 && key > node->left->key)                           //LR型
    {
        // 先左旋，在右旋
        node->left = rr_rotate(node->left);
        return ll_rotate(node);
    }
 
    if (balance < -1 && key < node->right->key)                         //RL型
    {
        // 先右旋，在左旋
        node->right = ll_rotate(node->right);
        return rr_rotate(node);
    }
 
    return node;
}
 
// 返回关键字最小的节点
BTNode * minValueNode(BTNode* node)
{
    BTNode* current = node;
 
    while (current->left != NULL)
        current = current->left;
 
    return current;
}

// 删除节点
BTNode* deleteNode(BTNode* root, int key)
{
    if (root == NULL)
        return root;
 
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else{
        if ((root->left == NULL) || (root->right == NULL))
        {
            BTNode* temp = root->left ? root->left : root->right;

            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;
            free(temp);
        }else
        {
            BTNode* temp = minValueNode(root->right);
 
            root->key = temp->key;
 
            root->right = deleteNode(root->right, temp->key);
        }
    }
  
    if (root == NULL)
        return root;
 
    root->height = 1 + max(height(root->left), height(root->right));
 
    int balance = getBalance(root);
 
    if (balance > 1 && getBalance(root->left) >= 0) //LL型
        return ll_rotate(root);

    if (balance > 1 && getBalance(root->left) < 0) //LR型
    {
        root->left = rr_rotate(root->left);
        return ll_rotate(root);
    }
 
    if (balance < -1 && getBalance(root->right) <= 0) //RR型
        return rr_rotate(root);
 
    if (balance < -1 && getBalance(root->right) > 0)  //Rl型
    {
        root->right = ll_rotate(root->right);
        return rr_rotate(root);
    }
 
    return root;
}
 
// 先序遍历
void preOrder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// 层次遍历
void levelPrintTree(BTNode *t)
{
    if(t == NULL)
        return ;
    queue<BTNode *> queue_;
    BTNode *p = t;
    queue_.push(p);
    while (!queue_.empty()) {
        p = queue_.front();
        queue_.pop();
        printf("%d ", p->key);
        if(p->left != NULL)
            queue_.push(p->left);
        if(p->right != NULL)
            queue_.push(p->right);
    }
    printf("\n");
}

// 判断该树是否为平衡二叉树
bool isAVLTree(BTNode *t, int *dept)
{
    if(t == NULL)
    {
        *dept = 0;
        return true;
    }
    int left, right;
    if(isAVLTree(t->left, &left)
            && isAVLTree(t->right, &right))
    {
        int num = left - right;
        if(num >= -1 && num <= 1)
        {
            *dept = 1 + (left > right ? left : right);
            return true;
        }else 
        {
            return false;   
        }
    }
    return false;
}
 
int main()
{
    BTNode *root = NULL;
 
    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 0);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, -1);
    root = insert(root, 1);
    root = insert(root, 2);
    printf("前序遍历：");
    preOrder(root);
    printf("\n");
    printf("层次遍历：");
    levelPrintTree(root);
    printf("\n");
    int dept = 0;
    if(isAVLTree(root, &dept))
        printf("It is true\n");
    else
       printf("It is false\n");
 
    /* The constructed AVL Tree would be
                     9
                    /  \
                   1    10
                 /  \     \
                0    5     11
               /    /  \
              -1   2    6
    */
	
	// 测试删除节点
	int k;
	printf("请输入需要删除的节点：");
	scanf("%d", &k);
    root = deleteNode(root, k);
    
    printf("\n");
    printf("前序遍历：");
    preOrder(root);
    printf("\n");
    printf("层次遍历：");
    levelPrintTree(root);  
    printf("\n");

    dept = 0;
    if(isAVLTree(root, &dept))
        printf("It is true\n");
    else
       printf("It is false\n");
    
    return 0;
}
