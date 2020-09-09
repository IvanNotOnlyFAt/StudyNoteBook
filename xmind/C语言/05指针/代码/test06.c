/*************************************************************************
	> File Name: test06.c
	> Author:Sjs
	> Mail:303547334@qq.com 
	> Created Time: 2020年07月02日 星期四 21时35分59秒
 ************************************************************************/

#include<stdio.h>
//数组大小
#define SIZEOF(x,y) sizeof(x)/sizeof(y);
int main()
{
    int arr[5] = {1,2,3,4,5};
    int n = SIZEOF(arr,arr[0]);
    printf("%d\n",n);
    return 0;
}
