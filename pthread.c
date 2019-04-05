#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(int argc, char** argv)
{

    printf("pthread_mutex_t: %ld\n", sizeof(pthread_mutex_t));
    printf("sem: %ld\n", sizeof(pthread_mutex_t));
    return 0;
}
