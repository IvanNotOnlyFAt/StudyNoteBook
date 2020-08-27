 /**
  ******************************************************************************
  * @file    link.cpp
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

