#include <stdio.h>
#include <stdlib.h>

int fun(int n)
{
    if(n / 10 == 0)
        return 1;
    else
        return 1 + fun(n / 10);
}

int main()
{
    int n = 123456789;
    printf("%d", fun(n));
    return 0;
}
