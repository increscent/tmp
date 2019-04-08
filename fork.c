#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int atexit = 0;

    if (fork() == 0)
        atexit = 1;

    if (fork() == 0)
    {
        printf("0"); fflush(stdout);
    } else
    {
        printf("1"); fflush(stdout);
    }

    if (atexit)
    {
        printf("2"); fflush(stdout);
    }
    return 0;
}
