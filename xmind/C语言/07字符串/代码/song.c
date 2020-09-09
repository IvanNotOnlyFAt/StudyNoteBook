/*************************************************************************
	> File Name: song.c
	> Author:Sjs
	> Mail:303547334@qq.com 
	> Created Time: 2020年07月04日 星期六 13时59分41秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
int main(int argc,char *argv[])
{
    int m1,s1 = 0;
    int m2,s2 = 0;
    char song[128] = "";

    char msg[128] = {"[12:13:32][12:27:32]给我一个机会"};

    sscanf(msg,"[%d:%d%*3s][%d:%d%*3s]%s",&m1,&s1,&m2,&s2,song);

    printf("%d-%d\n",m1,s1);
    printf("%d-%d\n",m2,s2);
    printf("%s\n",song);
}
