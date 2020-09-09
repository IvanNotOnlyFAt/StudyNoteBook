/*************************************************************************
	> File Name: test.c
	> Author: 
	> Mail: 
	> Created Time: 2020年06月29日 星期一 21时20分49秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
int main(int argc, char *argvp[])
{
    char buf[128] = "";
    int i = 0;
    printf("请输入字符串:");

    //fgets 会得到换行符
    fgets(buf,sizeof(buf),stdin);

    //strlen 返回字符串实际长度,不包括\0 但是有\n
    buf[strlen(buf)-1] = 0;
#if 0
    while(buf[i] != 0)
    {
        if(buf[i] >= 97 && buf[i] <= 122)
        {
            buf[i] = buf[i] - 32;
        }
        i++;
    }
#else

    printf("代码未执行!");
#endif
    printf("buf= %s\n",buf);
    return 0;
}
