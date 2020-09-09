/*************************************************************************
	> File Name: link_calloc.h
	> Author:Sjs
	> Mail:303547334@qq.com 
	> Created Time: 2020年07月07日 星期二 11时25分06秒
 ************************************************************************/

#ifndef _LINK_CALLOC_H
#define _LINK_CALLOC_H

//链表节点
typedef struct stu
{
    //数据域
    int num;
    char name[32];

    //指针域
    struct stu *next;
}STU;
extern STU* insert_link(STU *head,STU tmp);
extern void print_link(STU *head);
extern STU* search_link(STU *head,char *name);
extern STU* delete_link(STU *head,char *name);
extern STU* free_link(STU *head);
extern STU* reverse_link(STU *head);
extern void sort_link(STU *head);
#endif
