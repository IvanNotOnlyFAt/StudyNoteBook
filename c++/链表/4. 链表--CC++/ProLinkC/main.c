 /**
  ******************************************************************************
  * @file    main.c
  * @author  ������Ӣѵ��Ӫ   mind@unigress.com
  * @version V1.0
  * @date    2015-09-17
  * @brief   ��Ŀ���߼��塣
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

#include <stdio.h>
#include "node.h"
#include "link.h"

int main()
{


    Link link;
    create_link(&link, 10);
    traverse(&link);

//    Node *p = create_node(110);
//    insert_node(&link, p);
//    traverse(&link);
//
//    p = find_node(&link, 110);
//    if (p == NULL)
//    {
//        printf("Can't find node: %d\n", 5);
//    }else
//    {
//        printf("Finded node: %d\n", 5);
//        if (remove_node(&link, p))
//        {
//            destroy_node(p);
//        }
//    }
//
//    traverse(&link);

    Link link1;
    create_link(&link1, 5);
    traverse(&link1);
}
