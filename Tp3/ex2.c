#include <stdio.h>
#include <unistd.h>

/*
    • Identifiant du processus.
    • Identifiant du père du processus.
    • Le propriétaire réel.
    • Le propriétaire effectif.
    • Le groupe propriétaire réel.
    • Le groupe propriétaire effectif.
*/


int main()
{   
    if( fork()==0 )
    {
        printf("\nNous avons dans le processus fils.");
        printf("\nIdentifiant du processus: %d", getpid());
        printf("\nLe propriétaire réel: %d", getuid());
        printf("\nLe groupe propriétaire réel: %d\n", getgid());
    }else
    {
        printf("\nNous avons dans le processus père.");
        printf("\nIdentifiant du père du processus: %d", getpid());
        printf("\nLe propriétaire effectif: %d", getuid());
        printf("\nLe groupe propriétaire effectif: %d\n", getgid());
    }
}