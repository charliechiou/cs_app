#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

unsigned int snooze(unsigned int secs)
{
    unsigned int sleep_time = sleep(secs);
    printf("\nSlept for %d of %d secs. \n", secs - sleep_time, secs);
    return sleep_time;
}

void kill_handler(int sig)
{
    return;
}

int main(int argc, char **argv, char **envp)
{
    if (argc != 2)
    {
        fprintf(stderr, "usage: %s <secs>\n", argv[0]);
        exit(0);
    }

    if (signal(SIGINT, kill_handler) == SIG_ERR)
    {
        printf("Error");
    }
    snooze(atoi(argv[1]));

    return 0;
}