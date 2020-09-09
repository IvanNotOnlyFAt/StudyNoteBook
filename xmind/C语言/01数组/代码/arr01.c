/*************************************************************************
	> File Name: arr01.c
	> Author: 
	> Mail: 
	> Created Time: 2020年06月26日 星期五 10时35分12秒
 ************************************************************************/

#include<stdio.h>
int main(int argc ,char *argv[])
{
    int arr[5] = {0};
    int n = sizeof(arr)/sizeof(arr[0]);
    int i = 0;
    int max,min,sum = 0;
    for(; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    max = arr[0];
    min = arr[0];

    for(i = 0; i < n; i++)
    {
        //最大值
        if(max < arr[i])
        {
            max = arr[i];
        }
        //最小值
        if(min > arr[i])
        {
            min = arr[i];
        }
        //平均值
        sum = sum + arr[i];
       // printf("%d ",arr[i]);
    }

    printf("最大值: %d\n",max);
    printf("最小值: %d\n",min);
    printf("平均值: %d\n",sum/n);

    return 0;
}
