/*************************************************************************
	> File Name: main.c
	> Author: 
	> Mail: 
	> Created Time: 2020年06月26日 星期五 09时51分30秒
 ************************************************************************/

#include<stdio.h>
int main(int argc ,char *argv)
{
    int arr[10]={1,2,3,4,5};
    printf("数组大小:%d\n",sizeof(arr));
    int i = 0;
    //
    //遍历数组
    for(i = 0; i < 10; i++)
    {
        printf("%d\n",arr[i]);
    }
    //输出混乱,必须初始化.

    return 0;
}
