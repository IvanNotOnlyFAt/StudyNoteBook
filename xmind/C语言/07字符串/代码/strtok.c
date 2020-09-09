/*************************************************************************
	> File Name: ssprintf.c
	> Author:Sjs
	> Mail:303547334@qq.com 
	> Created Time: 2020年07月04日 星期六 10时16分02秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
void test01(void)
{
    char buf[] = "hehe:dada:didi:kkll";

    char *p[32] = {buf,NULL};
    int i = 0;

    while(p[i++] = strtok(p[i],":"));
    i = 0;
    while(p[i] != NULL)
    {
        printf("%s ",p[i]);
        i++;
    }

}
int main(int argc,char *argv[])
{
    test01();
    return 0;
}
