#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <time.h>



int main()
{
    
    pid_t pid = fork();
    int status;

    // les argument du l'exécution de la commande ps
    char* const argv[] = {
        "ps",
        "l",
        NULL
    };

    // Père: Vérifier la création du processus fils 
    if (pid < 0)
    {
        perror("Erreur dans la creation du processus fils.");
        exit(EXIT_FAILURE);
    }
    if(pid == 0)
    {
        // exécutant la commande ps
        execv("/bin/ps" ,argv);
        perror("Erreur: l'exécution ps ne fonctionne pas.");
        exit(EXIT_FAILURE);
    }

    // Père: attent la fin d'exécution de processus fils
    waitpid(pid, &status, 0);
    
    if(WIFEXITED(status))
    {
        if(WEXITSTATUS(status)==EXIT_SUCCESS)
            printf("L'exécutable ps est bien exécuter");
        else
            perror("L'exécutable ps n'est bien exécuter");

    }

    return 0;
}