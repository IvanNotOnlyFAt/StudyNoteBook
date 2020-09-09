#include <stdio.h>
#include <stdlib.h>

//串的定长顺序存储结构
#define MAX_STRLEN 256

typedef struct StringType{
	char str[MAX_STRLEN];
	int length;
}StringType;

//求字符串长度
int StringLen(StringType s)
{
	int i = 0;
	while (s.str[i] != '\0'){
		i++;
	} 
	return i;
}

//字符串联接
int StrConcat(StringType *s, StringType *t)
{
	int i;
	if (s->length + t->length > MAX_STRLEN){
		printf("error: long string\n");
		return -1;
	}
	for (i = 0; i < t->length; i++){
		s->str[s->length + i] = t->str[i];
	}
	s->str[s->length + i] = '\0';
	s->length = s->length + t->length;
	return 1;
}

//求子串操作,从pos位置开始返回一个长为len的子串
int SubString(StringType s, int pos, int len, StringType *sub)
{
	int i, j;
	if (pos < 1 || pos > s.length || len < 0 || len > (s.length - pos + 1)){
		printf("参数是非法的\n");
		return -1;
	}

	sub->length = len;
	for (i = 0, j = pos - 1; i < len; i++, j++){
		sub->str[i] = s.str[j];
	}
	sub->str[i] = '\0';
	return 1;
}

int main()
{
	StringType s1 = { "hello", 0 };
	StringType s2 = { "world", 0 };
	StringType s3;
	s1.length = StringLen(s1);
	s2.length = StringLen(s2);
	printf("s1 len = %d\n", s1.length);
	printf("s2 len = %d\n", s2.length);
	StrConcat(&s1, &s2);
	printf("s1: %s\n", s1.str);
	
	if (SubString(s1, 2, 5, &s3) == 1){
		printf("s3: %s\n", s3.str);
	}
	return 0;
}

