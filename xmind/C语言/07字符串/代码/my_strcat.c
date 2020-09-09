/*************************************************************************
	> File Name: my_strcat.c
	> Author:Sjs
	> Mail:303547334@qq.com 
	> Created Time: 2020年07月03日 星期五 19时40分09秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
char *my_strcat(char *str1, char *str2)
{
    if(str1 == NULL && str2 == NULL)
    {
        return;
    }
    char *tmp1 = str1;
    char *tmp2 = str2;
    while(*tmp1 != '\0')
    {
        tmp1++;
    }
    while(*tmp2 != '\0')
    {
        *tmp1 = *tmp2;
        tmp1++;
        tmp2++;
    }
    *tmp1 = '\0';
    return str1;
}

int main(int argc,char *argv[])
{
    char arr0[30] = "hello";
    char arr1[] = "world";
    char *buff = "hello world";
    char *dest = my_strcat(arr0,arr1);
    char *addr = strcat(arr0,arr1); 
    printf("%s\n",dest);
    printf("%s\n",addr);
    printf("%s\n",buff);
    return 0;
}

