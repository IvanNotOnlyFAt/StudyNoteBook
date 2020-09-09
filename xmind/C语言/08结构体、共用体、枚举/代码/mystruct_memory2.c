/*************************************************************************
	> File Name: mystruct_memory2.c
	> Author:Sjs
	> Mail:303547334@qq.com 
	> Created Time: 2020年07月06日 星期一 10时06分34秒
 ************************************************************************/

#include<stdio.h>
typedef struct data
{
    char x;
    short y;

}DATA;

typedef struct data2
{
    int a;
    short b;
    DATA data;
    short f;
}DATA2;
int main(int argc,char *argv[])
{
    printf("DATA2 (SIZE) = %d\n",sizeof(DATA2));
    DATA2 data = {1,2,{3,4},5};
    printf("%d %d %d %d %d",data.a,data.b,data.data.x,data.data.y,data.f);
    
    return 0;
}
