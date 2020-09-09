/*************************************************************************
	> File Name: define.c
	> Author: 
	> Mail: 
	> Created Time: 2020年06月29日 星期一 15时18分23秒
 ************************************************************************/

#include<stdio.h>
#define MY_ADD(a,b)  a+b
int main(int argc , char *argv[])
{
    int num = MY_ADD(55,45);
    printf("%d\n",num);

    return 0;
}
