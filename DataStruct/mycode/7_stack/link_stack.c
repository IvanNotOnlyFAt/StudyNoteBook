/*************************************************************************
  > File Name: link_stack.c
  > Author: IvanLxy
  > Mail: yoyiyyo@163.com 
  > Created Time: Mon 31 Aug 2020 08:09:59 PM CST
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
	node *p = (node *)malloc(sizeof(node));
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
	p->next = head;
	head = p;
}

void traverse()
{
	node *p = head;
	while(p != NULL)
	{
		printf("%d ",p->item);
		p = p->next;
	}
	printf("\n");
}

node *search(int target)
{
	node *p = head;
	while(p != NULL)
	{
		if(p->item == target)
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
		return;
	}
	
	while(pre->next != NULL)
	{
		if(pre->next == p)
		{
			pre->next = p->next;
			p->next = NULL;
			return;
		}
		pre = pre->next;
	}
}

void reverse_link()
{
	node *nhead = NULL;
	node *p;

	while(head != NULL)
	{
		p = head;
		head = head->next;

		p ->next = nhead;
		nhead = p;
	}
	head = nhead;
}

void destory()
{
	node *p;

	while(head != NULL)
	{
		p = head;
		head = head->next;
		free_node(p);
	}
}


int  is_empty()
{
	return head == NULL;
}

void push(int item)
{
	node *p = mk_node(item);
	insert_node(p);
}

int pop()
{
	node *p;
	int item;

	p = head;
	item = p->item;

	head = head->next;
	free_node(p);

	return item;
}

int main()
{
	push(1);
	push(2);
	push(3);
	push(4);
	push(5);
	push(6);
	push(7);

	while(!is_empty())
	{
		printf("%d  ", pop());
	}
	printf("\n");

	push(7);
	push(6);
	push(5);
	push(4);
	push(3);
	push(2);
	push(1);

	while (!is_empty())
	{
		printf("%d  ",  pop());
	}
	printf("\n");
	return 0;
	
/***********结果***********
* 	7  6  5  4  3  2  1  
* 	1  2  3  4  5  6  7   
************************/
}