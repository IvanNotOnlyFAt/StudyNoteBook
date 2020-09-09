#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct node
{
    int item;
    struct node *left;
    struct node *right;
}node;

node *stack[512];
int top = 0;

void init_stack()
{
    top = 0;
}

void push(node  *p)
{
    stack[top++] = p;
}

node  *pop(void)
{
    return stack[--top];
}

int is_empty(void)
{
    return top == 0;
}

node *root = NULL;

node *mk_node(int item)
{
    node *p = (node *)malloc(sizeof(node));
    if (p == NULL)
    {
        printf("malloc failed\n");
        exit(1);
    }

    p->item = item;
    p->left = NULL;
    p->right = NULL;

    return p;    
}

void free_node(node *p)
{
    free(p);
}

#if 0
//����ڵ� ����������
void insert_node(int item)
{
    node *pre;
    node *parent;
    node *p = mk_node(item);

    parent = pre = root;
    if (root == NULL)
    {
        root = p;
        return ;
    }

    while (pre != NULL)
    {
        parent = pre;
        if (item > pre->item)
        {
            pre = pre->right;
        }else if(item < pre->item)
        {
            pre = pre->left;
        }else
        {
            free_node(p);
            return;
        }
    }

    if (p->item > parent->item)
    {
        parent->right = p;
    }else
    {
        parent->left = p;
    }
}
#endif

#if 1
//����ڵ㣨�ݹ飩
void insert_node_r(node *current, node *p)
{
    if (p->item > current->item)
    {
        if (current->right == NULL)
        {
            current->right = p;
        }else
        {
            insert_node_r(current->right, p);     
        }
    }else if (p->item < current->item)
    {
        if (current->left == NULL)
        {
            current->left = p;
        }else
        {
            insert_node_r(current->left, p);         
        }
    }else
    {
        free_node(p);
    }
}
 
void insert_node(int item)
{
    node *p = mk_node(item);

    if (root == NULL)
    {
        root = p;
    }else
    {
        insert_node_r(root, p);   
    }
}
#endif

//�������
void traverse_m(node *p)
{
    if (p == NULL)
    {
        return ;
    }

    traverse_m(p->left);
    printf("%d ", p->item);
    traverse_m(p->right);
}

//ǰ�����
void traverse_b(node *p)
{
    if (p == NULL)
    {
        return ;
    }

    printf("%d ", p->item);
    traverse_b(p->left);
    traverse_b(p->right);
}

//��������
void traverse_a(node *p)
{
    if (p == NULL)
    {
        return;
    }

    traverse_a(p->left);
    traverse_a(p->right);
    printf("%d ", p->item);
}

//ǰ�������������
void pre_order_traverse()
{
    node *p = root;
    node *right;
    init_stack();

    if (root == NULL)
    {
        return;
    } 

    do
    {
        printf("%d ", p->item);

        right = p->right;
        if (right != NULL)
        {
            push(right);
        }
        p = p->left;
        if (p == NULL)
        {
            p = pop();
        }

    }while(p != NULL);
}

//���������������
void in_order_traverse()
{
    node *p = root;
    node *right;
    int is_empty_stack = 0;

    init_stack();
    if (root == NULL)
    {
        return;
    } 
	
    do
    {    
        while (p != NULL)
        {
            push(p);
            p = p->left;    
        }

        if (!is_empty())
        {
            p = pop();
            printf("%d ", p->item);
        
            p = p->right;
        }
        else
        {
            is_empty_stack = 1;
        }
   }while(!is_empty_stack);
}

#define MAX_NODE  50
//�������� ��������
void  post_order_traverse( )
{  
    node *s1[MAX_NODE];   //������
    node *p = root;
    int s2[MAX_NODE];     //S2�������״̬��־����tag    0 ������ݲ��ܷ���  1 �� �����Ա�����
    int top = 0;
    int is_empty_stack;

    if  (root == NULL)
    {
        printf("Binary Tree is Empty!\n") ;
        return;
    }     
   
    do
    {      
        while (p != NULL)
        {  
            s1[++top] = p ;   //��ջ
            s2[top] = 0 ;

            p = p->left ; 

            is_empty_stack = 0;  //ջ����
        }

        if  (top == 0)
        {
            is_empty_stack = 1;  //s1.s2ջ��
        }      
        else if (s2[top] == 0)   //s2��� 
        {   
            p = s1[top]->right;  
            s2[top] = 1 ;   
        }
        else 
        {  
            p = s1[top];            //��ջ
            top-- ;
            printf("%d ",  p->item); 
            p = NULL;                      
        }
    }while (!is_empty_stack);
    
}

//��α���
void  level_order_traverse()
{  
    node  *queue[MAX_NODE];
    node *p = root;
    int front = 0;
    int rear = 0;

    if  (root == NULL) 
    {  
        printf("Binary Tree is Empty!\n") ;
        return;
    }

    queue[rear++] = p;

    while (front < rear)
    {  
        p = queue[front++];

        printf("%d ", p->item);

        if (p->left != NULL)
        {
            queue[rear++] = p->left;    /*   �������  */
        }

        if (p->right != NULL)
        {
            queue[rear++] = p->right;    /*   �������  */
        }
    }    
}

//���������Ҷ�ӽ����
int search_leaves()
{
    node *p = root;
    node *right;
    int total  = 0;
    init_stack();

    if (root == NULL)
    {
        return 0;
    } 

    do
    {
        if (p->left == NULL  && p->right == NULL)
        {
            total++;
        }

        right = p->right;
        if (right != NULL)
        {
            push(right);
        }
        p = p->left;
        if (p == NULL)
        {
            p = pop();
        }

    }while(p != NULL);

    return total;
}

//������������ 
int  search_depth()
{  
    node  *queue[MAX_NODE];
    node *p = root;
    int front = 0;
    int rear = 0;
    int depth = 0;
    int level = 0;               /*  level����ָ����ʲ�����һ������ڶ��е�λ��  */

    if  (root == NULL) 
    {  
        printf("Binary Tree is Empty!\n") ;
        return 0;
    }

    queue[rear++] = p;
    level = rear;

    while (front < rear)
    {  
        p = queue[front++];

        //printf("%d ", p->item);

        if (p->left != NULL)
        {
            queue[rear++] = p->left;    /*   �������  */
        }

        if (p->right != NULL)
        {
            queue[rear++] = p->right;    /*   �ҽ�����  */
        }
    
        /*  �����ʵ��ǵ�ǰ������һ�����  */
        if (front == level)
        {  
            depth++;  
            level = rear;  
            //printf("\n");
        }
    }

    return depth;     
}

//�������Ĳ���
node *search_node(node *current, int item)
{
    if (item < current->item)
    {
        if (current->left == NULL)
        {
            return NULL;
        }
        return search_node(current->left, item);
    }else if(item > current->item)
    {
        if (current->right == NULL)
        {
            return NULL;
        }
        return search_node(current->right, item);
    }

    return current;
}


node *btree_find(int value, int *pos)
{
    node  *backfather;
    node  *ptr = root;

    backfather = root;          //���ø��ڵ�ָ���ֵ
    *pos = 0;                  //����λ�ó�ֵ

    while (ptr != NULL)
    {
        if (ptr->item == value)
        {
            return backfather;  //�ҵ��˷��ظ��ڵ�
        }
        else
        {
            backfather = ptr;
            if (ptr->item > value)
            {
                ptr = ptr->left;    //������
                *pos = -1;
            }
            else
            {
                ptr = ptr->right;   //������
                *pos = 1;
            }
        }
    }

    return NULL;
}

/*�������ڵ��ɾ��*/
void delete_node (int value)
{
    node *backfather;         //�����ָ��
    node *ptr;                //ɾ�����ָ��
    node *next;               //�ӽ��ָ��
    int pos;                  //ɾ��λ��

    backfather = btree_find(value, &pos);
    if (backfather == NULL)  //û���ҵ�
    {
        return ;
    }

    //ɾ��λ��
    switch (pos)
    {
        case -1:
        {
            //���ӽڵ�
            ptr = backfather->left;
            break;
        }
        case 1:
        {
            //���ӽڵ�
            ptr = backfather->right;
            break;
        }
        case 0:
        {
            //���ڵ�
            ptr = backfather;
            break;
        } 
    }

	if (ptr->left == NULL || ptr->right == NULL)
	{
		if (pos == 0)
		{
		    if (root->right != NULL)
            {
			    root = root->right;
            }else
            {
                root = root->left;
            }
		}else if (pos < 0)
		{
			if (ptr->left == NULL)
			{
				backfather->left = ptr->right;
			}else
			{
				backfather->left = ptr->left;
			}
		}else
		{
			if (ptr->left == NULL)
			{
				backfather->right = ptr->right;
			}else
			{
				backfather->right = ptr->left;
			}
		}

		free_node(ptr);

		return;
	}

    /*��������Ҳ������������� */
    backfather = ptr;  //���ڵ�ָ��ǰ�ڵ�
    next = ptr->left;   //�����ӽڵ�
    while (next->right != NULL)
    {
        backfather = next;
        next = next->right;
    }
    ptr->item = next->item;  //�滻����

	//��������Ľ��ɾ��
    if (backfather->left == next) 
    {
        backfather->left = next->left;
    }
    else
    {
        backfather->right = next->left;
    }

    free_node(next);

    return;
}

//������������
void destroy_btree(node *p)
{
    if (p == NULL)
    {
        return ;
    }

    destroy_btree(p->left);
    destroy_btree(p->right);

    printf("node %2d is destroyed\n", p->item);
	free_node(p);
}

int main()
{
    int item;
#if 1
    insert_node(20);
    insert_node(10);
    insert_node(26);
    insert_node(6);
    insert_node(16);
    insert_node(24);
    insert_node(30);
    insert_node(3);
    insert_node(5);
    insert_node(8);
    insert_node(7);
    insert_node(12);
    insert_node(18);
    insert_node(22);
    insert_node(25);
    insert_node(28);
    insert_node(32);
#endif

#if 0
    insert_node(8);
    insert_node(4);
    insert_node(9);
    insert_node(13);
    insert_node(11);
#endif
    
    printf("�������\n");
    traverse_a(root);
    printf("\n");
    post_order_traverse();
    printf("\n");

    printf("ǰ�����\n");
    traverse_b(root);
    printf("\n");

    pre_order_traverse();
    printf("\n");
    
    printf("�������\n");
    traverse_m(root);
    printf("\n");

    in_order_traverse();
    printf("\n");

    level_order_traverse();
    printf("\n");

    printf("leaves have %d\n", search_leaves());
    printf("levels have %d\n", search_depth());

    printf("please input you item:\n");
    scanf("%d", &item);

    node *p = search_node(root, item);
    if (p != NULL)
    {
        printf("node:%p: item %d\n", p, p->item);
        delete_node(item);
        traverse_m(root);
        printf("\n");

    }else
    {
        printf("can't find %d in this tree\n",item);
    }

	destroy_btree(root);

	return 0;
}
