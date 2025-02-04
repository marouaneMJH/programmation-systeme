#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h> 

#include <pthread.h>

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/msg.h>
#include <sys/ipc.h>

#define N 100000

long int global = 0;

pthread_mutex_t mutex;


void *add()
{
    for(int i=0; i < N ;i++)
    {
        
        // pthread_mutex_lock(&mutex);
        global++;
        // pthread_mutex_unlock(&mutex);
    }
}

int main()
{
    pthread_t th1,th2;

    pthread_mutex_init(&mutex,NULL);
    pthread_create(&th1,NULL,add,NULL);
    pthread_create(&th2,NULL,add,NULL);


    pthread_join(th1,NULL);
    pthread_join(th2,NULL);

    pthread_mutex_destroy(&mutex);
    printf("gloabl = %d",global);
    return 0;
}