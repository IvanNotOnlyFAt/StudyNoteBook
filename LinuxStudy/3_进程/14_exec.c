/*************************************************************************
  > File Name: 14_exec.c
  > Author: IvanLxy
  > Mail: yoyiyyo@163.com 
  > Created Time: Tue 04 Aug 2020 02:57:42 PM CST
************************************************************************/
#include <unistd.h> //execlp()
#include <stdlib.h>

int main(void)
{
	//int execlp(const char *file, const char *arg, ...);
    execlp("ps", "ps", "-o", "pid,ppid,pgrp,session,tpgid,comm", NULL);
    perror("exec ps");
    exit(1);
}
