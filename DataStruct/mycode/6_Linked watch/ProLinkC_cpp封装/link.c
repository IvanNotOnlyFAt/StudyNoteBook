 /**
  ******************************************************************************
  * @file    link.c
  * @author  联航精英训练营   mind@unigress.com
  * @version V1.0
  * @date    2015-09-17
  * @brief   本程序是链表练习中链表模块的源文件
  ******************************************************************************
  * @attention
  *
  * 本程序所提供的源代码均为本程序作者或由网络收集整理而来，仅供学习和研究使用。
  * 如有侵犯的地方，请及时联系，我们会立即修改。使用本程序源码的用户必须明白，
  * 我们不能保证所提供的源码及其它资源的准确性、安全性和完整性，因此我们将不负责
  * 承担任何直接，间接因使用这些源码对自己和他人造成任何形式的损失或伤害。任何人
  * 在使用本代码时，应注明作者和出处。
  *
  * <h2><center>版权所有(C) 2013 太原联航科技有限公司</center></h2>
  ******************************************************************************
*/

#include "node.h"
#include "link.h"

void create_link(Link *l, int len)
{
    int i = 0;

    l->head = NULL;
    for(i = 0; i < len; i++)
    {
        Node *node = create_node(i);
        insert_node(l, node);
    }

    printf("Create Link\n");
}

void destroy_link(Link *l)
{
    Node *p = l->head;
    Node *pre = NULL;
    while (p != NULL)
    {
        pre = p;
        p = p->next;
        destroy_node(pre);
    }

    printf("Destroy Link\n");
}

void insert_node(Link *l, Node *p)
{
    //将第一个插入的作为头结点的头插法
    //插入1~9，最后顺序是0 9 8 7 6 5 4 3 2 1
    if(l->head == NULL)
    {
        l->head = p;
    }else
    {
        p->next = l->head->next;
        l->head->next = p;
    }
}

Node *find_node(Link *l, int item)
{
	Node *p = l->head;
	while(p != NULL)
	{
		if (p->item == item)
		{
			return p;
		}
		p = p->next;
	}

	return NULL;
}

Node *remove_node(Link *l, Node *p)
{


    Node *pre = l->head;
    while (pre->next != NULL)
    {
        if (pre->next == p)
        {
            pre->next = p->next;
            p->next = NULL;
            return p;
        }
        pre = pre->next;
    }

    return NULL;
}

void traverse(Link *l)
{
	Node *p = l->head;
	while(p != NULL)
	{
		display(p);
		p = p->next;
	}

	printf("\n");
}

