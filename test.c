#include <stdio.h>

int main(int argc, char** argv)
{
    int a = 0xFFFFFFFC;
    int b = (a + (a << 1)) >> 2;
    printf("%x\n", b);
    printf("%d\n", b);

    return 0;
}
