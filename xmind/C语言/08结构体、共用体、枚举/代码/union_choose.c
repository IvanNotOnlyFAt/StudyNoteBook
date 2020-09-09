/*************************************************************************
	> File Name: union_choose.c
	> Author:Sjs
	> Mail:303547334@qq.com 
	> Created Time: 2020年07月06日 星期一 23时56分58秒
 ************************************************************************/

#include<stdio.h>
union TestCPU
{
    int i;
    char ch;
};
void TestCPUMode(void)
{
    union TestCPU test;
    test.i  = 1;
    if(test.ch == 1)
    {
        printf("小段模式");
    }else
    {
        printf("大段模式");
    }
}
int main(int argc,char *argv[])
{
    TestCPUMode();
    return 0;
}
