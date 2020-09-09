/*************************************************************************
    > File Name: KMP_algorithm.c
    > Author: Nfh
    > Mail: 1024222310@qq.com 
    > Created Time: 2020年08月05日 星期三 15时26分32秒
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

// 获取前缀表的函数，通过前缀表找到当indexString()j位置不匹配时
// 模式串应该跳到哪里
void getNext(SString t, int next[])
{
    int k = -1;     // 表示前缀
    int j = 0;      // 表示后缀

    next[0] = -1;   
    while(j < t.length)
    {
        if(k == -1 || t.str[k] == t.str[j])
        {
            ++k;
            ++j;
            if(t.str[k] == t.str[j])
            {
                next[j] = next[k];
            }else
            {
                next[j] = k;
            }
        }else
        {
            k = next[k];
        }
    }
}

int indexString(SString s, SString t)
{
    int i = 0;
    int j = 0;
    char *sp = s.str;
    char *tp = t.str;

    int n[MAX] = {0};
    getNext(t, n);

    while(i < s.length && j < t.length)
    {
        if(j == -1 || sp[i] == tp[j])
        {
            i++;
            j++;
        }else
        {
            j = n[j];
        }
    }
    if(j == t.length)
    {
        printf("匹配成功！\n");
        return i - j;
    }else
    {
        printf("匹配失败！\n");
        return 0;
    }
}

int main()
{
    SString s;
    SString t;
    initString(&s, "ABACABABC");
    initString(&t, "ABAB");
    printf("s: %s\n", s.str);
    printf("t: %s\n", t.str);

    int ret = indexString(s, t);
    printf("匹配位置：%d\n", ret);
    return 0;
}
