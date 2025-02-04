#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define W 1
#define R 0

// ps -aux | grep "root" | wc -l
int main() {

    // Les Pipes
    int fd1[2];
    int fd2[2];

    // Création des pipes
    if (pipe(fd1) == -1 || pipe(fd2) == -1)
    {
        perror("Erreur dans la création des pipes");
        exit(EXIT_FAILURE);
    }

    // Création des processus fils pour exécuter les commandes
    pid_t ps, grep, wc;

    ps = fork();
    
    if(ps)
        grep = fork();
    
    if(ps && grep)
            wc = fork();

    // Processus fils pour `ps -aux`
    if (!ps ) {
        // Fermer les descripteurs inutilisés
        close(fd2[W]);
        close(fd2[R]);
        close(fd1[R]);

        // Rediriger la sortie standard vers le pipe1 (fd1[W])
        dup2(fd1[W], STDOUT_FILENO);
        close(fd1[W]);

        execlp("ps", "ps", "-aux", NULL);
        perror("[!exec] ps");
        exit(EXIT_FAILURE);
    }

    // Processus fils pour `grep "root"`
    if (!grep ) {
        // Fermer les descripteurs inutilisés
        close(fd1[W]);
        close(fd2[R]);
        // Rediriger l'entrée standard depuis le pipe1 (fd1[R])

        // Rediriger la sortie standard vers le pipe2 (fd2[W])
        dup2(fd2[W], STDOUT_FILENO);
        close(fd2[W]);

        dup2(fd1[R], STDIN_FILENO);
        close(fd1[R]);

        execlp("grep", "grep", "root", NULL);
        perror("[!exec] grep");
        exit(EXIT_FAILURE);
    }

    // Processus fils pour `wc -l`
    if (!wc ) {
        // Fermer les descripteurs inutilisés
        close(fd2[W]);
        close(fd1[W]);
        close(fd1[R]);
        // Rediriger l'entrée standard depuis le pipe2 (fd2[R])
        dup2(fd2[R], STDIN_FILENO);
        close(fd2[R]);

        execlp("wc", "wc", "-l", NULL);
        perror("[!exec] wc");
        exit(EXIT_FAILURE);
    }

    // Fermeture des descripteurs de pipe inutilisés dans le processus parent
    close(fd1[R]);
    close(fd2[W]);
    close(fd2[R]);
    close(fd1[W]);

    // Attendre la fin des processus fils
    wait(NULL);
    wait(NULL);
    wait(NULL);

    return 0;
}
