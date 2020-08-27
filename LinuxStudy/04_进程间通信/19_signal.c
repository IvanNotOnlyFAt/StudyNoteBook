/*************************************************************************
  > File Name: 19_signal.c
  > Author: IvanLxy
  > Mail: yoyiyyo@163.com 
  > Created Time: Thu 06 Aug 2020 02:31:15 PM CST
************************************************************************/
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void my_signalfun(int sign_no) //
{
    if(sign_no == SIGINT)
        printf("The SIGINT's new process funtion\n");
    else if(sign_no == SIGQUIT)
        printf("The SIGQUIT's new process funtion\n");
}

int main()
{
    printf("Waiting for signal SIGINT or SIGQUIT \n");

    signal(SIGINT, my_signalfun);
    signal(SIGQUIT,my_signalfun);
    while (1)
    {
        printf("1\n");
        sleep(1);
        printf("2\n");
        sleep(1);
        printf("3\n");
        sleep(1);
        printf("4\n");
        sleep(1);
        printf("5\n");
        sleep(1);
    }
    exit(0);
}
