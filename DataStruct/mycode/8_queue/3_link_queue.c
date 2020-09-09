/*************************************************************************
  > File Name: link_queue.c
  > Author: IvanLxy
  > Mail: yoyiyyo@163.com 
  > Created Time: Mon 31 Aug 2020 11:21:19 PM CST
  > 链表队列，改自链表栈
************************************************************************/
#include <stdio.h>
#include <stdlib.h>
/**************nodelink***************/
typedef struct node 
{
	int item;
	struct node *next;
}node;

node *head = NULL;

node *mk_node(int item)
{
	node *p = (node *)malloc(sizeof(node));
	if (p == NULL)
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

	while (p != NULL)
	{
		printf("%d ", p->item);
		p = p->next;
	}
	printf("\n");
}

node *search(int target)
{
	node *p = head;

	while (p != NULL)
	{
		if (target == p->item)
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

	if (p == head)
	{
		head = head->next;
		p->next = NULL;
		return ;
	}

	while (pre->next != NULL)
	{
		if (pre->next == p)
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

	while (head != NULL)
	{
		p = head;
		head = head->next;
		p->next = nhead;
		nhead = p;
	}

	head = nhead;
}

void destroy()
{
	node *p;

	while (head != NULL)
	{
		p = head;
		head = head->next;
		free_node(p);
	}
}
/**************nodelink - end***************/

/*链表不需要判断满不满*/

int is_empty()
{
	return head == NULL;
}

void enqueue(int item)
{
	node *tail;
	node *p = mk_node(item);

	if(head == NULL)
	{
		head = p;
	}else
	{
		tail = head;
		while (tail->next != NULL)
		{
			//采用尾插法
			tail = tail->next;
		}
		tail->next = p;
	}
}

int dequeue()
{
	node *p;
	int item;

	p = head;
	head = head->next;

	item = p->item;
	free_node(p);
	return item;
}

int main()
{
	enqueue(1);
	enqueue(2);
	enqueue(3);
	enqueue(4);
	enqueue(1);
	enqueue(2);
	enqueue(3);
	enqueue(4);

	dequeue();
	enqueue(8);
	while(!is_empty())
    	{
    		printf("%d ",dequeue());
   	 }
   	 printf("\n");

    	return 0;
	/**********************
	>  2 3 4 1 2 3 4 8 
	> [Finished in 0.1s]
	**********************/
}