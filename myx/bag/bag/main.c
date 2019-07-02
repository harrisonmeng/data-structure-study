#include <stdio.h>
#include <stdlib.h>
#define BAGVOLUME 12

typedef struct Item_tag
{
    int cost;
    int volume;
}item;

typedef struct solution
{
    int sol[5];
}solution;

solution Method(item *items, solution a, int i)
{
    if(i > 4)
    {
        return a;
    }
    else
    {
        int csum1, csum2, vsum;
        int j;
        solution sol1,sol2;
        csum1 = 0;
        csum2 = 0;
        vsum = 0;

        for(j = 0; j < 5; j++)
        {
            sol1.sol[j] = sol2.sol[j] = a.sol[j];
        }

        sol1.sol[i] = 0;
        sol1 = Method(items, sol1, i+1);
        for(j = 0; j < 5; j++)
        {
            csum1 += sol1.sol[j] * items[j].cost;
            vsum += sol1.sol[j] * items[j].volume;
        }
        if(vsum > BAGVOLUME)
        {
            csum1 = 0;
        }

        vsum = 0;

        sol2.sol[i] = 1;
        sol2 = Method(items, sol2, i+1);
        for(j = 0; j < 5; j++)
        {
            csum2 += sol2.sol[j] * items[j].cost;
            vsum += sol2.sol[j] * items[j].volume;
        }
        if(vsum > BAGVOLUME)
        {
            csum2 = 0;
        }

        if(csum1 > csum2)
        {
            return sol1;
        }
        else
        {
            return sol2;
        }

    }
}

int main()
{
    item all_item[5] =
    {
        {50,3},
        {30,2},
        {20,1},
        {40,2},
        {80,6}
    };
    int i;
    solution a;

    a = Method(all_item, a, 0);
    for(i = 0; i < 5; i++)
    {
        printf("%d,",a.sol[i]);
    }
    return 0;
}
