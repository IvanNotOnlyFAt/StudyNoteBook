/*************************************************************************
	> File Name: sort_choose.c
	> Author:Sjs
	> Mail:303547334@qq.com 
	> Created Time: 2020年07月07日 星期二 21时24分15秒
 ************************************************************************/

#include<stdio.h>

int main(int argc,char *argv[])
{
    int arr[5] = {0};
    printf("请输入要排序的数组元素,5个\n");
    for(int i = 0; i < 5; i++)
    {
        scanf("%d",arr+i);    
    }
    int min,j;
    for(int i = 0 ; i  < 5 ; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");

    for(int i = 0; i < 4; i++)
    {
        int min = i;
        for(j = i+1; j < 5; j++ )
        {
            if(arr[min] > arr[j])
            {
                min = j;
            }
        }
        if(min != i)
        {
            int tmp = arr[min];
            arr[j] = arr[min];
            arr[min] = tmp;
        }
    }
    
    for(int i = 0 ; i  < 5 ; i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}
