/*************************************************************************
  > File Name: 25_shmwrite.c
  > Author: IvanLxy
  > Mail: yoyiyyo@163.com 
  > Created Time: Fri 07 Aug 2020 04:51:45 PM CST
************************************************************************/
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <string.h>
#include <stdio.h>
//#include <sys/stat.h> //??

/*VERIFYERR(a, b)是含参宏，当a成立是，它打印失败信息，否则打印成功信息。*/
#define VERIFYERR(a, b, c)  \
	if (a) \
	{\
		fprintf(stderr, "%s%d failed.\n", b, c);  \
		return;\
	}\
	else \
		fprintf(stderr, "%s%d success.\n", b, c);
int main()
{
    int shmid;
    char *pmat = NULL;  //共享内存的首地址
    char buf[1024];
    int no;

    /*打开共享内存*/
    // int shmget(key_t key, size_t size, int shmflg);
    if((shmid = shmget(0x1234, 10*1024, 0666|IPC_CREAT)) == -1)
    {
        fprintf(stderr, "%s sfailed.", "Open(Create) Shm");
        return 1;
    }else
    {
        fprintf(stderr, "%s success", "Link Shm");
    }


    /* 映射共享内存，地址存储与pmat处 */
    //void *shmat ( int shmid, char *shmaddr, int shmflg);
    //成功，则返回共享内存段连接到进程中的地址
	if ((pmat = (char *)shmat(shmid, 0, 0)) == NULL)
	{
        fprintf(stderr,"%s failed.","Link Shm");
				return 1;
	}else
	{
        fprintf(stderr,"%s success.","Link Shm");
	}

    /*输入更新的内存块号*/
    //
    printf("Please Input No.(0~9):");
    scanf("%d", &no);
    VERIFYERR(no < 0 || no >9, "Input No.",no);

    /*输入更新的数据*/
    printf("Please Input Data:");
    memset(buf, 0, sizeof(buf));
    scanf("%s", buf);

    /*更新共享内存数据*/
    // void *memcpy(void *dest, const void *src, size_t n);
    memcpy(pmat+no*1024, buf, 1024);
    /*释放共享内存映射*/
    //int shmdt ( char *shmaddr );
    shmdt(pmat);

}




