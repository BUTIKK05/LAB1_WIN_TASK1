#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void SignalHandler()
{
    printf("Received signal: Ctrl + C\n");
    exit(0);
}

int main() {
    signal(SIGINT, SignalHandler);
    signal(SIGTERM, SignalHandler);

    printf("Waiting for signal\n");

    pid_t pid = fork();

    if (pid < 0) 
    {
        printf("Failed to fork process\n");
        return 1;
    }
    else if (pid == 0) 
    {

        while (1) {}

        exit(0);
    }
    else 
    {
        int status;
        pid_t terminated_pid = wait(&status);

        if (WIFSIGNALED(status)) 
        {
            printf("Child process terminated by signal: %d\n", WTERMSIG(status));
        }
        else 
        {
            printf("Child process exit status unknown\n");
        }
    }

    return 0;