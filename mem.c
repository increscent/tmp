#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, int argv)
{
    char* test = malloc(4096);
    memset(test, 'a', 4096);

    free(test);

    test[4095] = '\0';
    printf("\n%s\n", test + 4000);

    return 0;
}
