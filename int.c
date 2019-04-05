#include <stdio.h>

int main(int argc, char** argv)
{
    int a[10];
    int* b;

//    b = a;
    a = b;

    a[0] = 5;
    a[5] = 6;

    printf("sizeof a: %ld\n", sizeof(a));
    printf("sizeof b: %ld\n", sizeof(b));

    return 0;
}
