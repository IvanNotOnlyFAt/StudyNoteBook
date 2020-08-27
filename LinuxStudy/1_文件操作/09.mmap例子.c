#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>

int main(void)
{
	char *p;
	int fd = open("hello", O_RDWR);
	int i = 0;
	if (fd < 0)
	{
		perror("open hello");
		exit(1);
	}
	
	p = mmap(NULL, 6, PROT_WRITE, MAP_SHARED, fd, 0);
	//  NULL任意位置；6个字节；PROT_WRITE只写；MAP_SHARED映射共享，fd，偏移量0
	if (p == MAP_FAILED) 
	{
		perror("mmap");
		exit(1);
	}
	close(fd);
	//映射之后关闭仍然可以访问
	for(i = 0; i < 6; i++)
	{
	     p[i] = 'a' + i;
	}
	     
	munmap(p, 6);
	//munmap()函数：解除内存映射
	return 0;
}