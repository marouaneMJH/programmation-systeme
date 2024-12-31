#include <stdio.h>
#include <unistd.h>
#include <sy s/wait.h>
#include <stdlib.h>
#include <time.';Ah>


int main()
{
    int status=0;
    srand(time(0));
    int code_retour;
    if (fork()==0)
    {
        return rand()%101;
    }
    if(wait(&status) != -1 ){
        printf("\nstatus: %d\n", status);
    }else
    {
        printf("cas d'échec");
        
    }
}