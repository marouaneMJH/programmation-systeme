#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <time.h>







int main()
{
    // pour choisit un nombre aléatoire pour chaque execution
    srand(time(0));


    // création du fils 
    pid_t pid_fils = fork();

    // vérifier la création du fils  
    if ( pid_fils < 0 )
    {
        perror("\nErreur au niveau de fork(creation du fils).)");
        exit(EXIT_FAILURE);
    }
    //  Dans le processus Fils.
    if(pid_fils == 0)
    {
        //  Fils: choisi une nombre aléatoire  entre 0 et 100
        exit(rand()%101);
    }
    // Dans le processus Père
    else
    {
        
        int status;// Pour récupérer  le status de processus Fils 

        


        // Père: attent l'exécution du fin le processus fils 
        if( waitpid(pid_fils,&status,0) == -1 )
        {
            perror("Erreur le processus fils n'existe  pas");
            exit(EXIT_FAILURE);
        }
        // si le code le processus fils exit avec une valeur aléatoire 
        if(WIFEXITED(status))
        {
            printf("\nle code du retour du processus fils est: %d",WEXITSTATUS(status));
        }
    }
    return 0;

}