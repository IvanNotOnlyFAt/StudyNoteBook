/*************************************************************************
	> File Name: struct_register.c
	> Author:Sjs
	> Mail:303547334@qq.com 
	> Created Time: 2020年07月06日 星期一 15时41分04秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>

typedef struct 
{
    unsigned char data:1;
    unsigned char :1;
    unsigned char addr:2;
    unsigned char :1;
    unsigned char opt:2;
    
}CONTROL;
int main(int argc,char *argv[])
{
    CONTROL data;
    data.data = 1;
    data.addr = 3;3;3;        //0x11 = 3        01 = 1   10 = 2     00 = 0
    return 0;
}
