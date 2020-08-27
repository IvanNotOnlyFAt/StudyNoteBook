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
    if (p == NULL)
    {
        printf("malloc failure\n");
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
	p->next = head->next;
	head->next = p;
}

void insert_node_l2b(node *p)
{
    if(head == NULL)
    {
        head = p;
    }else
    {
        node *pre = head;
        while (pre->next != NULL)
        {
            if (pre->next->item > p->item)
            {
                break;
            }
            pre = pre->next;
        }

        p->next = pre->next;
        pre->next = p;
    }
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

node *find(int item)
{
	node *p = head->next;
	while(p != NULL)
	{
		if ( p->item == item)
		{
			return p;
		}
		p = p->next;
	}

	return NULL;
}

node *remove_node(node *p)
{
    node *pre = head;
    while (pre->next != NULL)
    {
        if (pre->next == p)
        {
            pre->next = p->next;
            return p;
        }
        pre = pre->next;
    }

    return NULL;
}

void destroy()
{
    node *p;
    while (head->next != NULL)
    {
        p = head->next;
        head->next = head->next->next;
        free_node(p);
    }
}

int main()
{
	node *p = mk_node(11);
	insert_node_l2b(p);

	p = mk_node(2);
    insert_node_l2b(p);

    p = mk_node(31);
    insert_node_l2b(p);

    p = mk_node(14);
    insert_node_l2b(p);

    p = mk_node(-5);
    insert_node_l2b(p);

    traverse();

    p = find(14);
    if (p == NULL)
    {
        printf("can't find %d\n",14);
    }else
    {
        printf("%p item:%d target:%d\n",p,p->item,14);
       if (remove_node(p))
       {
            free_node(p);
       }
    }

    traverse();
    destroy();
    traverse();
}
