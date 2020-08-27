/*************************************************************************
  > File Name: 15_pipe.c
  > Author: IvanLxy
  > Mail: yoyiyyo@163.com 
  > Created Time: Tue 04 Aug 2020 03:29:35 PM CST
************************************************************************/
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define MAXLINE 80
void changChar(char *p)
{
    int i = 0;
    while(p[i] != '\0')
    {
        if(p[i] >= 'a' && p[i] <= 'z')
        {
            p[i] = p[i] - ('a' - 'A');
        }
        printf("%C", p[i]);
        i++;
    }
    return;
}

int main(void)
{
    int n;
    int fd1[2], fd2[2];
    pid_t pid;
    char line1[MAXLINE];
    char line2[MAXLINE];

    if(pipe(fd1) < 0)
    {
        perror("pipe1");
        exit(1);
    }
    if(pipe(fd2) < 0)
    {
        perror("pipe1");
        exit(1);
    }

    if((pid = fork()) < 0)
    {
        perror("fork");
        exit(1);            
    }

    if(pid > 0)
    {   /*parent*/
        close(fd1[0]); //关闭fd1读,只写
        close(fd2[1]); //关闭fd2写，只读
        write(fd1[1], "hello word\n", 12);
        read(fd2[0], line2, MAXLINE);
        wait(NULL);
        printf("Parent Rec:%s",line2);
    }else
    {   /* child*/    
        close(fd1[1]); //关闭fd1写,只读
        close(fd2[0]); //关闭fd2读，只写
        n = read(fd1[0], line1, MAXLINE);
        changChar(line1);
        write(fd2[1], line1, n);
    }

}






