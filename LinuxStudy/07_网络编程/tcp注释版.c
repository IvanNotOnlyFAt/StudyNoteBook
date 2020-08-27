/* server.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "wrap.h"

#define MAXLINE 80
#define SERV_PORT 8000

int main(int argc, char **argv)
{
	int i, maxi, maxfd, listenfd, connfd, sockfd;	//文件描述符listenfd是监听socket的fd，connfd是连接socket的fd
	
	//操作系统通过宏FD_SETSIZE来声明在一个进程中select所能操作的文件描述符的最大数目。一般默认1024
	int nready, client[FD_SETSIZE]; 
	
	ssize_t n;		//Read返回数
	
	//select()机制中提供一种fd_set的数据结构，它实际上是long类型的数组
	//每一个数组元素都能与一打开的文件句柄（不管是socket句柄，还是其他文件或命名管道或设备句柄）建立联系，
	//当调用select()时，由内核根据IO状态修改fd_set的内容，由此来通知执行了select()的进程哪一socket或文件发生了可读或可写事件。
	fd_set rset, allset;//rset是用户态临时的，allset是要传给内核态的总的
	
	char buf[MAXLINE];
	
	//<netinet/in.h>中有如下两个宏定义：INET_ADDRSTRLEN是使用10进制+句点表示时，所占用的char * 数组的长度
	//#define INET_ADDRSTRLEN 16 /* for IPv4 dotted-decimal */
	char str[INET_ADDRSTRLEN];
	
	socklen_t cliaddr_len;					//cliaddr_len = sizeof(sockaddr_in)，用于Accept
	struct sockaddr_in	cliaddr, servaddr;	//cliaddr用于Accept，servaddr用于Bind

	listenfd = Socket(AF_INET, SOCK_STREAM, 0);  //监听文件，ipv——tcp形式
	/********初始化servaddr**********/
	bzero(&servaddr, sizeof(servaddr));          //服务器地址置零
	servaddr.sin_family      = AF_INET;          //赋值ipv4
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);//网络地址小转大，长整型
	servaddr.sin_port        = htons(SERV_PORT); //端口号小转大，短整型
	/********************************/
	Bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));//绑定监听地址于服务器地址

	Listen(listenfd, 20);//监听文件  运行最大20个客户端处于待连接状态
	
	maxfd = listenfd;		/* initialize 定义最大文件描述符，select的参数n用*/
	maxi = -1;				/* index into client[] array */
	
	/*初始化用户态socket列表*/
	for (i = 0; i < FD_SETSIZE; i++)
	{
		client[i] = -1;	/* -1 indicates available entry *///用户值全置零
	}
		
	FD_ZERO(&allset);//清除全部allset
	FD_SET(listenfd, &allset);//将listenfd置位为allset中的值

	for ( ; ; ) //开始循环
	{
		rset = allset;	/* structure assignment  资源分配 */
		
		//int select(int n, fd_set *readfds, fd_set * writefds, fd_set * exceptfds, struct timeval * timeout);
		//n代表最大的文件描述符加1，因为描述符是从0开始的，因此如果最大的描述符为n的话，那么其实是有n+1个描述符。
		nready = select(maxfd+1, &rset, NULL, NULL, NULL);//准备接收客户端请求；只读方式
		if (nready < 0)
		{
			perr_exit("select error");//打印错误			
		}
		
		/*	FD_ISSET(int fd,fd_set *set)，一般与select()系统调用一起使用。判断描述符fd是否在给定的描述符集fdset中*/
		if (FD_ISSET(listenfd, &rset)) //如果FD值为真；即读取到文件描述符读提醒，可执行accpet
		{ 	
			/* new client connection 创建新链接 */
			cliaddr_len = sizeof(cliaddr);//用户地址长度赋值
			connfd = Accept(listenfd, (struct sockaddr *)&cliaddr, &cliaddr_len);//链接文件

			printf("received from %s at PORT %d\n",
			       inet_ntop(AF_INET, &cliaddr.sin_addr, str, sizeof(str)),
			       ntohs(cliaddr.sin_port));//打印收到的客户端的详细信息：地址，端口号
		/*********************************************************************************************/
		/******   接收到一个client连接之后，注册到自己的用户空间client[FD_SETSIZE]队列中  ************/
		/******                也注册到内核空间&allset用于select监听                     *************/
		/*********************************************************************************************/
			//遍历客户端，先入先写队列，保留自己的连接socketfd
			for (i = 0; i < FD_SETSIZE; i++)
			{
				if (client[i] < 0) 
				{
					client[i] = connfd; /* save descriptor  保存描述符并退出*/
					break;				//只要写成功一个就退出
				}
			}
			
			//如果i==客户端数目达到最大值，打印输出：太多客户端并退出
			if (i == FD_SETSIZE)		
			{
				fputs("too many clients\n", stderr);//
				exit(1);//退出
			}
			
			/*FD_SET（int fd,fd_set*set）； 用来设置描述词组set中相关fd的位*/
			FD_SET(connfd, &allset);	/* 注册到内核空间&allset用于select监听  */
			
			if (connfd > maxfd)
			{
				maxfd = connfd; /* 更新最大最大描述符，并再下一轮select时赋值给select */				
			}

			if (i > maxi)
			{	/*标记用户态client[FD_SETSIZE]中有效的sonnfd最大角标*/
				maxi = i;	/* max index in 用户态client[FD_SETSIZE] array */							
			}

			/*nready是select返回的文件描述符状态已改变的个数*/
			/*如果--nready == 0则表示只有一个监听scoket，如果不为0，则表示还有其他已经连接的client，socket响应*/
			if (--nready == 0)		
			{
				continue;	/* no more readable descriptors */
			}
		}
		
		/*还有其他已经连接的client，socket响应继续处理*/
		for (i = 0; i <= maxi; i++) 	//只访问前面有效元素connfd
		{	/* check all clients for data */
			if ( (sockfd = client[i]) < 0)
			{
				continue;	//这个失败就下一个
			}
			if (FD_ISSET(sockfd, &rset)) //确认sockfd = client[i]在给定的描述符集rset中
			{
				if ( (n = Read(sockfd, buf, MAXLINE)) == 0)//if读取信息为空则清理socket
				{
					/* connection closed by client */
					Close(sockfd);//关闭
					FD_CLR(sockfd, &allset);//	FD_CLR(int fd,fd_set* set)； 用来清除描述词组allset中相关sockfd的位
					client[i] = -1;//空出位置，置为-1
				} else
				{
					int j;
					for (j = 0; j < n; j++)
					{
						buf[j] = toupper(buf[j]);	//将buf中的字符小写转大写						
					}
					Write(sockfd, buf, n);//写读取到的信息
				}
				
				/*挨个执行，直到nready为0，也就从本次select回来的都处理完毕*/
				if (--nready == 0)
				{
					break;	/* no more readable descriptors */										
				}
			}
		}
	}
}
