 /**
  ******************************************************************************
  * @file    main.cpp
  * @author  联航精英训练营   mind@unigress.com
  * @version V1.0
  * @date    2015-09-17
  * @brief   项目主逻辑体。
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


#include <iostream>

#include "node.h"
#include "link.h"

using namespace std;

int main()
{
//    Link link(10);
//    link.traverse();
//
//    Node *p = new Node(110);
//    link.insert_node(p);
//    link.traverse();
//
//    p = link.find_node(5);
//    if (p == NULL)
//    {
//        cout << "Can't find node: " << 5 << endl;
//    }else
//    {
//        cout << "Finded node: " << 5 << endl;
//        if (link.remove_node(p))
//        {
//            delete p;
//        }
//    }
//
//    link.traverse();

    Link l(5);
    l.traverse();

    Link ll(10);
    ll.traverse();
}



