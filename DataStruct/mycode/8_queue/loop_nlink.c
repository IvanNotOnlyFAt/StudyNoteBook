#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int item;
	struct node *next;
}node;

node sentinel = {0,NULL};
node *head = &sentinel;
node * tail;

node *mk_node(int item)
{
	node *p = (node *)malloc(sizeof(node));
    if(p == NULL)
    {
    	printf("malloc filed");
    	exit(1);
    }
    p->item = item;
    p->next = NULL;
    return p;
}

void insert_node(node *p)
{
	node *pre = head->next;

	 if(pre == NULL)
    {
    	head ->next = p;
    	tail = p;
    	tail->next = head->next;
        return ;
    }

    if(p->item < pre->item)
    {
        p->next = pre;
        head ->next = p;
        tail->next = head->next;
        return ;
    }

    while(pre->next != head->next)
    {
        if((p->item) < (pre->next->item))
        {
            p->next = pre->next;
            pre->next = p;
            return ;
        }
        pre = pre->next;
    }
    pre->next = p;
    p->next = head->next;
    tail = p;
	
}

void traverse()
{
    node *p = head->next;

    while(p != tail)
    {
    	printf("%d ",p->item);
        p = p->next;
    }
    printf("%d\n",p->item);
}

void reverse()
{
	node *nhead = NULL;
	node * p;
	node *pp;

	while(head->next  != tail)
	{
        p = head ->next;
        head->next = p->next;
       p->next = nhead;
        nhead = p;
	}
	tail ->next = nhead;

	pp = nhead;
	while(pp->next !=NULL)
	{
		pp = pp->next;
	}

	tail = pp;
	tail ->next = head ->next; 
}

node * search_node(int target)
{
	node *p = head->next;

	while(p != tail)
	{
		if(p->item == target)
        {
        	return p;
        }	
        p = p->next;
	}

	if( target == tail->item)
	{
		return tail;
	}
return NULL;

}

void remove_node(node *p)
{
	node *pre = head->next;

if(p == head->next)
{
	head->next = p->next;
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
		pre = pre->next;

	}
	if(tail == p)
	{
		p->next = NULL;
		tail  = pre;
		tail ->next = head->next;
       return ;
	}
}

void free_node(node *p)
{
	free(p);
	p = NULL;
}

void destory()
{
	node *p;
    
    tail ->next = NULL;

	while(head->next != NULL)
		{
            p = head ->next;
            head ->next = p -> next;
            free_node(p);
		}
}

int main()
{
	node *p;
	int target;

	p = mk_node(1);
	insert_node(p);
	traverse();

	p = mk_node(2);
	insert_node(p);
	traverse();

	p = mk_node(3);
	insert_node(p);
	traverse();

	p = mk_node(4);
	insert_node(p);
	traverse();

	p = mk_node(5);
	insert_node(p);


	traverse();

	reverse();
	traverse();

  scanf("%d",&target);
	p = search_node(target);
    if(p == NULL)
    {
    	printf("can't find%d\n",target);
    }
    else
    {
    	printf("%p %d %d\n",p,target,p->item);
    	remove_node(p);
    	free_node(p);
    }
    traverse();

    destory();
    traverse();

	return 0;
}
