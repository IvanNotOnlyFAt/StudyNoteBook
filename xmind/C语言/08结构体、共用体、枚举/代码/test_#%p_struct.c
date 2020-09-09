/*************************************************************************
	> File Name: test_*p_struct.c
	> Author:Sjs
	> Mail:303547334@qq.com 
	> Created Time: 2020年07月05日 星期日 10时00分41秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//定义结构体别名
typedef struct stu
{
    int num;
    char name[32];
    int age;

}STU;
STU* calloc_STU(int n)
{
    return (STU*)calloc(n,sizeof(STU));
}
void mystruct_input(STU *p,int n)
{
    int i = 0;
    for(i = 0; i < n; i++)
    {
        printf("请输入第%d个学生的 num, name , age:\n",i+1);
        scanf("%d %s %d",&p[i].num,p[i].name,&p[i].age);
    }
}
void mystruct_output(STU *p,int n)
{
    int i = 0;
    for(; i < n; i++)
    {
        printf("num : %d  name : %s  age :%d\n", p[i].num,p[i].name,
               p[i].age);
    }
}
int main(int argc,char *argv[])
{
   /* STU lucy = {12,"lucy",21};
    printf("num = %d name = %s age = %d\n",lucy.num,lucy.name,lucy.age);
    STU *p = &lucy;
    
    printf("num = %d name = %s age = %d\n",(*p).num,(*p).name,(*p).age);
    
    printf("num = %d name = %s age = %d\n",p->num,p->name,p->age);
    */
    STU *p = NULL;
    int n = 0;
    printf("请输入需要登记信息的学生人数:\n");

    scanf("%d",&n);

    p = calloc_STU(n);
    mystruct_input(p,n);
    mystruct_output(p,n);
    return 0;
}
