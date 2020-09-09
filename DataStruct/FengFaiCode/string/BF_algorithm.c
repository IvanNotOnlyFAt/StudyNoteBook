/*************************************************************************
    > File Name: BF_algorithm.c
    > Author: Nfh
    > Mail: 1024222310@qq.com 
    > Created Time: 2020年08月05日 星期三 14时03分24秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define MAX 256

typedef struct SString
{
    char str[MAX];
    int length;
}SString;

// 初始化字符串
int initString(SString *sst, char str[])
{
    int i = 0;
    while(str[i] != '\0')
    {
        sst->str[i] = str[i];
        i++;
    }
    sst->length = i;
    return 1;
}

// 模式匹配算法，注意这里传入的pos是从1开始数的，而不是从0开始
int indexString(SString s, SString t, int pos)
{
    if(pos < 1 || pos > s.length)
    {
        printf("pos is errno!\n");
        exit(1);
    }
    int i = pos -1;
    int j = 0;
    char *sp = s.str;
    char *tp = t.str;

    while(i < s.length && j < t.length)
    {
        if(sp[i] == tp[j])
        {
            i++;
            j++;
        }else
        {
            i = i - j + 1;          // 回退回去从上次开始匹配的位置+1在进行匹配
            j = 0;
        }
    }
    if(j == t.length)
    {
        printf("匹配成功!\n");
        return (i - j - pos + 1);   // 返回pos后的匹配的位置
    }else
    {
        printf("匹配失败!\n");
        return 0;                   // 未匹配到则返回0
    }
}

int main()
{
    SString s, t;
    int pos;
    initString(&s, "abcd1234");
    initString(&t, "123");
    printf("s: %s\n", s.str);
    printf("t: %s\n", t.str);
    printf("请输入pos位置：");
    scanf("%d", &pos);
    printf("pos位置为：%d, 匹配结果为：%d\n", pos, indexString(s, t, pos));

    return 0;
}
