#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>

int main(void)
{
	struct winsize size;
	
	if (isatty(STDOUT_FILENO) == 0)  //表示is a  tty ?  是-1  不是-0
		exit(1);
		
	if(ioctl(STDOUT_FILENO, TIOCGWINSZ, &size)<0)    //控制窗口的size
	{
		perror("ioctl TIOCGWINSZ error");
		exit(1);
	}
	
	printf("%d rows, %d columns\n", size.ws_row, size.ws_col);   //打印窗口是size
	return 0;
}