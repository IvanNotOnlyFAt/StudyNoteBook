 /**
  ******************************************************************************
  * @file    link.h
  * @author  ������Ӣѵ��Ӫ   mind@unigress.com
  * @version V1.0
  * @date    2015-09-17
  * @brief   ��������������ϰ������ģ���ͷ�ļ�
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

#ifndef __LINK_H
#define __LINK_H

#ifdef __cplusplus
 extern "C" {
#endif

#include <stdio.h>
#include "node.h"
/**********************************/
typedef struct link
{
    Node *head;
    int len;
}Link;
/*********************************/
void create_link(Link *l, int len);
void destroy_link(Link *l);

void insert_node(Link *l, Node *p);
Node *find_node(Link *l, int item);
Node *remove_node(Link *l, Node *p);

void traverse(Link *l);

#ifdef __cplusplus
 }
#endif

#endif // __LINK_H
