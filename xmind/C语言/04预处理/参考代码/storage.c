/*************************************************************************
	> File Name: storage.c
	> Author: 
	> Mail: 
	> Created Time: 2020年06月30日 星期二 10时30分34秒
 ************************************************************************/

#include<stdio.h>


void test01(void)
{
    char data = -10;
    //%x十六进制
    printf("%x\n",data);
    //正数
    char data2 = 10;
    printf("%x\n",data2);
    //十六进制
    char data3 = 0xae;
    printf("%x\n",data3);
    //8进制   3位二进制
    char data4 = 0256;
    printf("%x\n",data4);
    char data5 = -10;
    printf("%x\n",data5);
    printf("data5 = %d\n",data5);
    printf("data5 u= %u\n",data5&0x000000ff);
    return;
}

int main(int argc , char *argv[])
{
    test01();
    return 0;
}
