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
    long type;  // Type de message
    int number1;
    int number2;

    pid_t id;
} MsgNumber;

typedef struct
{
    long type;  // Type de message
    char message[MAX_LEN];
} MsgChar;

int main() {
    key_t key = ftok(FILE_FTOK, PROJECT);
    if (key == -1)
    {
        perror("Erreur de génération de la clé");
        exit(EXIT_FAILURE);
    }

    int id = msgget(key, IPC_CREAT | 0666);
    if (id == -1)
    {
        perror("Erreur de création de la file de messages");
        exit(EXIT_FAILURE);
    }

    printf("Serveur en attente des messages...\n");

    while (1)
    {
        MsgNumber req;
        msgrcv(id, &req, sizeof(req) , 1, 0);

        printf("Message reçu de PID %d: %d + %d\n", req.id, req.number1, req.number2);

        // Préparer la réponse
        MsgChar res;
        res.type = req.id;  // Répondre avec le type correspondant au PID du client
        sprintf(res.message, "Le résultat de %d + %d est %d", req.number1, req.number2, req.number1 + req.number2);

        // Envoyer la réponse au client
        msgsnd(id, &res, sizeof(res), 0);
    }

    return 0;
}
