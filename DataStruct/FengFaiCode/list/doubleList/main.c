#include "list.h"

void print(node *p)
{
    printf("p->item: %c\n", p->item);
}

int main()
{
    LinkList *list = create_list();
    int i = 0;
    for(i = 0; i < 10; i++)
    {
        node *p = make_node('a' + i);
        enqueue(list, p);
    }

    traverse(list, print);
    destroy(list);


    return 0;
}
