#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h> 

#include <pthread.h>

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/msg.h>
#include <sys/ipc.h>




void* print_lower_case()
{
    for(char c='a';c <= 'z';c++)    
    {
        usleep(10000);
        printf("%c\t",c);
        fflush(stdout);
    }
}
void* print_upper_case()
{
    for(char c='A';c <= 'Z';c++)    
    {
        usleep(10000);
        printf("%c\t",c);
        fflush(stdout);
    }
}




int main()
{
    pthread_t th1,th2;

    pthread_create(&th1,NULL,print_lower_case,NULL);
    pthread_create(&th2,NULL,print_upper_case,NULL);
    pthread_join(th1,NULL);
    pthread_join(th2,NULL);

    printf("\n");
    return 0;
}