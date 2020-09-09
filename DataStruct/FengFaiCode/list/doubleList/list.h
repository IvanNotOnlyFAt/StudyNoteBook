#ifndef LIST_H
#define LIST_H

typedef struct node
{
    unsigned char item;
    struct node *prev;	//直接前驱
    struct node *next;	//直接后继
}node;

typedef struct list
{
    int len;
    struct node *hearder;
    struct node *tailer;
}LinkList;

LinkList *create_list();
node *make_node(unsigned char item);
void free_node(node *p);
node *search(LinkList *list, unsigned char key);
void insert(LinkList *list, node *p);
void delete_node(LinkList *list, node *p);
void traverse(LinkList *list, void (*visit)(node *));
void destroy(LinkList *list);
void enqueue(LinkList *list, node *p);
node *dequeue(LinkList *list);
int list_len(LinkList *list);

#endif // LIST_H
