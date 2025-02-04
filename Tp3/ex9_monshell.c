#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_ARG 10
#define MAX_ARG_SIZE 30

char** lire_buffer()
{
    // allocation dynamique de mémoire
    char **argv = (char**)malloc(MAX_ARG * sizeof(char*));
    if (!argv) exit(EXIT_FAILURE);

    for (int i = 0; i < MAX_ARG; i++)
    {
        argv[i] = (char*)malloc(MAX_ARG_SIZE * sizeof(char));
        if (!argv[i]) exit(EXIT_FAILURE);
    }

    char car;
    int ligne_counter = 0, column_counter = 0;

    printf("monshell>");
    while ((car = getchar()) != '\n' && ligne_counter < MAX_ARG)
    {
        if (car == ' ' || car == '\t') {
            if (column_counter > 0) // Nouvel argument
            { 
                argv[ligne_counter][column_counter] = '\0';
                ligne_counter++;
                column_counter = 0;
            }
        } else
            argv[ligne_counter][column_counter++] = car;    
    }

    if (column_counter > 0)
    { 
        argv[ligne_counter][column_counter] = '\0';
        ligne_counter++;
    }

    argv[ligne_counter] = NULL;
    return argv;
}

void free_command(char **argv)
{
    for (int i = 0; i < MAX_ARG; i++)
        if (argv[i]) free(argv[i]);
    free(argv);
}

int main() {
    char **argv;
    pid_t pid;

    do {
        argv = lire_buffer();
        if (!argv[0]) continue; // Pas de commande saisie

        if (strcmp(argv[0], "exit") == 0)
        {
            free_command(argv);
            break;
        }

        pid = fork();
        if (pid == 0)
        {
            execvp(argv[0], argv);
            printf("Erreur:échec de l'exécution");
            exit(EXIT_FAILURE);
        } 
        else if (pid > 0) {
            waitpid(pid, NULL, 0);
        } else 
            printf("Erreur de fork");

        free_command(argv);
    } while (1);

    return 0;
}
