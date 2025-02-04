#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>




int main(int argc,char* argv[])
{
    // vérifier la taille des argument 
    if(argc < 2)
    {
        printf("\n\nEnter le nom du la commande, Usage: %s <<nom_cmd>> -<<options>>\n\n",argv[0]);
        exit(EXIT_FAILURE);
    }

    // executer la commande
    execvp(argv[1],&argv[1]);
    // si l'exécution a échoué
    printf("La commande '%s' n'existe pas.\n",argv[1]);
    exit(EXIT_SUCCESS);
}