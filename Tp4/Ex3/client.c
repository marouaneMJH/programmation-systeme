#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>

#define FILE_FTOK "index.txt"
#define PROJECT 1
#define MAX_LEN 100



typedef struct
{
    long type;
    int number1;
    int number2;
    pid_t id;
} MsgNumber;

typedef struct
{
    long type;  // Type de message
    char message[MAX_LEN];
} MsgChar;

int main()
{

    key_t key = ftok(FILE_FTOK, PROJECT);
    if (key == -1)
    {
        perror("Erreur de génération de la clé");
        exit(EXIT_FAILURE);
    }

    int id = msgget(key, IPC_CREAT | 0666);
    if (id == -1) {
        perror("Erreur de création de la file de messages");
        exit(EXIT_FAILURE);
    }

    MsgNumber req;
    req.type = 1;       // Type général pour envoyer au serveur
    req.id = getpid();  // Utiliser le PID du client
    printf("Entrez deux nombres (ex: 1 2): ");
    scanf("%d %d", &req.number1, &req.number2);

    // Envoyer la requête au serveur
    msgsnd(id, &req, sizeof(req) , 0);

    // Attendre la réponse du serveur, de type correspondant au PID du client
    MsgChar res;
    msgrcv(id, &res, sizeof(res) , req.id, 0);

    // Afficher la réponse
    printf("\nRéponse du serveur: %s", res.message);
    printf("\nEt mon pid est:%d\n",req.id);
    return 0;
}
