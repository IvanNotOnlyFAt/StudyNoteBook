#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "list.h"

LinkList *create_list()
{
    static struct node l_head = {0, NULL, NULL};
    static struct node l_tail = {0, &l_head, NULL};
    l_head.next = &l_tail;

    LinkList *tmp = (LinkList *)malloc(sizeof(LinkList));
    assert(tmp != NULL);

    tmp->hearder = &l_head;
    tmp->tailer = &l_tail;
    tmp->len = 0;

    return tmp;
}

node *make_node(unsigned char item)
{
    node *p = (node *)malloc(sizeof(node));
    assert(p != NULL);

    p->item = item;
    p->next = NULL;
    p->prev = NULL;

    return p;
}

void free_node(node *p)
{
    free(p);
}

node *search(LinkList *list, unsigned char key)
{
    node *pr = NULL;
    for(pr = list->hearder->next; pr != list->tailer; pr = pr->next)
    {
        if(key == pr->item)
        {
            return pr;
        }
    }
    return NULL;
}

void insert(LinkList *list, node *p)
{
    node *pr = list->hearder;

    p->next = pr->next;
    p->prev = pr;
    pr->next->prev = p;
    pr->next = p;
    list->len++;
}

void delete_node(LinkList *list, node *p)
{
    p->next->prev = p->prev;
    p->prev->next = p->next;
    list->len--;
}

void traverse(LinkList *list, void (*visit)(node *))
{
    node *p = NULL;
    for(p = list->hearder->next; p != list->tailer; p = p->next)
    {
        visit(p);
    }
}

void destroy(LinkList *list)
{
    node *p = NULL;
    for(p = list->hearder->next; p != list->tailer; p = p->next)
    {
        if(p != NULL)
        {
            delete_node(list, p);
            free_node(p);
        }
    }
    list->hearder = NULL;
    list->tailer = NULL;
    free(list);
}

void enqueue(LinkList *list, node *p)
{
    insert(list, p);
}

node *dequeue(LinkList *list)
{
    node *ne = list->tailer;
    node *p = ne->prev;
    delete_node(list, p);
    return p;
}


int list_len(LinkList *list)
{
    return list->len;
}
