#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void SignalHandler()
{
    printf("Received signal: Ctrl + C\n");
    exit(0);
}

int main() {
    signal(SIGINT, SignalHandler);
    printf("Waiting for signal\n");

    if (SignalHandler, 1) {
        while (1) {}
    }
    else {
        printf("ERROR with setting control handler");
        return 1;
    }

    return 0;
}