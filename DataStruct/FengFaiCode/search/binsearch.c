/*************************************************************************
	> File Name: binsearch.c
	> Author: Nfh
	> Mail: 1024222310@qq.com 
	> Created Time: 2020年08月10日 星期一 15时07分50秒
 ************************************************************************/

#include <stdio.h>

// 递归二分查找
int binSearch1(int n, int *arr, int low, int high)
{
    if(low <= high)
    {
        int mid = (low + high) / 2;
        if(n == arr[mid])
        {
            printf("查找成功：");
            return arr[mid];
        }else if(n < arr[mid])
        {
            binSearch1(n, arr, low, mid - 1);
        }else
        {
            binSearch1(n, arr, mid + 1, high);
        }
    }else
    {
        printf("查找失败：");
        return -1;
    }
}

// 迭代二分查找
int binSearch2(int n, int *arr, int low, int high)
{
    while(low <= high)
    {
        int mid = (low + high) / 2;
        if(n == arr[mid])
        {
            printf("查找成功：");
            return arr[mid];
        }else if(n < arr[mid])
        {
            high = mid - 1;
        }else
        {
            low = mid + 1;
        }
    }
    printf("查找失败：");
    return -1;
}

int main()
{
    int arr[] = {5, 13, 19, 21, 37, 56, 64, 75, 80, 88, 92};
    int len = sizeof(arr) / sizeof(int);
    printf("有序表为：[ ");
    int i;
    for(i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("]\n");
    char c;
    printf("输入选择 <递归二分> 还是 <迭代二分>（1为递归二分）（2为迭代二分）：\n");
    scanf("%c", &c);
    int n;
    printf("请输入需要查找的数字：");
    scanf("%d", &n);
    switch(c)
    {
    case '1': printf("%d\n", binSearch1(n, arr, 0, len - 1)); break;
    case '2': printf("%d\n", binSearch2(n, arr, 0, len - 1)); break;
    }

    return 0;
}
