#include <stdio.h>
#include <unistd.h>

int main()
{
    int i = 0;
    for (; i < 3; ++i)
    {
        fork();
        printf("1");
    }
    return 0;
}
