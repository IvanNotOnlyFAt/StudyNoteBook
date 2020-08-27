/*************************************************************************
  > File Name: 23_msgsend.c
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
    /*打开或创建消队列*/
    if((msid = msgget(0x1234, 0666|IPC_CREAT)) < 0)
    {
        //stderr是标准错误输出流
        // int fprintf(FILE *stream, const char *format, ...);
        // %x以16进制输出无符号整数
        fprintf(stderr,"open msg %X failed.\n",0x1234);
        return -1;
    }
    // int strncmp(const char *s1, const char *s2, size_t n);
    // 如果返回值 < 0，则表示 str1 小于 str2。如果返回值 > 0，则表示 str2 小于 str1。
    // 如果返回值 = 0，则表示 str1 等于 str2。
    while(strncmp(buf.ctext, "exit", 4))
    {
        //void *memset(void *s, int c, size_t n);
        memset(&buf, 0, sizeof(buf));
        //stdout是行缓冲的，他的输出会放在一个buffer里面，只有到换行的时候，才会输出到屏幕。而stderr是无缓冲的，会直接输出。
        fprintf(stderr, "Please input:");
        /*从键盘输入消息内容*/
        fgets(buf.ctext, sizeof(buf.ctext), stdin);
        /*设置消息类型*/
        buf.mtype = getpid();       //
        /*发消息*/
        while((msgsnd(msid, &buf, strlen(buf.ctext), 0)) < 0)
        {
            //被信号打断，重新发送
            if(errno == EINTR)
                continue;
            return;
        }
    }
}


