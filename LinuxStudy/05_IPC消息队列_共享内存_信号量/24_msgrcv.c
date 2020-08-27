/*************************************************************************
  > File Name: 24_msgrcv.c
  > Author: IvanLxy
  > Mail: yoyiyyo@163.com 
  > Created Time: Fri 07 Aug 2020 03:47:33 PM CST
************************************************************************/
#include <sys/msg.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <string.h>
#include <sys/errno.h>

extern int errno;

/*定义消息结构体*/
struct mymsgbuf
{
    long mtype;         //消息类型
    char ctext[100];    //消息数据
};

int main()
{
    struct mymsgbuf buf;    //申请消息缓冲
    int msid;
    int ret;                //接受消息的长度1
    /*打开或创建消队列*/
    if((msid = msgget(0x1234, 0666|IPC_CREAT)) < 0)
    {
        fprintf(stderr,"open msg %X failed.\n",0x1234);
        return ;
    }
    while(strncmp(buf.ctext, "exit", 4))
    {
        //void *memset(void *s, int c, size_t n);
        memset(&buf, 0, sizeof(buf));
        /*收消息*/
        //int msgrcv (int msqid,struct  msgbuf * msgp, size_t msgsz, long msgtyp, int msgflg)
        //msgytype是0接收队列里的第一个消息
        while((ret = msgrcv(msid, &buf, sizeof(buf.ctext), 0, 0)) < 0)
        {
            //被信号打断，重新接收
            if(errno == EINTR)
                continue;
            return;
        }
        fprintf(stderr, "Msg : Type=%ld, Len=%d, Texy:%s ", buf.mtype, ret, buf.ctext);
    }
}


