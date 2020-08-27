 /**
  ******************************************************************************
  * @file    link.h
  * @author  联航精英训练营   mind@unigress.com
  * @version V1.0
  * @date    2015-09-17
  * @brief   本程序是链表练习中链表模块的头文件
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

#ifndef __LINK_H
#define __LINK_H

#include <stdio.h>
#include "node.h"

void create_link(int len);
void destroy_link(void);

void insert_node(Node *p);
Node *find_node(int item);
Node *remove_node(Node *p);

void traverse(void);

void setHead(Node *head);
Node *getHead(void);

#endif // __LINK_H
