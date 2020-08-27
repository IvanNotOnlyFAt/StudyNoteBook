#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
//extern int errno;
int main()
{
    int fd;
    int fd2;
    fd = open("test.txt",O_RDWR|O_APPEND);
    if (fd == -1)
    {
        perror("fail to open");
        return 1;
    }

    fd2 = open("test2.txt",O_RDWR);
    if (fd2 == -1)
    {
        perror("fail to open2");
      //  return 1;
    }

    write(fd,"helloworld\n",11);
    close(fd);

}
