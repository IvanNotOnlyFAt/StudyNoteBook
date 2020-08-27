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
    struct sigaction newact, oldact;
    unsigned int unslept;
    /*********************/
    sigset_t newmask, oldmask, suspmask;
    /*********************/
    
    /* set our handler, save previous information */
    newact.sa_handler = sig_alrm;//new process is sig_alrm
    sigemptyset(&newact.sa_mask);//初始化sa_mask阻塞信号集为0
    newact.sa_flags = 0; // int    sa_flags 信号处理选项,一般为0
    //int sigaction(int signo, const struct sigaction *act, struct sigaction *oact);
    //若act指针非空，则根据act修改该信号的处理动作。
    //若oact指针非空，则通过oact传出该信号原来old的处理动作。
    sigaction(SIGALRM, &newact, &oldact);
    
    /**********提前设置SIGALRM信号为阻塞态***********/
    /* block SIGALRM and save current signal mask */
    sigemptyset(&newmask);
    sigaddset(&newmask, SIGALRM);
    sigprocmask(SIG_BLOCK, &newmask, &oldmask); 
    /************************************************/

    alarm(nsecs);
    //pause();//阻塞等待供其他进程执行

    /****创造一个不阻塞的屏蔽信号集给suspend用**********/
    /****对时序要求严格的场合下都应该调用sigsuspend*****/
    //int sigsuspend(const sigset_t *sigmask);
    //sigsuspend时，进程的信号屏蔽字由sigmask参数指定，
    //指定sigmask来临时解除对某个信号的屏蔽，然后挂起等待
    //sigsuspend返回时，进程的信号屏蔽字恢复为原来的值，
    //如果原来对该信号是屏蔽的，从sigsuspend返回后仍然是屏蔽的。
    suspmask = oldmask;//获得原来不屏蔽时候的，屏蔽信号集
    sigdelset(&suspmask, SIGALRM); /*删除之前的闹钟信号阻塞位*/
    sigsuspend(&suspmask); /* wait for any signal to be caught */
    /***************************************************/

    unslept = alarm(0); //清除alarm之前设置的定时器闹钟，并返回剩下的时间

    //SIG_SETMASK 设置当前信号屏蔽字为set所指向的值，相当于mask=set
    sigprocmask(SIG_SETMASK, &oldmask, NULL);//再把原来的屏蔽信号集复原
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
