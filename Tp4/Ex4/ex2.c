#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h> 

#include <pthread.h>

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/msg.h>
#include <sys/ipc.h>

#define FILE_TXT "file.txt"
#define MODE "w"

void* write_1(void* file_txt)
{
    for(int i = 0;i < 100000 ;i++)
    {
        fprintf((FILE*)file_txt,"\t%d",i);
        fflush((FILE*)file_txt);

    }
}
void* write_2(void* file_txt)
{
    for(long int i = 1000000 ;i < 1100000;i++)
    {
        fprintf((FILE*)file_txt,"\t%ld",i);
        fflush((FILE*)file_txt);
    }
}

int main()
{
    pthread_t th1,th2;

    FILE* file_txt = fopen(FILE_TXT,MODE);

    pthread_create(&th1,NULL,write_1,file_txt);
    pthread_create(&th1,NULL,write_2,file_txt);


    pthread_join(th1,NULL);
    pthread_join(th2,NULL);





    fclose(file_txt);
    return 0;
}