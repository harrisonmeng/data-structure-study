#include <stdio.h>
#include <stdlib.h>

int Monkey(int x, int n)
{
    if(n == 0)
        return 1;
    else
    {
        if((x - 1) % 5 == 0)
        {
            return Monkey((x - 1) / 5 * 4, n - 1);
        }
        else
        {
            return 0;
        }
    }
}

int main()
{
    int num = 0;
    while(Monkey(num, 5) == 0)
    {
        num++;
    }
    printf("%d", num);
    return 0;
}
