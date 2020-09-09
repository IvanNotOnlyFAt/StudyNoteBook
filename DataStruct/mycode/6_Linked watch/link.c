/*************************************************************************
  > File Name: CompleteLink.c
  > Author: IvanLxy
  > Mail: yoyiyyo@163.com 
  > Created Time: Thu 27 Aug 2020 08:41:50 PM CST
  > 
************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int item;
	struct node *next;
}node;

node *head = NULL;

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
	//touchafa
	p->next = head;
	head = p;
}

void traverse()
{
	node *p = head;
	if(head == NULL)
	{
		return;
	}
	while(p->next != NULL)
	{
		printf("%d ", p->item);
		p = p->next;
	}
	printf("%d \n", p->item);
}

node *search(int target)
{
	node *p = head;

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

	if(p == head)
	{
		head = head->next;
		p->next = NULL;
		return ;
	}

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


void reverse_link()	//nizhuan
{
	node *nhead = NULL;	//new head
	node *p;

	while(head != NULL)
	{
		p = head;
		head = head->next;

		p->next = nhead;	//头插法
		nhead = p;		//nhead 前移
	}
	head = nhead;
}

void destroy()
{
	node *p;

	while(head != NULL)
	{
		p = head;
		head = head->next;
		free_node(p);
	}
}


int main()
{
	node *p;
	int target;

	p = mk_node(1);
	insert_node(p);
	p = mk_node(2);
	insert_node(p); 
	p = mk_node(3);
	insert_node(p); 
	p = mk_node(4);
	insert_node(p); 
	p = mk_node(5);
	insert_node(p); 
	p = mk_node(6);
	insert_node(p); 
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

