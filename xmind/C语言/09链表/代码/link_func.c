/*************************************************************************
	> File Name: link_func.c
	> Author:Sjs
	> Mail:303547334@qq.com 
	> Created Time: 2020年07月07日 星期二 13时24分05秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include"link_calloc.h"
#include<string.h>
#if 0
STU* insert_link(STU *head,STU tmp)
{
    //申请堆区动态空间
    STU *pi = (STU *)calloc(1,sizeof(STU));
    if(pi == NULL)
    {
        perror("申请空间失败");
        return head;
    }
    //将tmp值给*pi
    *pi = tmp;
    pi->next =NULL;  //注意
#if  0
    //将pi放入链表
    if(head == NULL)
    {
        head = pi;
    }
    else
    {
        //头部之前插入
        pi -> next = head;
        //head指向新的头
        head = pi;        
    }
#endif
    //尾部插入
    if(head == NULL)
    {
        head = pi;
        
    }
    else
    {
        STU *p = head;
        while(p->next != NULL)
        {
            p = p->next;
        }
        p->next = pi;
    }
    return head;
}
#endif

STU* insert_link(STU *head,STU tmp)
{
   // 1.分配空间
    STU *pi = (STU*)calloc(1,sizeof(STU));
    if(pi == NULL)
    {
        perror("calloc err");
        return head;
    }
    //2.将tmp给新创建的节点
    *pi = tmp;
    pi->next = NULL;

    //3.插入链表
    if(head == NULL)
    {
        head = pi;
    }
    else
    {
        //链表存在,有序插入  
        STU *pb = head;
        STU *pc = NULL;
        while(pb->next != NULL&&pb->num < pi->num)
        {
            pc = pb;
            pb = pb->next;
        }
        if(pb->num > pi->num)
        {
            //头部 中部插入
            if(pb == head)
            {
                //头部插入
                pi->next =head;
                head = pi;
            }
            else
            {
                //中部插入
                pi->next = pb;
                pc->next = pi;
            }
        }
        else
        {
            //尾部插入
            pb->next = pi;
        }
        
    }   
    return head;
}
void print_link(STU *head)
{
    if(head == NULL)
    {
        printf("link no dada\n");
        return;
    }
    else
    {
        STU *pb = head;
        while(pb != NULL)
        {
            printf("num : %d name :%s\n",pb->num,pb->name);
            pb = pb -> next;
        }
    }
    
}

STU* search_link(STU *head, char *name)
{
    if(head == NULL)
    {
        printf("link no data!\n");
        return NULL;
    }
    STU *pi = head;
    while(strcmp(pi->name,name) != 0 && pi->next != NULL)
    {
        pi = pi->next;
    }
    if(strcmp(pi->name,name) == 0)
    {
        return pi;
    }
    else
    {
        return NULL;
    }
    
}

STU* delete_link(STU *head,char *name)
{
    if(head == NULL)
    {
        perror("link no data\n");
        return head;
    }

    //找删除点
    STU *pa = head;
    STU *pb = head;
    while(strcmp(pa->name, name) != 0 && pa->next != NULL)
    {
        pb = pa;
        pa = pa -> next;
    }

    if(strcmp(pa->name,name) == 0)
    {
        //头部
        if(pa == head)
        {
        
            head = pa->next;
            free(pa);
            return head;
        }
        else
        { //中部
            pb->next = pa->next;
            free(pa);
            return head;
        }
    }
    else
    {
        printf("删除节点不存在\n");
    }
   return head; 
}
STU* free_link(STU *head)
{
    if(head == NULL)
    {
        perror("link no exit\n");
        return head;
    }
    STU *pa = head;
    while(pa != NULL)
    {
        head = pa->next;
        free(pa);
        pa = head;
    }
    return head;
}
STU* reverse_link(STU *head)
{
    if(head == NULL)
    {
        perror("link no data");
        return NULL;
    }
    STU *pb = head -> next;
    STU *pr = NULL;
    head->next = NULL;
    while(pb != NULL)
    {
        pr = pb -> next;
        pb->next = head;
        head = pb;
        pb = pr;
    }
    
    return head;
}
void sort_link(STU *head)
{
    if(head == NULL)
    {
        perror("link no data!");
        return;
    }
    else
    {
        STU *pi = head;  //i = 0;
        while(pi->next !=NULL)
        {
            STU *min = pi;
            STU *pj = min->next;
            while(pj != NULL)
            {
                if(min->num < pj->num)
                {
                    min = pj;
                }
                pj = pj -> next;
            }
            if(min != pi)
            {
                STU tmp;
                tmp = *min;
                *min = *pi;
                *pi = tmp;

                tmp.next = pi->next;
                pi->next = min->next;
                min->next = tmp.next;
            }
            pi = pi -> next;
        }
    }
}
