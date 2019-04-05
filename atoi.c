#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(int argc, char** argv)
{
    int i = strtol("hi", NULL, 10);

    printf("i: %d\n", i);
    printf("%s\n", strerror(errno));

    return 0;
}
