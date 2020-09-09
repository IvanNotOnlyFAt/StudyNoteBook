/*************************************************************************
	> File Name: test01.c
	> Author: 
	> Mail: 
	> Created Time: 2020年06月29日 星期一 21时33分41秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
int main()
{
    char buf[128] = "";

    char buf2[128] = {'\0'};

    printf("%d\n",strlen(buf));
    printf("buf2: %d\n",strlen(buf2));
    return 0;

}
