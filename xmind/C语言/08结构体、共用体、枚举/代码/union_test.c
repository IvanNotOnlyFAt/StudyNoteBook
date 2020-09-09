/*************************************************************************
	> File Name: union_test.c
	> Author:Sjs
	> Mail:303547334@qq.com 
	> Created Time: 2020年07月06日 星期一 16时28分16秒
 ************************************************************************/

#include<stdio.h>
union data
{
    char a;
    int  b;
    short c;
}

int main(int argc,char *argv[])
{
    printf("union sizeof %d\n",sizeof(data));
}
