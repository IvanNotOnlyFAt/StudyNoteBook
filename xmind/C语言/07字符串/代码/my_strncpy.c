/*************************************************************************
	> File Name: my_strncpy.c
	> Author:Sjs
	> Mail:303547334@qq.com 
	> Created Time: 2020年07月03日 星期五 19时19分11秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
char *my_strcpy(char *dest,const char *src)
{
    //缺陷 : 地址重叠 或者内存重叠
    if(dest == NULL && *src ==NULL)
    {
        return;
    }
    char *tmp = dest;
#if  1
    do
    {
        *dest = *src;
        dest++;
        src++;
    }while(*src != '\0');
    *dest = '\0'; 
#else

    while(*dest++ = *src++);
#endif

    return tmp;
}


int main(int argc,char *argv[])
{
    char str1[] = "hello world";
    printf("str1 = %d\n",sizeof(str1));
    printf("str1 = %s\n",str1);
    char str2[30] = "";
    
    char *dest = my_strcpy(str2,str1);
    printf("sizeof(dest) : %d\n",sizeof(dest));
    printf("strlen = %d\n",strlen(dest));
    printf("str2 = %s\n",dest);
    return 0;
}
