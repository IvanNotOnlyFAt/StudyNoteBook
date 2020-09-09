/*************************************************************************
	> File Name: kmp.c
	> Author: Nfh
	> Mail: 1024222310@qq.com 
	> Created Time: 2020年08月07日 星期五 09时33分48秒
 ************************************************************************/

#include <stdio.h>
#define MAX 256

typedef struct
{
	char str[MAX];
	int length;
}SString;

int initString(SString *st, char *str)
{
	int i = 0;
	while(str[i] != '\0')
	{
		st->str[i] = str[i];
		i++;
	}
	st->length = i;
}

void getNext(SString t, int next[])
{
	int k = -1;
	int j = 0;
	next[0] = -1;
	next[1] = 0;

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
	return ;
}

int indexString(SString s, SString t)
{
	int i = 0;
	int j = 0;
	int next[MAX] = {0};
	getNext(t, next);

	while(i < s.length && j < t.length)
	{
		if(j == -1 || s.str[i] == t.str[j])
		{
			++i;
			++j;
		}else
		{
			j = next[j];
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
	initString(&s, "ABACABADC");
	initString(&t, "BAD");
	int ret = indexString(s, t);
	printf("s = %s\n", s.str);
	printf("t = %s\n", t.str);
	if(ret > 0)
		printf("匹配位置为：%d\n", ret);
	
    return 0;
}
