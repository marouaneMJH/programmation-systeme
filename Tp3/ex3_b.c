#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <time.h>

#define NOT_FOUND -1
#define SHM_SIZE 2 * sizeof(int)  // Mémoire partagée pour deux positions (père et fils)

int recherche_interval(int *tab, int val, int debut, int fin) {
    if (!tab) return NOT_FOUND;
    for (int i = debut; i < fin; i++) {
        if (tab[i] == val) return i;
    }
    return NOT_FOUND;
}

int is_in_tab(int* tab, int length, int val) {
    if (!tab) return NOT_FOUND;

    // Créer un segment de mémoire partagée
    int shm_id = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666);
    if (shm_id < 0)
    {
        perror("Erreur lors de la création de la mémoire partagée");
        exit(EXIT_FAILURE);
    }

    // Attacher la mémoire partagée
    int *shared_mem = (int *)shmat(shm_id, NULL, 0);
    if (shared_mem == (int *)-1)
    {
        perror("Erreur lors de l'attachement de la mémoire partagée");
        exit(EXIT_FAILURE);
    }

    // Initialiser les résultats dans la mémoire partagée à NOT_FOUND
    shared_mem[0] = NOT_FOUND;  // Résultat du père
    shared_mem[1] = NOT_FOUND;  // Résultat du fils

    pid_t pid_fils = fork();
    if (pid_fils < 0) {
        perror("Erreur au niveau de fork");
        exit(EXIT_FAILURE);
    }

    if (pid_fils == 0) {
        // Fils : recherche dans la première moitié
        shared_mem[1] = recherche_interval(tab, val, 0, length / 2);
        exit(EXIT_SUCCESS);
    } else {
        // Père : recherche dans la seconde moitié
        shared_mem[0] = recherche_interval(tab, val, length / 2, length);

        // Attendre la fin du fils
        wait(NULL);

        // Récupérer les résultats de la mémoire partagée
        int pos1 = shared_mem[0];
        int pos2 = shared_mem[1];

        // Détacher et supprimer la mémoire partagée
        shmdt(shared_mem);
        shmctl(shm_id, IPC_RMID, NULL);

        // Analyser les résultats
        if (pos1 == NOT_FOUND && pos2 == NOT_FOUND) {
            printf("\n%d n'existe pas dans le tableau\n", val);
            return NOT_FOUND;
        }

        int pos_finale = (pos1 == NOT_FOUND) ? pos2 : (pos2 == NOT_FOUND) ? pos1 : (pos1 < pos2 ? pos1 : pos2);
        return pos_finale;
    }
}

int main() {
    srand(time(NULL));
    int tab[8] = {1, 2, 3, 4, 5, 6, 7, 3};
    // int val = tab[rand() % 7];
    int val = 1;
    int length = 7;

    printf("\nLa position de %d est %d\n", val, is_in_tab(tab, length, val));

    return 0;
}
