/**
  ******************************************************************************
  * @file    node.cpp
  * @author  联航精英训练营   mind@unigress.com
  * @version V1.0
  * @date    2015-09-17
  * @brief   本程序是链表练习中节点模块的源文件
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

#include <stdlib.h>
#include "node.h"

Node *create_node(int item)
{
    Node *p =(Node *)malloc(sizeof(Node));
    p->item = item;
    p->next = NULL;
    printf("Create Node: %d\n", p->item);
    return p;
}

void destroy_node(Node *p)
{
    printf("Destroy Node: %d\n", p->item);
    free(p);
}

void display(Node *p)
{
    printf("%d ", p->item);
}
