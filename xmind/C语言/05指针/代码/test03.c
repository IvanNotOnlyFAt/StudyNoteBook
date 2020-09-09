/*************************************************************************
	> File Name: test03.c
    > Desrc:指针数组存储字符串
	> Author:Sjs
	> Mail:303547334@qq.com 
	> Created Time: 2020年07月01日 星期三 23时40分58秒
 ************************************************************************/

#include<stdio.h>
int main(int argc , char *argv[])
{
    //存储的为字符串的首地址,通过对arr取大小证明
    char *arr[3] = {"hehehe","hahaha","dadada"};

    printf("%d\n",sizeof(arr));

    //根据*(arr+0)
    printf("%s\n",arr[0]);

    //取某个数值的某个值*(*(arr+1) +1)
    printf("%c\n",*(arr[1]+1));
    return 0;

}
