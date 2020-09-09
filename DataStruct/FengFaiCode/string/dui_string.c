/*************************************************************************
    > File Name: dui_string.c
    > Author: Nfh
    > Mail: 1024222310@qq.com 
    > Created Time: 2020年08月04日 星期二 15时44分08秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct
{
    char *ch;
    int length;
}HString;

// 字符串初始化
int StrAssign(HString *t, char *str)
{
    int len = 0, i = 0;
    if(t->ch != NULL)
    {
        free(t->ch);
        t->ch = NULL;
        t->length = 0;
    }
    // 求str的长度
    while(str[len] != '\0')
        len++;

    t->ch = (char *)malloc(sizeof(char) * len);
    assert(t->ch != NULL);
    t->length = len;

    while(str[i] != '\0')
    {
        t->ch[i] = str[i];
        i++;
    }
    return 1;
}

// 求字符串长度
int StrLength(HString s)
{
    return s.length;
}

// 字符串比较
int StrCompare(HString s, HString t)
{
   int i = 0;
   for(i = 0; i < s.length && i < t.length; ++i)
   {
       if(s.ch[i] != t.ch[i])
           return s.ch[i] - t.ch[i];
   }
   return s.length - t.length;
}

// 清空字符串
int StrClear(HString *str)
{
    if(str->ch != NULL)
    {
        free(str->ch);
        str->ch = NULL;
        str->length = 0;
    }
    return 1;
}

// 连接字符串并放入t
int StrConcat(HString *t, HString s1, HString s2)
{
    int i = 0, j = 0;
    if(t->ch != NULL)
    {
        free(t->ch);
        t->ch = NULL;
    }
    t->ch = (char *)malloc(s1.length + s2.length);
    assert(t->ch);

    while(s1.ch[i] != '\0')
    {
        t->ch[i] = s1.ch[i];
        i++;
    }
    while(s2.ch[j] != '\0')
    {
        t->ch[i] = s2.ch[j];
        i++;
        j++;
    }
    return 1;
}

// 返回str中从pos位置开始长度为len的字符串
int StrSubString(HString *t, HString str, int pos, int len)
{
    if(pos < 1 || pos > str.length || len < 0 || len > str.length - pos + 1)
    {
        printf("pos or len is errno\n");
        return -1;
    }
    if(t->ch != NULL)
    {
        free(t->ch);
        t->ch = NULL;
    }
    if(len == 0)
    {
        t->ch = NULL;
        t->length = 0;
    }else
    {
        t->ch = (char *)malloc(sizeof(char) * len);
        assert(t->ch);
        t->length = len;
        int i = 0;
        while(i < len)
        {
            t->ch[i] = str.ch[pos + i];
            i++;
        }
    }
    return 1;
}

int StrCopy(HString *t, HString s)
{
    int i = 0;
    if(t->ch != NULL)
    {
        free(t->ch);
        t->length = 0;
    }
    t->ch = (char *)malloc(s.length);
    assert(t->ch != NULL);
    
    while(s.ch[i] != '\0')
    {
        t->ch[i] = s.ch[i];
        i++;
    }
    t->length = s.length;
    return 1;
}


int main()
{

    return 0;
}
