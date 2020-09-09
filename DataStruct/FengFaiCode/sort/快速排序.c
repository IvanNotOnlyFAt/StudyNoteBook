/*************************************************************************
  > File Name: 快速排序.c
  > Author: Nfh
  > Mail: 1024222310@qq.com
  > Created Time: 2020年08月15日 星期六 10时29分23秒
 ************************************************************************/
#include <stdlib.h>
#include <time.h>
#include<sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <assert.h>

#define NUM 20
#define MAX 100000

// 设置数组的元素值
void setArray(int *arr, int len)
{
    int i = 0;
    srand(time(NULL));              // 设置随机种子
    for(i = 0; i < len; i++)
    {
        int rm = rand() % MAX + 1;  // 在【1-100】之间制造随机数
        arr[i] = rm;
    }
}

// 打印数组
void displayResult(int *arr, int len)
{
    int i = 0;
    for(i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 快速排序0
void quickSortMain0(int *arr, int low, int high)
{
    if(low >= high)
        return;
    int x = low, y = high, key = arr[low];
    while(x < y)
    {
        while(x < y && arr[y] >= key)
            y--;
        if(x < y)
            arr[x++] = arr[y];
        while(x < y && arr[x] <= key)
            x++;
        if(x < y)
            arr[y--] = arr[x];
    }
    arr[x] = key;
    quickSortMain0(arr, low, x - 1);
    quickSortMain0(arr, x + 1, high);
}


// 快速排序1
void quickSortMain1(int *arr, int low, int high)
{
    while(low < high)
    {
        int x = low, y = high, key = arr[low];
        while(x < y)
        {
            while(x < y && arr[y] >= key)
                y--;
            if(x < y)
                arr[x++] = arr[y];
            while(x < y && arr[x] <= key)
                x++;
            if(x < y)
                arr[y--] = arr[x];
        }
        arr[x] = key;
        quickSortMain1(arr, low, x - 1);
        low = x + 1;
    }
    return ;
}

// 快速排序2
void quickSortMain2(int *arr, int low, int high)
{
    while(low < high)
    {
        int x = low, y = high, key = arr[low];
        while(x <= y)
        {
            while(arr[y] > key)
                y--;
            while(arr[x] < key)
                x++;
            if(x <= y)
            {
                int n = arr[x];
                arr[x] = arr[y];
                arr[y] = n;
                x++;
                y--;
            }
        }
        quickSortMain2(arr, low, y);
        low = x;
    }
    return ;
}

// 快速排序3
void quickSortMain3(int *arr, int low, int high)
{
    while(low < high)
    {
        int x = low, y = high, key = arr[low + rand() % (high - low + 1)];
        while(x <= y)
        {
            while(arr[y] > key)
                y--;
            while(arr[x] < key)
                x++;
            if(x <= y)
            {
                int n = arr[x];
                arr[x] = arr[y];
                arr[y] = n;
                x++;
                y--;
            }
        }
        quickSortMain3(arr, low, y);
        low = x;
    }
    return ;
}

void quickSort(int *arr, int len, void(*sortType)(int *, int, int))
{
    sortType(arr, 0, len - 1);
}

// 测试效率
void testEffective(int len, void(*sort)(int *, int, void(*)(int *, int, int)), void(*sortType)(int *, int, int))
{
    struct timeval tBegin,tEnd;
    double time=0;


    int *temp = (int *)malloc(sizeof(int) * len);
    assert(temp != NULL);

    setArray(temp, len);
    gettimeofday(&tBegin, NULL);
    sort(temp, len, sortType);
    gettimeofday(&tEnd, NULL);
    time = tEnd.tv_sec-tBegin.tv_sec + (tEnd.tv_usec-tBegin.tv_usec)/1000000.0;
    printf("排序[%d]数据所需时间为：%5.3lf ms\n", len, time * 1000);
    free(temp);
}

int main()
{
    int arr[NUM] = {0};
    setArray(arr, NUM);

    printf("排序前：");
    displayResult(arr, NUM);

    quickSort(arr, NUM, quickSortMain0);
    printf("排序后：");
    displayResult(arr, NUM);

    printf("快排0：");
    testEffective(MAX, quickSort, quickSortMain0);
    printf("快排1：");
    testEffective(MAX, quickSort, quickSortMain1);
    printf("快排2：");
    testEffective(MAX, quickSort, quickSortMain2);
    printf("快排3：");
    testEffective(MAX, quickSort, quickSortMain3);

    return 0;
}

