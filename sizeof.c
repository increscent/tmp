#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[]) {
    char s1[] = "CS 324";
    char s2[] = "CS 324";

    char a1[] = { 'C', 'S', ' ', '3', '2', '4', '\0' };
    char a2[] = { 67, 83, 32, 51, 50, 52, 0 };
    char a3[] = { 0x43, 0x53, 0x20, 0x33, 0x32, 0x34, 0x00 };
    char a4[] = { '\x43', '\x53', '\x20', '\x33', '\x32', '\x34', '\x00' };

    char b1[] = { 'C', 'S', ' ', '3', '2', '4' };
    char b2[] = { 67, 83, 32, 51, 50, 52 };
    char b3[] = { 0x43, 0x53, 0x20, 0x33, 0x32, 0x34 };
    char b4[] = { '\x43', '\x53', '\x20', '\x33', '\x32', '\x34' };

    char c1[] = { 'C', 'S', '\0', '3', '2', '4', '\0' };
    char c2[] = { 'C', 'S', '\0', '4', '6', '0', '\0' };

    char d1[100];
    char d2[100];

    char* d3 = malloc(100);

    /* Just to prove a point. */
    memset(d1, 0xff, sizeof(d1));
    memset(d2, 0xff, sizeof(d2));

    d1[0] = 'C';
    d1[1] = 'S';
    d1[2] = ' ';
    d1[3] =	'3';
    d1[4] = '2';
    d1[5] = '4';
    d1[6] = '\0';

    d2[0] = 'C';
    d2[1] = 'S';
    d2[2] = ' ';
    d2[3] =	'3';
    d2[4] = '2';
    d2[5] = '4';

    printf("%lu\n", sizeof(d1));
    printf("%lu\n", sizeof(d3));
    printf("%lu\n", sizeof(char*));
    printf("%u\n", d1);
    return 0;
}
