/*************************************************************************
	> File Name: link.c
	> Author:Sjs
	> Mail:303547334@qq.com 
	> Created Time: 2020年07月07日 星期二 10时38分44秒
 ************************************************************************/

#include<stdio.h>
typedef struct stu
{
    //数据域
    int num;
    char name[32];
    //指针域  STU尚未定义 
    struct stu *next;
}STU;

int main(int argc,char *argv[])
{
    STU data1 = {1001,"sjs"};
    STU data2 = {1002,"zj"};
    STU data3 = {1003,"LY"};
    STU data4 = {1004,"PS"};
    STU *head = NULL;
    STU *pb = NULL;
    head = &data1;
    data1.next = &data2;
    data2.next = &data3;
    data3.next = &data4;
    data4.next = NULL;
    pb = head;
    
    while(pb != NULL)
    {
        printf("num = %d name = %s\n",pb->num,pb->name);
        pb = pb->next;
    }
    return 0;
}
