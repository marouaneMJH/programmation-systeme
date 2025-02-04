#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    
    pid_t pid =   fork();
    int status;

    // Père: Vérifier la création du processus fils 
    if (pid < 0)
    {
        printf("Erreur dans la creation du processus fils.");
        exit(EXIT_FAILURE);
    }
    
    if(pid == 0)
    {
        // Fils: exécute l'exécutable ps avec l'option -l  

        // exécutant la commande ps
        execl("/bin/ps" ,"ps", "l", NULL);
        printf("Erreur: l'exécution de ps a échoué");
        exit(EXIT_FAILURE);
    }

    // Père: attent la fin d'exécution de processus fils
    waitpid(pid, &status, 0);
    
    if(WIFEXITED(status))
    {
        if(WEXITSTATUS(status)==EXIT_SUCCESS)
            printf("L'exécutable ps est bien exécuter");
        else
            printf("Erreur: l'exécution de ps a échoué");

    }
    return 0;
}