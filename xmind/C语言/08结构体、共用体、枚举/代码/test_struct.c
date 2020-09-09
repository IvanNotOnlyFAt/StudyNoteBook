/*************************************************************************
	> File Name: test_struct.c
	> Author:Sjs
	> Mail:303547334@qq.com 
	> Created Time: 2020年07月04日 星期六 18时03分12秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
struct stu
{
    int no;
    char name[32];
    int age;
};
int main(int argc,char *argv[])
{
    //定义 不分配空间,只是告诉了他需要多少空间
    printf("sizeof(struct stu)%d\n",sizeof(struct stu));
    //定义结构体变量
    struct stu BOb;

    //分配空间可能有内容,需要清空.

    memset(&BOb,0,sizeof(BOb));

    printf("no = %d\n",BOb.no);
    printf("name = %s\n",BOb.name);
    printf("age = %d\n",BOb.age);


    //一定要遵守类型 ,你可以试试不遵守
    BOb.no = 1001;
    //字符串不可以直接赋值
    //BOb.name = "Lucy";
    strcpy(BOb.name,"lucy");

    BOb.age = 23;

    printf("no = %d\n",BOb.no);
    printf("name = %s\n",BOb.name);
    printf("age = %d\n",BOb.age);

    //结构体变量获取键盘输入
    printf("请输入 no, name,age:");

    scanf("%d %s %d",&BOb.no,BOb.name,&BOb.age);
    printf("no = %d\n",BOb.no);
    printf("name = %s\n",BOb.name);
    printf("age = %d\n",BOb.age);
    return 0;
}
