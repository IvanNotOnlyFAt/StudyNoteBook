/*************************************************************************
	> File Name: test01.c
	> Author: 
	> Mail: 
	> Created Time: 2020年06月30日 星期二 22时40分42秒
 ************************************************************************/

#include<stdio.h>
int main(int argc, char *argv[])
{
    //两个数字 一个字节
    int num = 0x1234;
    printf("num :%x\n",num);
    //指针跨度和宽度不等
    char *p;
    p = &num;
    //强制转换
    printf("%#x\n",*p);
    printf("%#x\n",*(short *)p);
    return 0;
}
