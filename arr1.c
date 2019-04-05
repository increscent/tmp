#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    int a[argc][argc];

    for (int i = 0; i < argc; i++)
        for (int j = 0; j < argc; j++)
            a[i][j] = random();

    for (int i = argc-1; i >= 0; i--)
        for (int j = argc-1; j >= 0; j--)
            printf("%d\n", a[i][j]);

    return 0;
}
