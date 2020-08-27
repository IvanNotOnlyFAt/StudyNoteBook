 /**
  ******************************************************************************
  * @file    node.cpp
  * @author  ������Ӣѵ��Ӫ   mind@unigress.com
  * @version V1.0
  * @date    2015-09-17
  * @brief   ��������������ϰ�нڵ�ģ���Դ�ļ�
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

Node::Node(int item)
{
    m_item = item;
    m_next = NULL;

    cout << "Create Node: " << m_item << endl;
}

Node::~Node()
{
    cout << "Destroy Node: " << m_item << endl;
}

void Node::display() const
{
    cout << m_item << " ";
}

void Node::setItem(int item)
{
    m_item = item;
}
int Node::getItem(void) const
{
    return m_item;
}
void Node::setNext(Node *next)
{
    m_next = next;
}
Node *Node::getNext(void) const
{
    return m_next;
}

