#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void* RandNum(void*) 
{
	while (1)
  {
		printf("%f\n", (float)rand() / ((float)RAND_MAX / 1));
		sleep(3);
	}
	return 0;
}

void* InputHandler(void*)
{
	while (1) 
  {
		char str[100];
		scanf("%s", str);
		for (int i = strlen(str) - 1; i >= 0; --i) 
    {
			printf("%c", str[i]);
		}
		printf("\n");
	}

	return 0;
}

void SignalHandler(int signal) 
{
	switch(signal) 
  {
		case SIGINT:
			printf("\nSIGINT %d\n", signal);
			break;
		case SIGTERM:
			printf("\nSIGTERM %d\n", signal);
			break;
		default:
			printf("\nAnother signal %d\n", signal);
			break;
	}
	exit(0);
}

int main(int argc, char** argv) 
{
	pthread_t thread1, thread2;
	int ret1, ret2;

	signal(SIGINT, SignalHandler);
	signal(SIGTERM, SignalHandler);
 
	ret1 = pthread_create(&thread1, NULL, RandNum, NULL);
	ret2 = pthread_create(&thread2, NULL, InputHandler, NULL);
 
	while(1){};
 
	return 0;
}
