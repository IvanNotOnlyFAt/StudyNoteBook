#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>


int main(int argc,char *argv[])
{
    int fd_src;
    int fd_dest;
    int ret;
    char buf[20] = {0};
    if (argc < 3)
    {
        printf("usage:./cp src dest\n");
        exit(1);
    }

    fd_src = open(argv[1],O_RDONLY);
    if (fd_src == -1)
    {
         perror("open");
         exit(1);
    }

    fd_dest = open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,0644);
    if (fd_dest == -1)
    {
         perror("open");
         exit(1);
    }

    while ( (ret = read(fd_src,buf,sizeof(buf))) > 0 )
    {
        write(fd_dest,buf,ret);
    }
    
    close(fd_dest);
    close(fd_src);
}
