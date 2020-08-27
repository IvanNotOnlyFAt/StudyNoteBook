#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#include <fcntl.h>


#define SEM_NAME "sem_name"
int main()
{
    sem_t *pSem;
	//sem_t *sem_open(const char *name,int oflag,mode_t mode,unsigned int value);value是初始值
    pSem = sem_open(SEM_NAME, O_CREAT, 0666, 5);

    int val;
	//int sem_getvalue(sem_t *sem,int *valp); 
    sem_getvalue(pSem, &val);
    printf("parent:semaphore value:%d\n", val);

    if(fork() == 0)
    {  
		/*****************************************************/
        sem_getvalue(pSem, &val); 
        printf("wait before child1:semaphore value:%d\n", val);
		/*lllllllllllllllllllllllllllllllllllllllllllllllllll*/
		
        sem_wait(pSem);		//5-1 = 4 
		
		/*****************************************************/
        sem_getvalue(pSem, &val); 
        printf("child2:semaphore value:%d\n", val);		//4
		/*lllllllllllllllllllllllllllllllllllllllllllllllllll*/

        sleep(1);
        sem_wait(pSem);		//3-1 = 2	
		
		/*****************************************************/
        sem_getvalue(pSem, &val); 
        printf("child3:semaphore value:%d\n", val);		//2
		/*lllllllllllllllllllllllllllllllllllllllllllllllllll*/

        exit(0);
    }else
    {
        sleep(1);
		/*****************************************************/
        sem_getvalue(pSem, &val);
        printf("wait before:parent1:semaphore value:%d\n", val);	//4
		/*lllllllllllllllllllllllllllllllllllllllllllllllllll*/
        
		sem_wait(pSem);		//4-1=3
		/*****************************************************/
        sem_getvalue(pSem, &val);
        printf("parent2:semaphore value:%d\n", val);		//3
		/*lllllllllllllllllllllllllllllllllllllllllllllllllll*/
		
        sleep(1);
        sem_wait(pSem);		//2-1=1
		
		/*****************************************************/
        sem_getvalue(pSem, &val);
        printf("parent3:semaphore value:%d\n", val);	//1
		/*lllllllllllllllllllllllllllllllllllllllllllllllllll*/

        sem_unlink(SEM_NAME);
    }
}
