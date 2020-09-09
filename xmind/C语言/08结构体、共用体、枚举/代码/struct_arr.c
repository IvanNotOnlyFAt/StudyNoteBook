/*************************************************************************
	> File Name: struct_arr.c
	> Author:Sjs
	> Mail:303547334@qq.com 
	> Created Time: 2020年07月04日 星期六 23时10分03秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
struct stu
{
    int num;
    int age;
    char name[32];
};
int main(int argc,char *argv[])
{
    struct stu test[5];
    int i = 0;
    for(; i < 5; i++)
    {   
        printf("%d %d %s\n",test[i].num,test[i].age,test[i].name);
    }
    //数组结构体清零
    memset(test,0,sizeof(test));
    for(; i < 5; i++)
    {   
        printf("%d %d %s\n",test[i].num,test[i].age,test[i].name);
    }

    struct stu arr[5]={
        {01,23,"韩信"},
        {02,24,"王昭君"},
        {03,25,"猪八戒"},
        {04,2900,"孙悟空"},
        {05,22,"安琪拉"}
    };
    i = 0;
    //根据年龄冒泡排序
    int j = 0;

    for(i = 0; i < 4; i++)
    {
        for(j = 0;j < 5 - i - 1; j++)
        {
            if(arr[j].age < arr[j+1].age)
            {
                struct stu tmp;
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
    i = 0;
    for(; i < 5; i++)
    {   
        printf("%d %d %si\n",arr[i].num,arr[i].age,arr[i].name);
    }
       
    return 0;
}
