/*************************************************************************
  > File Name: 16_popen.c
  > Author: IvanLxy
  > Mail: yoyiyyo@163.com 
  > Created Time: Tue 04 Aug 2020 05:30:44 PM CST
************************************************************************/
#include <stdio.h>  //popen fgets
#include <stdlib.h> //exit
#include <string.h> //strstr

#define BUFSIZE 1024

int main()
{
    FILE *fp;
    char *cmd = "printenv";
    char buf[BUFSIZE];
    buf[BUFSIZE-1] = '\0';
    
    //popen() 函数通过创建一个标准io管道传输“cmd”，
    //调用 fork 产生一个子进程，
    //执行一个 shell 以运行命令来开启一个进程。
    //如果成功，返回一个新的文件流。可用fgets读取文件流
    //这个进程必须由 pclose() 函数关闭，整个过程类似于调用systrem
    if((fp=popen(cmd,"r")) == NULL)
    {
        perror("popen");
    }
    while((fgets(buf,BUFSIZE,fp)) != NULL)
    {
        // char *strstr(const char *haystack, const char *needle)
        // 在字符串 haystack 中查找第一次出现字符串 needle 的位置
        // 返回在 haystack 中第一次出现 needle 字符串的位置如果
        // 未找到则返回 null。
        if (strstr(buf,"PATH") != NULL)
        {
            printf("%s",buf);
        }

    }
    pclose(fp);
    exit(0);
}
