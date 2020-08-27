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

Node *m_head;

void create_link(int len)
{
    int i = 0;

    m_head = NULL;
    for(i = 0; i < len; i++)
    {
        Node *node = create_node(i);
        insert_node(node);
    }

    printf("Create Link\n");
}

void destroy_link(void)
{
    Node *p = m_head;
    while (p != NULL)
    {
        destroy_node(p);
        p = getNext(p);
    }

    printf("Destroy Link\n");
}

void insert_node(Node *p)
{
    if(m_head == NULL)
    {
        m_head = p;
    }else
    {
        setNext(p,getNext(m_head));
        setNext(m_head, p);
    }
}

Node *find_node(int item)
{
	Node *p = getNext(m_head);
	while(p != NULL)
	{
		if ( getItem(p) == item)
		{
			return p;
		}
		p = getNext(p);
	}

	return NULL;
}

Node *remove_node(Node *p)
{
    Node *pre = m_head;
    while (getNext(pre) != NULL)
    {
        if (getNext(pre) == p)
        {
            setNext(pre, getNext(p));
            return p;
        }
        pre = getNext(pre);
    }

    return NULL;
}

void traverse(void)
{
	Node *p = m_head;
	while(p != NULL)
	{
		display(p);
		p = getNext(p);
	}

	printf("\n");
}

void setHead(Node *head)
{
    m_head = head;
}
Node *getHead(void)
{
    return m_head;
}
