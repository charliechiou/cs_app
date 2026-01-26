#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv, char **envp)
{
    printf("Commad-ine arguments:\n");
    for (int i = 0; i < argc; i++)
    {
        printf("argv[ %d]: %s\n", i, argv[i]);
    }

    printf("Environment variables:\n");
    int count = 0;
    while (envp[count] != NULL)
    {
        printf("envp[%d]: %s\n", count, envp[count]);
        count++;
    }

    return 0;
}