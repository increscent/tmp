#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char** argv)
{
    FILE* f = fopen("test.txt", "w");

    int fd = fileno(f);
    printf("fd: %d\n", fd);

    dup2(2, fd);
    int newfd = dup(2);

    fprintf(f, "testing 123\n");

    write(newfd, "hi\n", 3);

    return 0;
}
