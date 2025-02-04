#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>


int main()
{

    pid_t pid1 =  fork(), // Fils1
        pid2,            // Fils2
        pid_premier_terminer; //le pid de la premier processus à terminer
    
    // Père: creation de la deuxième Fils
    if(pid1 != 0)
        pid2 = fork();
    

    // Fils1
    if(pid1 < 0)
    {
        printf("Erreur: Création du fils.");
        exit(EXIT_FAILURE);
    }
    if(pid1 == 0)
    {
        execlp("ls", "ls","-l",NULL);
        printf("Erreur: la commande ls -l a échoué.");
        exit(EXIT_FAILURE);
    }

    // Fils 2
    if(pid2 < 0)
    {
        printf("Erreur: Création du fils.");
        exit(EXIT_FAILURE);
    }
    if(pid2 == 0)
    {
        execlp("ps", "ps","-l",NULL);
        printf("Erreur: la commande ps -l a échoué.");
        exit(EXIT_FAILURE);
    }


    // Père : attendre la fin du premier processus à terminer
    pid_premier_terminer = wait(NULL);
    printf("\n\nLe premier processus à terminer:  Fils%d\n\n" , 
        ((pid1 == pid_premier_terminer )? 1 : 2)
    ); 
    
    // Attendre la fin du second processus
    wait(NULL);
    return 0;
}