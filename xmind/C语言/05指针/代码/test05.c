/*************************************************************************
	> File Name: test05.c
	> Author:Sjs
	> Mail:303547334@qq.com 
	> Created Time: 2020年07月02日 星期四 21时07分35秒
 ************************************************************************/

#include<stdio.h>
int num = 10;
void my_set_p(int **p)
{
    *p = &num;
}
//减少二级指针
int* get_addr(void)
{
    return &num;
}
void test05(void)
{
    int *p = NULL;

   // my_set_p(&p);
    p = get_addr();

    printf("*p = %d\n",*p);
}

int main(int argc , char *argv[])
{
    test05();
    return 0;
}
