/*************************************************************************
	> File Name: tdStr.c
	> Author: 
	> Mail: 
	> Created Time: 2020年06月27日 星期六 22时40分07秒
 ************************************************************************/

#include<stdio.h>
int main(int argc, char *argv[])
{
    char str[4][6] ={""};
    int i = 0;
    //获取键盘输入
    for(;i < 4; i++)
    {
        scanf("%s",str[i]);
        //C语言真正的魅力
        //&str[i][0] == & *(str[i] + 0) == str[i] + 0  == str[i]
    }
    
    //输出
    for(i = 0; i < 4; i++)
    {
        printf("buf[%d] = %s\n",i,str[i]);
        printf("sizeof(buf[%d]) = %d\n ",i,sizeof(str[i]));
    }
    return 0;
}
