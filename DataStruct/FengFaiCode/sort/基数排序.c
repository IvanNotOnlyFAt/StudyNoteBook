/*************************************************************************
    > File Name: 基数排序.c
    > Author: Nfh
    > Mail: 1024222310@qq.com
    > Created Time: 2020年08月17日 星期一 10时06分04秒
 ************************************************************************/

#include <stdlib.h>
#include <time.h>
#include<sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <assert.h>

#define NUM 20
#define MAX 100000

#define N 6
#define BUCKET 10

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

// 获取每一位的值
int getBate(int value, int k)
{
    int r[N] = {1, 10, 100, 1000, 10000, 100000};
    int num = value / r[k - 1] % 10;
    return num;
}

// 最高位优先（MSD）递归实现
void MSDBucket1(int *arr, int *arr_v, int left, int right, int k)
{

}

// 最低位优先（LSD）递归实现
void LSDBucket1(int *arr, int *arr_v, int left, int right, int k)
{
    int i, j, value;
    int count[BUCKET] = {0};    // 记录桶中每个元素的个数
    int posit[BUCKET] = {0};    // 记录元素存放在arr_v时的开始位置

    if(left >= right || k > N)
        return ;
    for(i = left; i <= right; i++)
    {
        value = getBate(arr[i], k);
        count[value]++;
    }

    posit[0] = 0;
    for(i = 1; i < BUCKET; i++)
    {
        posit[i] = posit[i - 1] + count[i - 1];
    }
    for(i = left; i <= right; i++)
    {
        value = getBate(arr[i], k);
        arr_v[posit[value]] = arr[i];
        posit[value]++;
    }

    for(i = left; i <= right; i++)
    {
        arr[i] = arr_v[i];
    }
    LSDBucket1(arr, arr_v, left, right, ++k);
}

// 最低位优先（LSD）迭代实现
void LSDBucket2(int *arr, int *arr_v, int left, int right, int k)
{
    if(left >= right || k > N)
        return ;
    while(k < N)
    {
        int i, j, value;
        int count[BUCKET] = {0};    // 记录桶中每个元素的个数
        int posit[BUCKET] = {0};    // 记录元素存放在arr_v时的开始位置
        for(i = left; i <= right; i++)
        {
            value = getBate(arr[i], k);
            count[value]++;
        }

        posit[0] = 0;
        for(i = 1; i < BUCKET; i++)
        {
            posit[i] = posit[i - 1] + count[i - 1];
        }
        for(i = left; i <= right; i++)
        {
            value = getBate(arr[i], k);
            arr_v[posit[value]] = arr[i];
            posit[value]++;
        }

        for(i = left; i <= right; i++)
        {
            arr[i] = arr_v[i];
        }
        k++;
    }
}

// 基数排序
void bucketSort(int *arr, int len)
{
    int *arr_v = (int *)malloc(sizeof(int) * len);
    assert(arr_v != NULL);
    LSDBucket2(arr, arr_v, 0, len - 1, 1);
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

    bucketSort(arr, NUM);
    printf("排序后：");
    displayResult(arr, NUM);

    testEffective(MAX, bucketSort);

    return 0;
}

