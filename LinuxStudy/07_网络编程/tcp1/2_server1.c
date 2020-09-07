/*************************************************************************
  > File Name: 2_server1.c
  > Author: IvanLxy
  > Mail: yoyiyyo@163.com 
  > Created Time: Fri 14 Aug 2020 05:18:26 PM CST
************************************************************************/
/* server.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>     //
#include <netinet/in.h>     //#define INET_ADDRSTRLEN 16{for IPv4 dotted-decimal}
#include <arpa/inet.h>      //

#define MAXLINE 80
#define SERV_PORT 8000

int main(void)
{
	struct sockaddr_in servaddr, cliaddr;   //两个结构体 监听/连接
	socklen_t cliaddr_len;      //bind第三个addrlen指定结构体的长度
	int listenfd, connfd;       //文件描述符，监听和连接
	char buf[MAXLINE];
	char str[INET_ADDRSTRLEN];  //#define INET_ADDRSTRLEN 16
	int i, n;
    
	listenfd = socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(SERV_PORT);
    
    //int bind(int sockfd, const struct sockaddr *myaddr, socklen_t addrlen);
    bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
    //int listen(int sockfd, int backlog);
    //最多允许有backlog个客户端处于连接待状态
    listen(listenfd, 20);
    
    printf("Accepting connections ...\n");
    while(1)
    {
        cliaddr_len = sizeof(cliaddr);
        // int accept(int sockfd, struct sockaddr *cliaddr, socklen_t *addrlen);
        // cliaddr是一个传出参数，accept()返回时传出客户端的地址和端口号。
        connfd = accept(listenfd, (struct sockaddr*)&cliaddr, &cliaddr_len);
        n = read(connfd, buf, MAXLINE);
        printf("received from %s at PORT %d\n",
            inet_ntop(AF_INET, &cliaddr.sin_addr, str, sizeof(str)),
            ntohs(cliaddr.sin_port));
        
        for(i = 0; i < n; i++)
        {
            //int tolower(int c);将字符转小写
            //int toupper(int c);将字符转大写
            buf[i] = toupper(buf[i]);
        }
        write(connfd, buf, n);
        close(connfd);
    }
}
