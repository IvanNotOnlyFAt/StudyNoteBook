/*************************************************************************
	> File Name: atoA.c
	> Author: 
	> Mail: 
	> Created Time: 2020年06月27日 星期六 22时15分09秒
 ************************************************************************/

#include<stdio.h>
int main(int argc, char *argv[])
{
    printf("请输入字符串:\n");
    char buf[128] = "";

    fgets(buf, sizeof(buf),stdin);

    //for()进行大小写转换
    for(int i = 0; i < sizeof(buf); i++)
    {
        if(buf[i] >= 97 && buf[i] <= 122)
        {
            buf[i] = buf[i] - 32;
        }
        
    }
    
    printf("%s\n",buf);
    return 0;
}
