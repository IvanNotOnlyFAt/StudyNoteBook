/*************************************************************************
	> File Name: ssprintf.c
	> Author:Sjs
	> Mail:303547334@qq.com 
	> Created Time: 2020年07月04日 星期六 10时16分02秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
void test01(void)
{
    int year = 2020;
    int month = 07;
    int date = 04;
    char buf[128] = "";
    sprintf(buf,"%d年%d月%d日",year,month,date);
    printf("%s",buf);
}
int main(int argc,char *argv[])
{
    test01();
    return 0;
}
