 /**
  ******************************************************************************
  * @file    link.cpp
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

#include "link.h"
#include "node.h"

Link::Link()
{
    m_head = NULL;
    cout << "Create Link" << endl;
}

Link::Link(int len)
{
    m_head = NULL;
    for(int i = 0; i < len; i++)
    {
        Node *node = new Node(i);
        insert_node(node);
    }
    cout << "Create Link" << endl;
}

Link::~Link()
{
    Node *p = NULL;
    Node *pre = m_head;
    while (pre->getNext() != NULL)
    {
        p = pre;
        pre = pre->getNext();
        delete p;
    }

    cout << "Destroy Link" << endl;
}

void Link::insert_node(Node *p)
{
    if(m_head == NULL)
    {
        m_head = p;
    }else
    {
        p->setNext(m_head->getNext());
        m_head->setNext(p);
    }
}

Node *Link::find_node(int item)
{
	Node *p = m_head->getNext();
	while(p != NULL)
	{
		if ( p->getItem() == item)
		{
			return p;
		}
		p = p->getNext();
	}

	return NULL;
}

Node *Link::remove_node(Node *p)
{
    Node *pre = m_head;
    while (pre->getNext() != NULL)
    {
        if (pre->getNext() == p)
        {
            pre->setNext(p->getNext());
            return p;
        }
        pre = pre->getNext();
    }

    return NULL;
}

void Link::traverse(void) const
{
	Node *p = m_head;
	while(p != NULL)
	{
		p->display();
		p = p->getNext();
	}

	cout << "\n" ;
}

void Link::setHead(Node *head)
{
    m_head = head;
}
Node *Link::getHead(void) const
{
    return m_head;
}

