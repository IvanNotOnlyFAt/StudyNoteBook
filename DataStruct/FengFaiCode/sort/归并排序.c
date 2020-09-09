/*************************************************************************
    > File Name: 归并排序.c
    > Author: Nfh
    > Mail: 1024222310@qq.com
    > Created Time: 2020年08月15日 星期六 16时40分07秒
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

// 归并
void merge(int *arr, int *arr_v, int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = 0;
    while(i <= mid && j <= high)
    {
        if(arr[i] < arr[j])
        {
            arr_v[k++] = arr[i++];
        }else
        {
            arr_v[k++] = arr[j++];
        }
    }
    while(i <= mid)
        arr_v[k++] = arr[i++];
    while(j <= high)
        arr_v[k++] = arr[j++];
    for(i = low, k = 0; i <= high; i++, k++)
    {
        arr[i] = arr_v[k];
    }
}

// 递归处
void mergeWhile(int *arr, int *arr_v, int low, int high)
{
    int mid = (low + high) / 2;
    if(low < high)
    {
        mergeWhile(arr, arr_v, low, mid);
        mergeWhile(arr, arr_v, mid + 1, high);
        merge(arr, arr_v, low, mid, high);
    }
}

// 归并排序
void mergeSort(int *arr, int len)
{
    int *arr_v = (int *)malloc(sizeof(int) * len);
    assert(arr_v != NULL);
    mergeWhile(arr, arr_v, 0, len - 1);
	free(arr_v);
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

    mergeSort(arr, NUM);
    printf("排序后：");
    displayResult(arr, NUM);

    testEffective(MAX, mergeSort);

    return 0;
}

