#include <stdio.h>
#include <stdlib.h>

int perm(char *a, int i, int n)
{
    int j;
    int temp;
    char p[4];
    for(j = 0; j < 4; j++)
    {
        p[j] = a[j];
    }

    if (i == n)
    {
        printf("\t%s\n", p);
    }
    else
    {
        for (j = i; j < n; j++)
        {
            temp = p[i];
            p[i] = p[j];
            p[j] = temp;

            perm(p, i+1, n);

            temp = p[i];
            p[i] = p[j];
            p[j] = temp;
        }
    }
}

int main()
{
    int n = 3;
    char a[4] = "abc";
    printf("ееап:\n");
    perm(a, 0, n);
    return 0;
}
