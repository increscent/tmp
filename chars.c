#include <stdio.h>
#include <unistd.h>

int main(int argc, char** argv)
{
    char c;

    while(read(0, &c, 1))
    {
        if (c == '\n')
            printf("'\\n',\n");
        else if (c == '\t')
            printf("'\\t',\n");
        else
            printf("'%c',\n", c);
    }

    return 0;
}
