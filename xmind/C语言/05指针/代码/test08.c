/*************************************************************************
	> File Name: test08.c
	> Author:Sjs
	> Mail:303547334@qq.com 
	> Created Time: 2020年07月03日 星期五 00时01分45秒
 ************************************************************************/

#include<stdio.h>
int sum(int a, int b)
{
    return a+b;
}
int main(int argc , char *argv[])
{
    //输出函数名地址
    printf("函数名 : %p\n", sum);
    
    //定义函数指针
    //函数返回值类型 (* 指针变量名) (函数参数列表);
    int (*p)(int,int)  = NULL;
    //赋值
    p = sum;
    //输出指针地址
    printf("指针地址: %p\n",p);

    //使用
    printf("函数调用: %d\n",sum(10,20));
    printf("指针调用: %d\n",p(100,200));

    //所以有什么用呢?
    //就是C++多态的实现方式之一

    return 0;
}
