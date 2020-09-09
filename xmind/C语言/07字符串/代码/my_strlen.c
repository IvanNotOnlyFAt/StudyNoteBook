/*************************************************************************
	> File Name: my_strlen.c
	> Author:Sjs
	> Mail:303547334@qq.com 
	> Created Time: 2020年07月04日 星期六 09时16分56秒
 ************************************************************************/

#include<stdio.h>
int my_strlen(char *str)
{
    if(str == NULL)
    {
        return 0;
    }
    int num = 0;
    char *tmp = str;
    while(*tmp != '\0')
    {
        tmp++;
        num++;
    }

    return num;
}

int main(int argc,char *argv[])
{
    char arr[] = "hello";
    printf("%d",my_strlen(arr));
    return 0;
}
