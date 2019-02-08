#include <stdio.h>
#include <stdlib.h>

float fun(int a[], int length)
{
    if(length == 0)
        return a[length];
    else
        return (a[length-1]+(length-1)*fun(a, length - 1)) / length;
}

int main()
{
    int a[] = {1,2,1,2,1,2};
    int length = 6;
    printf("%f", fun(a, length));
    return 0;
}
