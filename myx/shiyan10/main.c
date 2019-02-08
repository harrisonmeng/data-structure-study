#include <stdio.h>
#include <stdlib.h>
#include "str.h"

int Check(stringtype *s)
{
    int i, j;
    if(s->length % 2 == 0 || s->data[s->length / 2] != '@')
        return 0;
    for(i = 0; i < s->length; i++)
    {
        if(i != s->length / 2 && s->data[i] == '@')
            return 0;
    }
    i = s->length / 2 - 1;
    j = s->length / 2 + 1;
    while(i >= 0)
    {
        if(s->data[i] != s->data[j])
            return 0;
        i--;
        j++;
    }
    return 1;
}

int main()
{
    stringtype *s;
    char c[] = "abcde345@543edcba";

    StrAssign(&s, c);
    DisStr(s);
    printf("%d\n", s->length);
    printf("%d\n", Check(s));
    return 0;
}
