/*************************************************************************
	> File Name: test02.c
	> Author:Sjs
	> Mail:303547334@qq.com 
	> Created Time: 2020年07月01日 星期三 22时25分40秒
 ************************************************************************/

#include<stdio.h>
void test(void)
{
    int arr[5] = {0};
    int n = sizeof(arr) / sizeof(arr[0]);
    //&arr 和 arr 虽然相同但是指针类别不同
    int *p = arr;
    int *p2 = &arr;
    
    printf("请输入%d个字符:\n",n);
    for(int i = 0; i< n; i++)
    {
        scanf("%d",p);
        p++;
    }
    for(int i = 0; i < n; i++)
    {
        //*(arr + i)
        printf("%d ", arr[i]);
    }
    return;
}
int main(int argc , char *argv[])
{
    //test();
    int a[5] = {0,1,2,3,4};
     //&a[0] = &*(a+0) = a+0 = a;
    int *p = &a[0];
    printf("a = %p\n",p);
    printf("&a[0] = %p\n",a);
    for(int i = 0; i < 5; i++){
        printf("%d\n",*p);
        p = p + 1;
    }
    return 0;
}
