/*************************************************************************
	> File Name: link_calloc.c
	> Author:Sjs
	> Mail:303547334@qq.com 
	> Created Time: 2020年07月07日 星期二 11时25分26秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include"link_calloc.h"
void stu_help(void);
int main(int argc,char *argv[])
{
    STU *head = NULL;
    stu_help();
    while(1)
    {
        char cmd[32] = "";
        printf("请输入操作指令:\n");
        scanf("%s",cmd);
        if(strcmp(cmd,"help") == 0)
        {
            printf("######help######\n");
        }
        else if(strcmp(cmd,"insert") == 0)
        {
            STU tmp; 
            printf("请输入要插入的数据num 和 name:\n");
            scanf("%d %s",&tmp.num,tmp.name);
            head = insert_link(head,tmp);
        }
        else if(strcmp(cmd,"search") == 0)
        { 
            char name[64] = "";
            printf("请输入要查询的用户姓名:\n");
            STU *ret = NULL;
            scanf("%s",name);
            ret = search_link(head,name);
            if(ret != NULL)
            {
                printf("num = %d,name = %s\n",ret->num,ret->name);
            }
            else
            {
                printf("未找到!\n");
            }
        }
        else if(strcmp(cmd,"print") == 0)
        {
            print_link(head);
        }
        else if(strcmp(cmd,"delete") == 0)
        {
            char name[64] = "";
            printf("请输入要删除的名字:\n");
            scanf("%s",name);
            head = delete_link(head,name);
        }
        else if(strcmp(cmd,"free") == 0)
        {
            head = free_link(head);
            if(head  == NULL)
            {
                printf("free Success!\n");
            }
        }else if(strcmp(cmd,"quit") == 0)
        {
            printf("########quit#########\n");
            break;
        }
        else if(strcmp(cmd,"reverse") == 0)
        {
            head = reverse_link(head);

        }
        else if(strcmp(cmd,"sort") == 0)
        {
            sort_link(head);
        }
        else
        {
            printf("指令错误重新输入!\n");
        }
    }
}
void stu_help(void)
{
    printf("##########################\n");
    printf("#####help:打印帮助信息####\n");
    printf("####insert:插入节点信息####\n");
    printf("####print:打印节点信息#####\n");
    printf("#####search:查询节点信息####\n");
    printf("#####delete:删除节点信息####\n");
    printf("######free:释放链表#####\n");
    printf("######reverse:倒置链表####\n");
    printf("######sort:链表排序######\n");
    printf("#######quit:退出#########\n");
    printf("#############################\n");
    return;
}
