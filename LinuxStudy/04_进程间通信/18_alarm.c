/*************************************************************************
  > File Name: 18_alarm.c
  > Author: IvanLxy
  > Mail: yoyiyyo@163.com 
  > Created Time: Thu 06 Aug 2020 02:20:21 PM CST
************************************************************************/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ret;
    // alarm也称为闹钟函数，它可以在进程中设置一个定时器
    // 当定时器指定的时间到时:它就向进程发送SIGALARM信号。
    ret=alarm(5);
    //pause()函数是用于将调用进程挂起直到捕捉到信号为止
    //如果没有pause'不等alarm时间到发信号，程序就退出，
    //并printf ret=0 alarm失败返回0取消闹钟
    pause();
    printf("I have been waken up%d.\n",ret);
}
