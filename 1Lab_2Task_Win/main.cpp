#include<Windows.h>
#include<processthreadsapi.h>
#include<stdio.h>


BOOL WINAPI CTRLHANDRLER(_In_ DWORD CTRLTYPE) 
{
    if (CTRLTYPE == CTRL_C_EVENT) 
    {
        printf("CTRL-C event\n");
        exit(1);
    }
    else if (CTRLTYPE == CTRL_CLOSE_EVENT) 
    {
        printf("CTRL-CLOSE event\n");
        exit(2);
    }
    else 
    {
        return FALSE;
    }
}

void PRINTNUMBER() 
{
    while (TRUE) 
    {
        printf("%f\n", (double)rand() / RAND_MAX);
        Sleep(1500);
    }
}

void REVERSE() 
{
    while (TRUE) 
    {
        char str[250];
        scanf_s("%s", str, 250);
        printf("%s\n", _strrev(str));
    }
}

int main() 
{
    SetConsoleCtrlHandler(CTRLHANDRLER, TRUE);
    CreateThread(NULL, 0, PRINTNUMBER, NULL, 0, NULL);
    CreateThread(NULL, 0, REVERSE, NULL, 0, NULL);
    while (TRUE) {}

    return 0;
}
