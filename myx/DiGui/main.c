#include <stdio.h>
#include <stdlib.h>

float fun(float a[], int length)
{
    if(length == 0)
        return a[length];
    else
        return (a[length - 1] + (length - 1) * fun(a, length - 1)) / length;
}

int main()
{
    float a[] = {1,2,3,4,5,6};
    int length = sizeof(a) / sizeof(float);
    printf("%f", fun(a, length));
    return 0;
}
