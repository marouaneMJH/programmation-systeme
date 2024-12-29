#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{

    if (fork() == 0)
        for (int i = 0; i < 50; i++)
            printf("\t  %d", i + 1);
    else if (fork() == 0)
            for (int i = 50; i < 100; i++)
                printf("\t  %d", i + 1);
}
