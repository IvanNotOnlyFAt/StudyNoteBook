/*************************************************************************
  > File Name: 17_fifo_write.c
  > Author: IvanLxy
  > Mail: yoyiyyo@163.com 
  > Created Time: Tue 04 Aug 2020 06:05:45 PM CST
************************************************************************/
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FIFO_SERVER "./lxyfifo"

main(int argc, char** argv)
{
    char buf_w[100];
    int fd;
    int nwrite;

    fd=open(FIFO_SERVER,O_WRONLY|O_NONBLOCK,0);
    if(fd==-1)
    {
        //ENXIO 6 No such device or address 
        //没有这样的设备或地址
        //ENOENT No such file or directory
        if(errno==ENOENT)
        {
            printf("open error; no reading process");
        }
    }
    
    if(argc==1)
    {
        printf("please send something\n");
        exit(1);
    }
    
    /*****将输入放到缓冲区*******/
    strcpy(buf_w,argv[1]);
    /***************************/

    if(nwrite = write(fd,buf_w,100)==-1)
    {
        //非阻塞的系统调用，由于资源限制/不满足条件，
        //导致返回值为EAGAIN
        if(errno == EAGAIN)
            printf("The FIFO has not been read yet ,please try later \n");

    }else
    {
        printf("write %s to the FIFO\n",buf_w);
    }
}

