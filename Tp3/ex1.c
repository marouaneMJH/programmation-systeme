#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>



/*
 * Pour garantir l'ordre d'exécution dans cet exemple,
 * on utilise la fonction waitpid pour s'assurer que le
 * petit-fils termine avant que le fils continue son exécution.
*/
int main(int argc, char *argv[])
{
	
	// crée le premier processus 
	pid_t pid1 = fork();
	if(pid1 < 0)
	{
		perror("\nErreur au niveau du fork.");
		exit(EXIT_FAILURE);
	}
	else if(pid1 == 0)
	{
		// création du petit-fils
		pid_t pid2 =  fork();
		if(pid2 < 0)
		{
			perror("\nErreur au niveau du fork.");
			exit(EXIT_FAILURE);
		}
		else if(pid2 == 0)
		{
			// petit-fils: afficher les nombre 1-50
			for(int i=1;i<=50;i++)
				printf("%d \t", i);
			exit(EXIT_SUCCESS);
		}
		// Fils : attend la fin d'exécution du petit-fils
		waitpid(pid2, NULL, 0);
		// Fils: affiche les nombre 51-100 
		for(int i=51;i<=100;i++)
			printf("%d \t", i);
		exit(EXIT_SUCCESS);
	}
	else
	{
		// Père : atend la fin d'exécution du Fils 
		waitpid(pid1, NULL, 0);
		exit(EXIT_FAILURE);
	}
	
	return 0;
}
