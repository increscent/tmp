#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <setjmp.h>

sigjmp_buf jmpbuf;

void handler(int sig)
{
    siglongjmp(jmpbuf, 1);
}

int main()
{
    if (!sigsetjmp(jmpbuf, 1))
    {
        printf("Starting...\n");
        signal(SIGTSTP, handler);
    } else
        printf("Restarting...\n");

    while(1)
    {
        printf("foo\n");
        sleep(1);
    }
    return 0;
}
