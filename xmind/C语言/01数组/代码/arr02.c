/*************************************************************************
	> File Name: arr02.c
	> Author: 
	> Mail: 
	> Created Time: 2020年06月26日 星期五 11时02分11秒
 ************************************************************************/

#include<stdio.h>
int main(int argc, char *argv[])
{
    int arr[3][4] ={{1,2,3,4},{3},{4}};

    int i = 0;
    int j = 0;

    for(i = 0;i < 3; i++)
    {
        for(j = 0; j < 4; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
