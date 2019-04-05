#include <unistd.h>
#include <stdio.h>

int main(int argc, char** argv)
{
    FILE* f = fopen("test.txt", "w");

    dup2(fileno(f), 1);

    fprintf(stdout, "hi\n");

    return 0;
}
