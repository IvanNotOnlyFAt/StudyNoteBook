 /**
  ******************************************************************************
  * @file    node.h
  * @author  ������Ӣѵ��Ӫ   mind@unigress.com
  * @version V1.0
  * @date    2015-09-17
  * @brief   ��������������ϰ�нڵ�ģ���ͷ�ļ�
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

#ifndef __NODE_H
#define __NODE_H

#include <stdio.h>

typedef struct node
{
    int m_item;
    struct node *m_next;
}Node;

Node *create_node(int item);
void destroy_node(Node *p);

void display(Node *p);

void setItem(Node *p, int item);
int getItem(Node *p);
void setNext(Node *p, Node *next);
Node *getNext(Node *p);

#endif // __NODE_H
