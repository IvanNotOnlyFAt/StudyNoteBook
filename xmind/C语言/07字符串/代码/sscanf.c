/*************************************************************************
	> File Name: sscanf.c
	> Author:Sjs
	> Mail:303547334@qq.com 
	> Created Time: 2020年07月04日 星期六 13时15分41秒
 ************************************************************************/

#include<stdio.h>

int main(int argc,char *argv[])
{
    char buf[128] = "";
    int num = 0;
    sscanf("1234 5678","%*s %d",&num);
    printf("%d\n",num);
    sscanf("aaBBcDEFabc","%[aBc]",buf);

    printf("%s\n",buf);
    return 0;
}
