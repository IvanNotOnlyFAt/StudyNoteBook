/*************************************************************************
	> File Name: malloc_test01.c
	> Author:Sjs
	> Mail:303547334@qq.com 
	> Created Time: 2020年07月03日 星期五 10时30分37秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
void test_malloc()
{
    int *addr = NULL;
    addr = (int *)malloc(sizeof(int));
    if(addr == NULL)
    {
        printf("malloc fail");
        return;
    }
    printf("*addr = %d\n",*addr);

    //对堆区清零
    memset(addr,0,sizeof(int));
    
    //查看空间内容
    printf("%d\n",*addr);

    //赋值
    *addr = 1000;
    printf("%d\n",*addr);

    //释放堆区空间
    free(addr);
    //指针不用置空,因为局部放弃
    return;
}
int get_n(void)
{
    int n = 0;
    printf("请输入数组大小: ");
    scanf("%d", &n);
    return n;
}
int* get_addr(int n)
{
    printf("分配大小: %d\n",n*sizeof(int));
    return (int *)malloc(n*sizeof(int));
}
void my_input(int *arr,int n)
{
    //将*arr清零
    memset(arr,0,n*sizeof(int));
    printf("请输入%d个数值\n",n);
    //键盘输入
    for(int i = 0; i < n; i++)
    {
        scanf("%d", arr+i);
    }

    //输出
    for(int i = 0 ; i < n ; i++)
    {
        printf("%d " ,arr[i]);
        //printf("%d ", *(arr+i));
    }
    printf("\n");
    return;
}
void  test02(void)
{
    int *arr = NULL;
    int n = 0;

    //得到用户输入大小
    n = get_n();

    //得到分配地址
    arr = get_addr(n);
    if(arr == NULL)
    {
        printf("malloc fail");
        return;
    }
    printf("arr = %d\n",*arr);
    //获取键盘输入
    my_input(arr, n);

    free(arr);
}
int main(int argc , char *argv[])
{
    test02();
    return 0;
}
