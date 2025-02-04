#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>


// Gestionnaire de signal
void handler(int signal_id) {}

int main() {
    pid_t fils;
    signal(SIGUSR1, handler); // Configurer le gestionnaire de signal avant le fork

    fils = fork();
    if (fils == -1)
    {
        perror("[!]Fork");
        exit(EXIT_FAILURE);
    }


    if (fils == 0)
    { // Processus enfant
        // pause();
        for (int i = 0; i <= 100; i += 2)
        {
            printf("%d\t", i);  // Imprimer les nombres pairs
            fflush(stdout);
            kill(getppid(), SIGUSR1); // Envoyer un signal au parent
            pause(); // Attendre un signal du parent
        }
        exit(EXIT_SUCCESS);
    }
    
    
    pid_t order = fork();

    if(order < 0)
    {
        perror("[!]Fork");
        exit(EXIT_FAILURE);
    }

    if(order == 0)
    {
        sleep(1);
        kill(fils,SIGUSR1);
        exit(EXIT_SUCCESS);
    }

    // Processus parent
    for (int i = 1; i < 100; i += 2)
    {
        pause(); // Attender un signal de l'enfant
        printf("%d\t", i);  // Imprimer les nombres impairs
        fflush(stdout);
        kill(fils, SIGUSR1); // Envoyer un signal à l'enfant
    }

    waitpid(fils, NULL, 0);
    return 0;
}
