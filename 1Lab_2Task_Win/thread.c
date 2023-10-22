#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <string.h>

void* InputHandler()
{
    char a[256];

    while (1)
    {
        if (fgets(a, sizeof(a), stdin) != NULL)
        {
            int b = strlen(a);
            for (int i = b - 2; i >= 0; i--)
            {
                putchar(a[i]);
            }
            putchar('\n');
        }
    }
}

void* RandNum() 
{

    while (1) 
    {
        double random = (double)rand() / RAND_MAX;
        printf("%.2f\n", random);
        sleep(3);
    }

}

void SignalHandler() 
{
    printf("Received Signal.\n");
    exit(1);
}

int main() 
{
    signal(SIGINT, SignalHandler);

    pthread_t RandNumThread, InputThread;

    if (pthread_create(&RandNumThread, NULL, RandNum, NULL) != 0)
    {
        perror("!Fail!");
        return 1;
    }

    if (pthread_create(&InputThread, NULL, InputHandler, NULL) != 0)
    {
        perror("!Fail!");
        return 1;
    }

    pthread_join(RandNumThread, NULL);

    pthread_join(InputThread, NULL);

    return 0;
}
