 /**
  ******************************************************************************
  * @file    link.c
  * @author  ������Ӣѵ��Ӫ   mind@unigress.com
  * @version V1.0
  * @date    2015-09-17
  * @brief   ��������������ϰ������ģ���Դ�ļ�
  ******************************************************************************
  * @attention
  *
  * ���������ṩ��Դ�����Ϊ���������߻��������ռ��������������ѧϰ���о�ʹ�á�
  * �����ַ��ĵط����뼰ʱ��ϵ�����ǻ������޸ġ�ʹ�ñ�����Դ����û��������ף�
  * ���ǲ��ܱ�֤���ṩ��Դ�뼰������Դ��׼ȷ�ԡ���ȫ�Ժ������ԣ�������ǽ�������
  * �е��κ�ֱ�ӣ������ʹ����ЩԴ����Լ�����������κ���ʽ����ʧ���˺����κ���
  * ��ʹ�ñ�����ʱ��Ӧע�����ߺͳ�����
  *
  * <h2><center>��Ȩ����(C) 2013 ̫ԭ�����Ƽ����޹�˾</center></h2>
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
    //����һ���������Ϊͷ����ͷ�巨
    //����1~9�����˳����0 9 8 7 6 5 4 3 2 1
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

