#include <stdio.h>

struct Test
{
    unsigned short a:5;
    unsigned short b:5;
    unsigned short c:6;
};

struct Test2
{
    short a:4;
    short b:9;
    short c:3;
};

int main()
{
    long long a = 1, b = 2, c = 3;
    printf("%d %d %d\n", a, b, c);

    struct Test test;
    test.a = 16;
    test.b = 2;
    test.c = 0;
    int i = *(short *)&test;
    printf("%d %x\n", i, test);

    struct Test2 test2;
    test2.a = 3;
    test2.b = 74;
    test2.c = 0;
    int j = *(short *)&test2;
    printf("%d %x\n", j, j);

    return 0;
}
