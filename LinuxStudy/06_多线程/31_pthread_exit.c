/*************************************************************************
  > File Name: 31_pthread_exit.c
  > Author: IvanLxy
  > Mail: yoyiyyo@163.com 
  > Created Time: Thu 13 Aug 2020 11:31:40 AM CST
************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *thr_fn1(void *arg)
{
    printf("thread 1 exit by returning\n");
    return (void *)1;
}

void f(void)
{
    printf("thread 2 exit by self pthread_exit\n");
    //void pthread_exit(void *retval);
    //retval（撤回）： pthread_exit调用者线程的返回值，可由其他函数和pthread_ join来检测获取。
    pthread_exit((void *)2);
}

void *thr_fn2(void *arg)
{
    f();
    while(1)
    {
        //就没有机会进入该循环
        printf("*****thr_fn2******\n");
    }
}
void *thr_fn3(void *arg)
{
    while(1)
    {
        printf("thread 3 wrinting....will exit by other pthread_cancel\n");
        sleep(1);   
    }
}

int main()
{
    pthread_t tid;
    void *tret;
    //tret用来存储被等待线程的返回值,调用该函数的线程将挂起等待，直到tid为thread的线程终止
    //int pthread_join(pthread_t thread, void **retval);
    pthread_create(&tid, NULL, thr_fn1, NULL);
    pthread_join(tid, &tret);
    printf("%u:thread 1 exit code %d\n", (unsigned int)tid, (int)tret);

    pthread_create(&tid, NULL, thr_fn2, NULL);
    pthread_join(tid, &tret);
    printf("%u:thread 2 exit code %d\n", (unsigned int)tid, (int)tret);


    pthread_create(&tid, NULL, thr_fn3, NULL);
    /*******/
    sleep(3);
    pthread_cancel(tid);    //从一个线程通知另一个线程结束
    /*******/
    pthread_join(tid, &tret);
    printf("%u:thread 3 exit code %d\n", (unsigned int)tid, (int)tret);

}
