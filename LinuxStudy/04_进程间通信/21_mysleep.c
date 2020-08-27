/*************************************************************************
  > File Name: 21_mysleep.c
  > Author: IvanLxy
  > Mail: yoyiyyo@163.com 
  > Created Time: Thu 06 Aug 2020 03:45:08 PM CST
************************************************************************/
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void sig_alrm(int signo)
{
	/* nothing to do */
}

unsigned int mysleep(unsigned int nsecs)
{
    struct sigaction newact,oldact;
    unsigned int unslept;

    newact.sa_handler = sig_alrm;//new process is sig_alrm
    sigemptyset(&newact.sa_mask);//初始化sa_mask阻塞信号集为0
    newact.sa_flags = 0; // int    sa_flags 信号处理选项,一般为0
    //int sigaction(int signo, const struct sigaction *act, struct sigaction *oact);
    //若act指针非空，则根据act修改该信号的处理动作。
    //若oact指针非空，则通过oact传出该信号原来old的处理动作。
    sigaction(SIGALRM, &newact, &oldact);
    
    alarm(nsecs);
    pause();//阻塞等待供其他进程执行
    
    unslept = alarm(0); //返回alarm成功与否，0 是失败
    sigaction(SIGALRM, &oldact, NULL);//再把原来的信号处理复原
    return unslept;//返回sleep的成功与否
}

int main(void)
{
    while(1)
    {
        mysleep(2);
        printf("Two seconds passed\n");
    }
    return 0;
}
