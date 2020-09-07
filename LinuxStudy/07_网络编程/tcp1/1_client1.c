/*************************************************************************
  > File Name: 1_client1.c
  > Author: IvanLxy
  > Mail: yoyiyyo@163.com 
  > Created Time: Fri 14 Aug 2020 03:27:39 PM CST
************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/socket.h>
#include <netinet/in.h>

#define MAXLINE 80
#define SERV_PORT 8000  //端口号

int main(int argc, char *argv[])
{
    struct sockaddr_in servaddr;
    char buf[MAXLINE];
    int sockfd, n;
    char *str;

    if(argc != 2)
    {
        fputs("usage:./client message\n", stderr);
        exit(1);
    }
    str = argv[1];

    //int socket(int domain, int type, int protocol);返回个文件描述符
    //IPv4， domain参数指定为AF_INET
    //TCP协议， type参数指定为SOCK_STREAM
    //protocol参数，指定为0即可
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    /*****struct sockaddr_in的初始化*****/
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
        // #include <arpa/inet.h>
        // int inet_pton(int af, const char *src, void *dst);
        //将字符串src转换为af地址族中的网络地址结构，然后将网络地址结构复制到dst。代替servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);//本地回环
    servaddr.sin_port = htons(SERV_PORT);
    /************************************/
    
    //int connect(int sockfd, const struct sockaddr *servaddr, socklen_t addrlen);对应server中的blind
    connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
    
    write(sockfd, str, MAXLINE);
    
    n = read(sockfd, buf, MAXLINE);
    printf("Response from server: %d\n", n);

    write(STDOUT_FILENO, buf, n);
    printf("\n");
    printf("------------\n");
    close(sockfd);
    return 0;
}
