/*************************************************************************
  > File Name: 13_atexit.c
  > Author: IvanLxy
  > Mail: yoyiyyo@163.com 
  > Created Time: Tue 04 Aug 2020 11:04:10 AM CST
************************************************************************/
#include <stdlib.h>
#include <stdio.h>

static void my_exit1(void)
{
    printf("first exit handler \n");
}

static void my_exit2(void)
{
    printf("second eixt handler \n");
}

int main(void)
{   
    //因为exit()函数需执行一系列的操作进行清理，这些终止处理函数实际上就是完成各种所谓的清除操作的实际执行体。
    //而atexit函数就是注册清理操作程序到程序列表（最多32个）中，并且注册和最后清理调用顺序相反
    if(atexit(my_exit2) != 0)
    {
        printf("can't register my_exit2\n");
    }
    if(atexit(my_exit1) != 0)
    {
        printf("can't register my_exit1\n");
    }
    printf("main is done\n");
    return 0;
}
