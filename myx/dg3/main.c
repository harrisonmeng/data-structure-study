#include <stdio.h>
#include <stdlib.h>

int step(int n)
{
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
    else if(n == 2)
        return 2;
    else
        return step(n - 1) + step(n - 2);
}

int main()
{
    int n = 5;
    printf("%d", step(n));
    return 0;
}
