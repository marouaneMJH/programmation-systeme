#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    srand(time(NULL));

    // crée un processus fils
    pid_t pid = fork();
    int status;

    if (pid < 0) {
        perror("Erreur lors du fork");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0) {
        // Fils : termine avec un code de sortie 
        int return_types[]={-1,0,1,2,3,4};
        int termine=return_types[rand()%6];
        printf("Fils : Je me termine avec le code %d.\n",termine);
        exit(termine);
    }
    else {
        // Père : attend la fin du fils
        wait(&status);

        // Vérifie si le fils s'est terminé normalement
        if (WIFEXITED(status)) {
            printf("Père : Le fils s'est terminé normalement avec le code de sortie %d.\n", WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("Père : Le fils a été tué par le signal %d.\n", WTERMSIG(status));
        } else if (WIFSTOPPED(status)) {
            printf("Père : Le fils a été stoppé temporairement par le signal %d.\n", WSTOPSIG(status));
        }
    }

    return 0;
}
