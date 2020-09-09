/*************************************************************************
	> File Name: mystruct_memory.c
	> Author:Sjs
	> Mail:303547334@qq.com 
	> Created Time: 2020年07月06日 星期一 09时29分21秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
typedef struct stu 
{
    double a;
    int num;
}STU;
int main(int argc,char *argv[])
{
    STU stu = {1,2};
//更改 a的类型  char 改为double  地址就变为8B;
    printf("&stu.a %p",&stu.a);
    printf("&stu.num %p",&stu.num);
    return 0;
}
