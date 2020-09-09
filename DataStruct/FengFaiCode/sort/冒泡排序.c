/*************************************************************************
    > File Name: 冒泡排序.c
    > Author: Nfh
    > Mail: 1024222310@qq.com
    > Created Time: 2020年08月15日 星期六 09时25分57秒
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

// 冒泡排序
void bubbleSort(int *arr, int len)
{
    int i = 0, j = 0;
    for(i = len; i > 0; i--)
    {
        for(j = 1; j < i; j++)
        {
            if(arr[j - 1] > arr[j])
            {
                int n = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = n;
            }
        }
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

    bubbleSort(arr, NUM);
    printf("排序后：");
    displayResult(arr, NUM);

    testEffective(MAX, bubbleSort);

    return 0;
}

