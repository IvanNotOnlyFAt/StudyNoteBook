/*************************************************************************
  > File Name: 20_signalset.c
  > Author: IvanLxy
  > Mail: yoyiyyo@163.com 
  > Created Time: Thu 06 Aug 2020 02:53:48 PM CST
************************************************************************/
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

//打印 set 信号集中的32个位数
void print_signalset(const sigset_t *set)
{
    int i;
    for(i = 1;i <= 32; i++)
    {
        //int sigismember(const sigset_t *set, int signo);
        //用于判断一个信号集的有效信号中是否包含某种信号，
        //包含则返回1，不包含则返回0，出错返回-1。
        if(sigismember(set, i) == 1)
        {
            putchar('1');
        }else
        {
            putchar('0');
        }
    }
    printf("\n");
}

int main(void)
{
    sigset_t s,p;
    //int sigemptyset(sigset_t *set);
    //sigemptyset初始化set所指向的信号集为 0
    // int sigfillset(sigset_t *set);同上，不同的只是置1
    sigemptyset(&s);
    //int sigaddset(sigset_t *set, int signo);
    //int sigdelset(sigset_t *set, int signo);
    //在set信号集中添加或删除某种有效信号
    sigaddset(&s, SIGINT);
    sigaddset(&s, SIGQUIT);
    //int sigprocmask(int how, const sigset_t *set, sigset_t *oset);
    //阻塞信号集也叫做当前进程的信号屏蔽字（Signal Mask）
    //Sigprocmask是设置或者获取block位的，
    //SIG_BLOCK 是添加到当前信号屏蔽字的信号，s当前的信号集|原有的信号集
    //而sigpending是获取pending位的
    sigprocmask(SIG_BLOCK, &s, NULL);
    printf("print the bolck *set:\n");
    print_signalset(&s);
    printf("print the pending *set:\n");
    while(1)
    {
        //int sigpending(sigset_t *set);
        //sigpending读取当前进程的未决信号集，通过set参数传出。
        sigpending(&p);
        //p就是传出的未决信号集，并用print_signalsetd打印出来
        print_signalset(&p);
        sleep(1);
    }
    return 0;
    //最后由程序可知，一开始两个信号未被产生，pending是0
    //但是都被sigprocmask阻塞，所以block两个1，
    //当信号产生时，pengding变成两个1，但是信号不执行，是因为仍被阻塞，不能递达
}

