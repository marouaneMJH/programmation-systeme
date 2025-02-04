#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// 1.	who & ps & ls -l


int main()
{
    pid_t pid_1,pid_2,pid_3;

    pid_1 = pid_2 = pid_3 = -1;

    pid_1 = fork();

    // Fils1
    if(!pid_1)
    {
        execlp("who", "who",NULL);
        printf("Erreur: la commande who a échoué");
        exit(EXIT_FAILURE);
    }

    pid_2 = fork();
    // Fils2
    if(!pid_2)
    {
        execlp("ps", "ps",NULL);
        printf("Erreur: la commande 'ps' a échoué");
        exit(EXIT_FAILURE);
    }

    pid_3 =  fork();
    // Fils3
    if(!pid_3)
    {
        execlp("ls", "ls", "-l",NULL);
        printf("Erreur: la commande 'ls' a échoué");
        exit(EXIT_FAILURE);
    }
    
    exit(EXIT_SUCCESS);
}