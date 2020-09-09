/*************************************************************************
  > File Name: node_约瑟.c
  > Author: IvanLxy
  > Mail: yoyiyyo@163.com 
  > Created Time: Thu 27 Aug 2020 08:41:50 PM CST
  > 已知n个人（以编号1，2，3…n分别表示）围坐在一张圆桌周围。从编号为k的人开始报数，
  > 数到m的那个人出列；他的下一个人又从1开始报数，数到m的那个人又出列；
  > 依此规律重复下去，直到圆桌周围的人全部出列
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

node *init_josph(int n)	//init约瑟
{
	int i = 0;
	node *tail;	//tail node
	node *p = mk_node(1);

	head = p; 
	head->next = head; //init loop
	tail = head;	//init tail ,first tail is head
	/*Creat other node*/
	for(i = 1; i < n; i++)
	{
		node *p = mk_node(i+1);
		p->next = tail->next;	//loop:new node->next inherit old tail->next
		tail->next = p;			//link old tail with p  -|old_tail| --> |p| 
		tail = p;				//new node become new tail 
	}

	return head;
}

int josph(int n)
{
	int total = 1;
	int survial;
	node *p = init_josph(n);
	node *node_next;	//tmp

	while(p->next != p)//不是只有一个节点
	{
		total++;
		if(total == 3)
		{
			node_next = p->next;
			p->next = node_next->next;
			printf("%d ", node_next->item);

			free_node(node_next);
			p = p->next;

			total = 1;	//repeat
			continue;
		}

		p = p->next;
	}

	survial = p->item;
	free_node(p);

	return survial;
}

int main()
{
	printf("\nsurvial is %d \n", josph(12));

	return 0;
}

