#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void SignalHandler()
{
    printf("Received signal: Ctrl + C\n");
    exit(0);
}

int main() 
{
    signal(SIGINT, SignalHandler);
    signal(SIGTERM, SignalHandler);

    printf("Waiting for signal\n");

    while (1) {}

    return 0;
}