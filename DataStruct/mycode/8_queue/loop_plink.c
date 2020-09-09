#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int item;
	struct node *next;
}node;

node *head;
node *nhead;
node *tail;

node *mk_node(int item)
{
	node *p = (node *)malloc(sizeof(node));

	if(p == NULL)
	{
		printf("molloc filed\n");
		exit(1);
	}

	p->item = item;
	p->next = NULL;

	return p;
}

void insert_node(node *p)
{
    if(head == NULL)
    {
    	p->next = head;
    	head = p;
    	tail = p;
    	tail->next = head;
        return ;
    }

    p->next = head;
    head = p;
    tail->next =head;

}

void sort_insert(node *p)
{
	node *pp = head;

    if(head == NULL)
    {
    	p->next = head;
    	head = p;
    	tail = p;
    	tail->next = head;
        return ;
    }

    if(p->item < head->item)
    {
        p->next = head;
        head = p;
        tail->next = head;
        return ;
    }

    while(pp->next != head)
    {
        if((p->item) < (pp->next->item))
        {
            p->next = pp->next;
            pp->next = p;
            return ;
        }
        pp = pp->next;
    }
    pp->next = p;
    p->next = head;
    tail = p;
}

void traverse()
{
	node *p = head;

	if( head == NULL)
	{
		return ;
	}

	while(p->next != head)
	{
		printf("%d ",p->item);
		p = p->next;
	}
	printf("%d ",p->item);
	printf("\n");
}

void free_node(node *p)
{
	free(p);
	p = NULL;
}

node *search_node(int item)
{
	node *p = head;

	while(p->next != head)
	{
		if(p->item == item)
        {
        	return p;
        }
        p = p->next;
	}

	if(p->item == item)
	{
		return p;
	}
	return NULL;
}

void remove_node(node *p)
{
   node *pre = head;

   if(p == head)
   {
   	head  = head->next;
   	tail ->next = head;
   	return ;
   }

   while(pre->next != tail)
   {
   	 if(pre->next == p)
   	 {
   	 	pre->next = p->next;
   	 	p->next = NULL;
   	 	return ;
   	 }
   	 pre = pre ->next;
   }

   if(tail == p)
   {
      pre->next = head;
      tail = pre;
      return;
   }

}

void reverse()
{
	node *p;
	node *pp;

	while(head != tail)
	{
		p = head;
		remove_node(p);
		p->next = nhead;
		nhead = p;
	}

	head->next = nhead;
	nhead = head;
		
    pp = nhead;
	while(pp->next != NULL)
	{
		pp = pp->next;
	}

	tail = pp;
	tail ->next = head;
}

void destory()
{
   node *p;
   tail ->next =NULL;

   while(head != NULL)
   {
   	p = head;
   	head= head->next;
   	p->next = NULL;
   	free_node(p);
   }
   
}

int main()
{
	node *p;

	p = mk_node(1);
	//insert_node(p);
	sort_insert(p);
	p = mk_node(2);
	//insert_node(p);
	sort_insert(p);
	p = mk_node(3);
	//insert_node(p);
	sort_insert(p);

	traverse();

    p = search_node(1);
    if(p != NULL)
    {
    	printf("%p %d\n",p,p->item);
    	remove_node(p);
    	free(p);
    }
    else
    {
    	printf("not found\n");
    }
    
    traverse();

   reverse();
   traverse();

   destory();
   traverse();

	return 0;
}
