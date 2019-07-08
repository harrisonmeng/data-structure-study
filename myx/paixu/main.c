#include <stdio.h>
#include <stdlib.h>

int perm(char *p, int i, int n)
{
    int j;
    char temp;
 //   char p[4];
 //   for(j = 0; j < 4; j++)
 //   {
 //       p[j] = a[j];
 //   }

    if (i == n)
    {
        printf("\t%s\n", p);
    }
    else
    {
        for (j = i; j < n; j++)
        {
            if(i!=j)
            {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }

            perm(p, i+1, n);

            if(i!=j)
            {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

int main()
{
    char a[] = "abcde";
    printf("output:\n");
    perm(a, 0, sizeof(a)-1);
    return 0;
}
