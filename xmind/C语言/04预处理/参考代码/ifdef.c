/*************************************************************************
	> File Name: ifdef.c
	> Author: 
	> Mail: 
	> Created Time: 2020年06月29日 星期一 21时17分20秒
 ************************************************************************/

#include<stdio.h>
//#define HEHE 
int main(int argc, char *argv[])
{
#ifdef HEHE
    printf("001");
#else
    printf("002");
#endif
    return 0;
}
