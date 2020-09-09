/*************************************************************************
	> File Name: sort.c
	> Author: 
	> Mail: 
	> Created Time: 2020年06月28日 星期日 09时42分30秒
 ************************************************************************/

#include<stdio.h>
int main(int argc, char *argv[])
{
    int arr[10] = {0};
    int i = 0;
    int temp;
    //输入10个int

    for(;i < 10; i++ )
    {
        scanf("%d",&arr[i]);
    }

    //排序
    for(i = 0; i < 10; i++)
    {
        for(int j = i+1; j < 10; j++)
        {
            if(arr[i] > arr[j])
            {
                temp = arr[i];   
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        
    }

    //输出
    for(i = 0; i < 10; i++)
    {
        printf("%d\n",arr[i]);
    }
    return 0;
}
