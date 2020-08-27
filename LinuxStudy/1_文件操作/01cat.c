#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>


int main(int argc,char *argv[])
{
    int fd;
    int ret;
    char buf[20] = {0};
    if (argc < 2)
    {
        fd = 0;
    }else
    {
        fd = open(argv[1],O_RDONLY);
        if (fd == -1)
        {
            perror("open");
            exit(1);
        }
    }

    while ( (ret = read(fd,buf,sizeof(buf))) > 0 )
    {
        write(1,buf,ret);
    }
    
    close(fd);
}
