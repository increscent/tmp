#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(int argc, char** argv)
{
    char* input = "GET http://www.cmu.edu/hub/index.html HTTP/1.1";

    char method[20];
    char domain[20];
    char path[100];
    char version[20];

    sscanf(input, "%s http://%s/%s %s", method, domain, path, version);

    printf("method: %s\n", method);
    printf("domain: %s\n", domain);
    printf("path: %s\n", path);
    printf("version: %s\n", version);


    return 0;
}
