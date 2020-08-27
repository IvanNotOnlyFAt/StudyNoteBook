#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#include <fcntl.h>

sem_t mSem;
/**********此程序没有将无名信号量放入共享内存******************/
int main()
{
    int val;
	//int sem_init(sem_t *sem, int pshared, unsigned int value);
	//pshared: 非零值则表示信号量将在进程间共享。
	//在进程间共享，无名信号量必须位于共享内存区域内。
    sem_init(&mSem, 1, 3);		//初始值是3

    sem_getvalue(&mSem, &val);
    printf("parent:semaphore value:%d\n", val);
	printf("*************************\n");
    if(fork() == 0)
    {   printf("-------------child------------\n");
        sem_getvalue(&mSem, &val);
        printf("wait before child_1:semaphore value:child %d\n", val);		//3.：***child3
		
        sem_wait(&mSem);		//child3-1=2

        sem_getvalue(&mSem, &val);
        printf("child_2:semaphore value:child %d\n", val);		//4.：***child2
        sleep(1);
		
        sem_wait(&mSem);		//7:child2-1=1
		
        sem_getvalue(&mSem, &val);
        printf("child_3:semaphore value:child %d\n", val);		//8：***child1
        printf("child finish\n");							//9：child finish
        exit(0);
    }else
    {
		printf("-------------parent------------\n");		//1.先进入parent
        sleep(1);											//2.随后跳到child
		
        sem_getvalue(&mSem, &val);
        printf("wait before:parent_1:semaphore value:parent %d\n", val);	//5：***parent3
        
		sem_wait(&mSem);		//parent3-1=2
        
		sem_getvalue(&mSem, &val);
        printf("parent_2:semaphore value:parent %d\n", val);				//6：***parent2
		sleep(1);
		
		sem_wait(&mSem);		//10：parent2-1=1
        
		sem_getvalue(&mSem, &val);
        printf("parent_3:semaphore value:parent %d\n", val);				//11：**parent1
    }
}
