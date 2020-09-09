/*************************************************************************
	> File Name: choose_sort.c
	> Author:Sjs
	> Mail:303547334@qq.com 
	> Created Time: 2020年07月07日 星期二 23时12分21秒
 ************************************************************************/

#include<stdio.h>

int main(int argc,char *argv[])
{
    int arr[5] = {12,21,2,6,5};
    for(int i = 0; i < 5;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    int i,j,min =0;
    int tmp;
    for(i = 0 ; i < 4; i++)
    {
        min = i;
        for(j = min+1; j < 5; j++)
        {
            if(arr[min] > arr[j])
            {
                min = j;
            }
        }
        if(min != i)
        {
            tmp = arr[i];
            arr[i] = arr[min];
            arr[min] = tmp;
        }
    }
    for(int i = 0; i < 5;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}
