#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(int argc, char** argv)
{
    int* d1_arr = malloc(sizeof(int) * 3*4*5);

    int (*d3_arr)[3][4][5] = (int(*)[3][4][5])d1_arr;

    (*d3_arr)[1][2][3] = 5;
    printf("value at d3_arr[1][2][3]: %d\n", (*d3_arr)[1][2][3]);
    printf("value at d1_arr[1*4*5 + 2*5 + 3]: %d\n", d1_arr[1*4*5 + 2*5 + 3]);

    return 0;
}
