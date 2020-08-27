/*************************************************************************
  > File Name: 30_pthread.c
  > Author: IvanLxy
  > Mail: yoyiyyo@163.com 
  > Created Time: Thu 13 Aug 2020 11:25:08 AM CST
************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_t ntid;

void printids(const char *s)
{
	pid_t      pid;
	pthread_t  tid;

	pid = getpid();                      /*得到进程ID*/
	tid = pthread_self();             /*得到线程ＩＤ*/
	printf("%s pid %u tid %u (0x%x)\n", s, (unsigned int)pid,
	       (unsigned int)tid, (unsigned int)tid);
}

void *thr_fn(void *arg)
{
	printids(arg);
	return NULL;
}

int main(void)
{
	int err;
// int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);
	err = pthread_create(&ntid, NULL, thr_fn, "new thread: ");
	if (err != 0)
	{
		fprintf(stderr, "can't create thread: %s\n", strerror(err));
		exit(1);
	}
	
	printids("main thread:");
	sleep(1);

	return 0;
}
