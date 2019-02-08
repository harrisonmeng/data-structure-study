#include <stdio.h>
#include <stdlib.h>
#include "str.h"

stringtype* Find(stringtype *s)
{
    stringtype *str1, *str2;
    int i, j, k;
    str1 = SubStr(s, 0, s->length);
    for(k = 0; k < s->length; k++)
    {
        for(i = s->length; i > 0; i--)
        {
            str2 = SubStr(s, k, i);
            for(j = k + 1; j < s->length; j++)
            {
                if(StrEqual(SubStr(s, j, i), str2))
                {
                    if(str2->length > str1->length)
                    {
                        DestroyStr(&str1);
                        StrAssign(&str1, str2->data);
                    }
                    continue;
                }
            }
        }
    }
    return str1;
}

int main()
{
    stringtype *s;
    char c[] = "aabbacccccabbaabab";

    StrAssign(&s, c);
    DisStr(Find(s));
    return 0;
}
