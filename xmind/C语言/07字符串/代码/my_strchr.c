/*************************************************************************
	> File Name: my_strchr.c
	> Author:Sjs
	> Mail:303547334@qq.com 
	> Created Time: 2020年07月04日 星期六 09时57分22秒
 ************************************************************************/

#include<stdio.h>
char *my_strchr(char *buf, char c)
{
    if(buf != NULL)
    {
        return NULL;
    }
    for(;*buf != c ; buf++){
        if(*buf == '\0')
        {
            return NULL;
        }
    }
    return *buf;
}

int main(int argc,char *argv[])
{
    return 0;
}
