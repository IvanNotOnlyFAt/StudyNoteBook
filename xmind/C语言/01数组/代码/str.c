/*************************************************************************
	> File Name: str.c
	> Author: 
	> Mail: 
	> Created Time: 2020年06月27日 星期六 21时54分08秒
 ************************************************************************/

#include<stdio.h>
int main(int argc , char *argv[])
{
    char buf[10] = "";
    printf("请输入一个字符串:\n");
    //scanf("%s",buf);
    //注意 遇到空格就会结束
    //但是可以用gets();,gets不会管输入大小,会内存越界.
    // char *fgets(char *s, int size, FILE *stream);
    // s表示存放字符串的空间地址,size能够提取到字符串的最大长度-1 (存放\0)
    // stream stdin 标准输入设备

    fgets(buf,sizeof(buf),stdin);

    printf("buf = %s\n",buf);
    return 0;
}
