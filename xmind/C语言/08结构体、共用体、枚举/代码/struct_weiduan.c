/*************************************************************************
	> File Name: struct_weiduan.c
	> Author:Sjs
	> Mail:303547334@qq.com 
	> Created Time: 2020年07月06日 星期一 15时32分18秒
 ************************************************************************/

#include<stdio.h>
typedef struct weiduan
{
    unsigned  char a:2;
    unsigned  char b:4;
    unsigned  char c:3;
}WD;
int main(int argc,char *argv[])
{
    printf("sizeof(wd) = %d  ",sizeof(WD));
    return 0;
}
