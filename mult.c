#include <stdio.h>

int main(int argc, char* argv[])
{
    printf("%d\n", -2147483647 * 3 / 4);
    printf("%d\n", (-2147483647 + (-2147483647 << 1)) >> 2);
    printf("%d\n", (-9 + (-9 << 1)) >> 2);
    printf("%x\n", 0x80000000 * 3);
    printf("%x\n", (0x80000000 + (0x80000000 << 1)));
    printf("%x\n", (0x80000001 + (0x80000001 << 1)));
    printf("%x\n", 0x80000003 / 4);
    int x = 0x80000003;
    int y = 0x7FFFFFFF;
    printf("%x\n", x * 3 / 4);
    printf("%x\n", x / 4);
    printf("%x\n", x / 2);
    printf("%x\n", x >> 31);
    printf("%x\n", y >> 31);
    printf("%x\n", (1 << 2) - 1);
    return 0;
}
