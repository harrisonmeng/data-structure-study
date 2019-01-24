#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void PaiXu(stacktype *s)
{
    stacktype *p;
    char temp;

    InitStack(&p);
    Push(Pop(s), p);
    while(StackEmpty(s) == 0)
    {
        if(s->data[s->top] >= p->data[p->top])
        {
            Push(Pop(s), p);
        }
        else
        {
            temp = Pop(s);
            while(p->data[p->top] > temp && StackEmpty(p) != 1)
            {
                Push(Pop(p), s);
            }
            Push(temp, p);
        }
    }

    while(StackEmpty(p) == 0)
    {
        Push(Pop(p), s);
    }
    FreeStack(p);
}

int main()
{
    unsigned int seed;
    stacktype *s;

    InitStack(&s);
    srand(seed);
    while(StackFull(s) == 0)
    {
        Push(rand() % ('~' - '!') + '!', s);
    }
    PrintStack(s);
    PaiXu(s);
    PrintStack(s);
    FreeStack(s);
    return 0;
}
