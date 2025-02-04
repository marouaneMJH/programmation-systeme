#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

// Gestionnaire de signal pour SIGCHLD
void signal_handler(int signal_id) {
    if (signal_id == SIGCHLD) {
        pid_t pid;

        // pour que le processus fils ne doit pas zombie
        pid = waitpid(-1, NULL, WNOHANG);
        printf("\nProcessus[%d] le Fils[%d] est terminer.\n",getpid(),pid);

    }
}

int main(int argc, char *argv[]) {
    // Associer le gestionnaire de signal
    signal(SIGCHLD, signal_handler);

    // Création du processus fils
    if (!fork()) {
        for (int i = 0; i < 10; i++) {
            printf("Fils effectue un calcul: %d\n", i);
            // Simule un petit calcul avec un délai
            usleep(300000);
        }
        exit(0); // Fin du processus fils
    }

    // Simule un calcul infini pour le père
    while (1) {
        printf("Père continue son travail...\n");
        sleep(2); // Simule un travail du père
    }

    return 0;
}
