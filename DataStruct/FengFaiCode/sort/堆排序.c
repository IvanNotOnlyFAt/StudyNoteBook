/*************************************************************************
    > File Name: 堆排序.c
    > Author: Nfh
    > Mail: 1024222310@qq.com
    > Created Time: 2020年08月15日 星期六 14时41分05秒
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

// 交换元素的值
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


// 大根堆调整
void adjustHeap(int *arr, int start, int end)
{
    int i = 0;
    int par = start;
    int value = arr[start];
    if(start == end)
        return ;
    for(i = start * 2 + 1; i < end; i= i * 2 + 1)
    {
        if((i + 1 < end) && (arr[i] < arr[i + 1]))
            i++;

        if(value >= arr[i])
            break;
        else
        {
            arr[par] = arr[i];
            par = i;
        }
    }
    arr[par] = value;
}

// 堆排序
void heapSort(int *arr, int len)
{
    int i = 0;
    // 初始化大根堆
    for(i = len / 2 - 1; i >= 0; i--)
    {
        adjustHeap(arr, i, len);
    }
    for(i = len - 1; i > 0; i--)
    {
        swap(arr, arr + i);
        adjustHeap(arr, 0, i);
    }
}
// 测试效率
void testEffective(int len, void(*sort)(int *, int))
{
    struct timeval tBegin,tEnd;
    double time=0;


    int *temp = (int *)malloc(sizeof(int) * len);
    assert(temp != NULL);

    setArray(temp, len);
    gettimeofday(&tBegin, NULL);
    sort(temp, len);
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

    heapSort(arr, NUM);
    printf("排序后：");
    displayResult(arr, NUM);

    testEffective(MAX, heapSort);

    return 0;
}

