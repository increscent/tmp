#include <stdio.h>
#include <signal.h>

int main(int argc, char** argv)
{
    printf("%d\n", SIGCHLD);

    return 0;
}
