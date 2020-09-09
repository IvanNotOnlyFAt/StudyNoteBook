/*************************************************************************
  > File Name: loopLink.c
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
node *tail = NULL;

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
	//头插法，所以tail一直是一开始head的位置，反而head一直向左移，
	//tail只要一直同步好tail->next是最新的head
	/*tail keep the link's end*/
	if(head == NULL)
	{
		head = p;
		head->next = head;
		tail = head;
	}else
	{
		p->next = head;
		head = p;	
		tail->next = head;
	}
}

void traverse_o()
{
	/*loop printf*/
	node *p = head;
	int i = 0;
	while((p != NULL )&&(i <= 20))
	{
		printf("%d ",p->item);
		p = p->next;
		i++;
	}
	printf("\n");
}

void traverse()
{
	node *p = head;
	if(head == NULL)
	{
		return;
	}
	while(p->next != head)	//loop limit
	{
		printf("%d ", p->item);
		p = p->next;
	}
	printf("%d \n", p->item);
}

node *search(int target)
{
	node *p = head;

	while(p->next != head)
	{
		if(target == p->item)
		{
			return p;
		}
		p = p->next;
	}
	/*if just have one node or search last node*/
	if(p->item == target)
	{
		return p;
	}else
	{
		return NULL;
	}
}

void rm_node(node *p)
{
	node *pre = head;

	if(p == head)
	{
		head = head->next;
		tail->next = head;
		p->next = NULL;
		return ;
	}

	while(pre->next != head)
	{
		if(pre->next == p)
		{
			pre->next = p->next;
			p->next = NULL;
			/*if p is tail node,remove tail need set pre for new tail  */
			if(p == tail)
			{
				tail = pre;
			}
			return ;
		}

		pre = pre->next;
	}
}



void reverse_link()	//nizhuan
{
	node *nhead = NULL;	//new head
	node *ntail = NULL;
	node *p;

	if(tail == NULL)
	{
		return ;
	}
	tail->next = NULL;

	while(head != NULL)
	{
		p = head;
		head = head->next;

		if(nhead == NULL)
		{
			p->next = nhead;	//头插法	
			nhead = p;		//nhead 前移
			
			ntail = nhead;
			ntail->next = nhead;
		}else
		{
			p->next = nhead;	//头插法	
			nhead = p;		//nhead 前移

			ntail->next = nhead;
		}	
	}
	head = nhead;
	tail = ntail;
}

void destroy()
{
	node *p;
	/*change looplink to sample link*/
	if(tail == NULL)
	{
		return;
	}
	tail->next = NULL;
	/*-------------------------------------------*/

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
	printf("------------loop print------------\n");
	traverse_o();
	printf("---------------------------------------\n");
	reverse_link();
	traverse();
	destroy();
	traverse();
	return 0;
}

