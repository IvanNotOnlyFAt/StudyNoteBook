/*************************************************************************
	> File Name: reversed.c
	> Author: 
	> Mail: 
	> Created Time: 2020年06月28日 星期日 10时01分44秒
 ************************************************************************/

#include<stdio.h>
int main(int argc, char *argv[])
{
    char buf[10] = {""};
    int i = 0;
    char temp = '\0';
    //键盘输入字符串

    fgets(buf,sizeof(buf),stdin);

    //逆序
    for(; i < sizeof(buf)/2; i++)
    {
        char temp = buf[i];
    //注意  只能存储9个值, 0-8  buf[9]为\0  printf遇到\0就终止
        buf[i] = buf[9 - i -1];
        buf[9 - i - 1] = temp;
    }

    printf("%s\n",buf);
    return 0;
}
