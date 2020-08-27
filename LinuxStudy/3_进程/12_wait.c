/*************************************************************************
  > File Name: 12_wait.c
  > Author: IvanLxy
  > Mail: yoyiyyo@163.com 
  > Created Time: Tue 04 Aug 2020 09:28:23 AM CST
************************************************************************/
#include <sys/types.h>  //typedef __pid_t pid_t;
#include <sys/wait.h>   //waitpid
#include <unistd.h>     //unix's stdio  void _exit(int); pid_t fork(void);
#include <stdio.h>      //printf
#include <stdlib.h>     //exit()

int main(void)
{
    pid_t pid;
    pid = fork();
    if(pid < 0)
    {
        perror("fork failed");
        exit(1);
    }
    
    if(pid == 0)
    {
        /*child*/
        int i;
        for(i = 10; i > 0; i--)
        {
            printf("This is the child \n");
            sleep(1);
        }
        exit(3);   //The status is 3 and return to wait or waitpid;
    }else
    {
        int stat_val;
        waitpid(pid, &stat_val, 0);
	//等待pid的进程， &stat_val是子进程退出状态的输出，0是同wait的阻塞
	//如果第三个参数非0，WNOHANG不阻塞，WUNTRACED
	//wait等待第一个终止的子进程，而waitpid可以通过pid参数指定等待哪一个子进程。
    /*================================================================*/
	//子进程的终止信息在一个int中包含了多个字段，用宏定义可以取出其中的每个字段：

	if(WIFEXITED(stat_val))		//如果子进程是正常终止的，WIFEXITED取出的字段值非零，
        {
					//如果子进程是正常终止的，WEXITSTATUS取出的字段值就是子进程的退出状态，这里exit(3)，所以正常退出就反馈为3；

            printf("Child exited with code %d\n", WEXITSTATUS(stat_val));
        }else if(WIFSIGNALED(stat_val))	//如果子进程是收到信号而异常终止的，WIFSIGNALED取出的字段值非零
        {
					//如果子进程是收到信号而异常终止的，WTERMSIG取出的字段值就是信号的编号。--如9 就是kill杀死，15就是终止结束
            printf("Child terminated abnormally,signal %d\n", WTERMSIG(stat_val));
        }
    }
    return 0;
       
}




