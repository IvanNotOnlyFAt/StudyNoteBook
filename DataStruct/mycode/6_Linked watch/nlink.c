/*************************************************************************
  > File Name: nLink.c
  > Author: IvanLxy
  > Mail: yoyiyyo@163.com 
  > Created Time: Thu 30 Aug 2020 08:41:50 PM CST
  > 带头结点的单链表：头指针head指向头结点。
  > 头指针head始终不等于NULL，head->next等于NULL的时候链表为空。
************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct node
{
	int item;
	struct node *next;
}node;
//哨兵sentinel
node sentinel = {0, NULL};
node *head = &sentinel;


node *mk_node(int item)
{
	node *p = (node*)malloc(sizeof(node));
	if(p == NULL)
	{
		printf("malloc failed\n");
		exit(1);
	}
	p->item = item;
	p->next = NULL;

	return p;
}

void free_node(node *p)
{
	free(p);
}

void insert_node(node *p)
{
	//头插法，插入到哨兵节点之后
	p->next = head->next;
	head->next = p;
}

void insert_node_l2b(node *p)
{
	//排序插入，从小到大
	node *pre = head;

	while(pre->next != NULL)
	{
		if(p->item <= pre->next->item)
		{
			break;
		}
		pre = pre->next;
	}

	p->next = pre->next;
	pre->next = p;
}

void traverse()
{
	node *p = head->next;

	while(p != NULL)
	{
		printf("%d ", p->item);
		p = p->next;
	}
	printf("\n");
}

node *search(int target)
{
	node *p = head->next;

	while(p != NULL)
	{
		if(target == p->item)
		{
			return p;
		}
		p = p->next;
	}
	return NULL;
}

void rm_node(node *p)
{
	node *pre = head;

	while(pre->next != NULL)
	{
		if(pre->next == p)
		{
			pre->next = p->next;
			p->next = NULL;
			return ;
		}
		pre = pre->next;
	}
}



void reverse_link()
{
	node *nhead = NULL;
	node *p;

	while(head->next != NULL)
	{
		p = head->next;
		head->next = p->next;

		p->next = nhead;
		nhead = p;
	}
	head->next = nhead;
}

void destroy()
{
	node *p;

	while(head->next != NULL)
	{
		/*销毁的时候，头节点不动，一直删除头结点的下一个*/
		p = head->next;
		head->next = p->next;
		free_node(p);
	}
}


int main()
{
	node *p;
	int target;
	p = mk_node(100);
	insert_node_l2b(p); 
	p = mk_node(-2);
	insert_node_l2b(p); 
	p = mk_node(30);
	insert_node_l2b(p); 
	p = mk_node(-4);
	insert_node_l2b(p); 
	p = mk_node(50);
	insert_node_l2b(p); 
	p = mk_node(6);
	insert_node_l2b(p); 

	traverse();

	scanf("%d", &target);
	p = search(target);
	if (p == NULL)
	{
		printf("can't find  %d\n",  target);
	}else
	{
		printf("%p %d %d\n",  p, target, p->item);
		rm_node(p);
		free_node(p);
	}
	traverse();
	reverse_link();
	traverse();
	destroy();
	traverse();
	return 0;
}

