#include <stdio.h>
#include <stdlib.h>
#define N 5
#define R 3

int *arrange(int *array, int *a, int x, int n)
{
    int i;
    int b[R];

    if(n == R)
    {
        for(i = 0; i < R; i++)
        {
            printf("%d,", a[i]);
        }
        printf("\n");
        return b;
    }
    else
    {
        for(i = 0; i < R; i++)
        {
            b[i] = a[i];
        }
        for(i = x+1; i <= N; i++)
        {
            b[n] = i;
            arrange(array, b, i, n+1);
        }
    }
}

int main()
{
    int array[N] = {1,2,3,4,5};
    int a[R] = {0};
    arrange(array, a, 0, 0);
    return 0;
}
