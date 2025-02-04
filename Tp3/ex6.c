#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <nom_du_fichier>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Construire la commande "cat <nom_du_fichier>"
    char commande[256];
    snprintf(commande, sizeof(commande), "cat %s", argv[1]);
    printf("\nla taille de commande est: %ld\n\n\n\n", sizeof(commande));

    // Exécuter la commande avec system()
    int status = system(commande);

    // Vérifier si la commande s'est exécutée correctement
    if (status == -1) {
        printf("Erreur lors de l'exécution de la commande");
        return EXIT_FAILURE;
    }


    return EXIT_SUCCESS;
}
