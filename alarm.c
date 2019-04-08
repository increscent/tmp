#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int beep = 5;

void sig_handler(int sig)
{
    if (--beep > 0)
    {
        write(1, "BEEP\n", 5);
        alarm(1);
    } else
    {
        write(1, "BOOM!\n", 6);
        exit(0);
    }
}

int main()
{
    signal(SIGALRM, sig_handler);
    alarm(1);

    while(1);
    return 0;
}
