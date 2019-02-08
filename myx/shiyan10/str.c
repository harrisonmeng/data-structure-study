#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "str.h"
void StrAssign(stringtype **s, char cstr[])
{
    int i;
    int length;
    stringtype *str;

    length = strlen(cstr);
    str = (stringtype*)malloc(sizeof(stringtype));
    str->data = (char*)malloc(length * sizeof(char));
    str->length = length;
    for(i = 0; cstr[i] != '\0'; i++)
    {
        str->data[i] = cstr[i];
    }
    *s = str;
}

void DestroyStr(stringtype *s)
{
    free(s->data);
    free(s);
}

void StrCopy(stringtype *s, stringtype *t)
{
    int i;
    for(i = 0; i < t->length; i++)
    {
        s->data[i] = t->data[i];
    }
    s->length = t->length;
}

int StrEqual(stringtype *s, stringtype *t)
{
    int same = 1;
    int i;
    if(s->length != t->length)
        same = 0;
    else
        for(i = 0; i < s->length; i++)
            if(s->data[i] != t->data[i])
            {
                same = 0;
                break;
            }
    return same;
}

int StrLength(stringtype *s)
{
    return s->length;
}

stringtype* Concat(stringtype *s, stringtype *t)
{
    stringtype *str;
    int i;

    str = (stringtype*)malloc(sizeof(stringtype));
    str->data = (char*)malloc((s->length + t->length) * sizeof(char));
    str->length = s->length + t->length;
    for(i = 0; i < s->length; i++)
    {
        str->data[i] = s->data[i];
    }
    for(i = 0; i < t->length; i++)
    {
        str->data[s->length + i] = t->data[i];
    }
    return str;
}

stringtype* SubStr(stringtype *s, int i, int j)
{
    int k;
    stringtype *str;
    str = (stringtype*)malloc(sizeof(stringtype));
    str->data = (char*)malloc(j * sizeof(char));
    str->length = 0;
    if(i <= 0 || i > s->length || j < 0 || i+j-1 > s->length)
        return str;
    for(k = i-1; k < i+j-1; k++)
        str->data[k-i+1] = s->data[k];
    str->length = j;
    return str;
}

stringtype* InsStr(stringtype *s1, int i, stringtype *s2)
{
    int j;
    stringtype *str;
    str = (stringtype*)malloc(sizeof(stringtype));
    str->data = (char*)malloc((s1->length + s2->length) * sizeof(char));
    str->length = 0;
    if(i <= 0 || i > s1->length+1)
        return str;
    for(j = 0; j < i-1; j++)
        str->data[j] = s1->data[j];
    for(j = 0; j < s2->length; j++)
        str->data[i+j-1] = s2->data[j];
    for(j = i-1; j < s1->length; j++)
        str->data[s2->length + j] = s1->data[j];
    str->length = s1->length + s2->length;
    return str;
}

stringtype* DelStr(stringtype *s, int i, int j)
{
    int k;
    stringtype *str;
    str = (stringtype*)malloc(sizeof(stringtype));
    str->data = (char*)malloc((s->length - j) * sizeof(char));
    str->length = 0;
    if(i <= 0 || i > s->length || i + j > s->length + 1)
        return str;
    for(k = 0; k <i - 1; k++)
        str->data[k] = s->data[k];
    for(k = i + j - 1; k < s->length; k++)
        str->data[k - j] = s->data[k];
    str->length = s->length - j;
    return str;
}

void DisStr(stringtype *s)
{
    int i;
    if(s->length>0)
    {
        for(i = 0; i < s->length; i++)
            printf("%c",s->data[i]);
        printf("\n");
    }
}

stringtype* RepStr(stringtype *s, int i, int j, stringtype *t)
{
    int k;
    stringtype *str;
    str = (stringtype*)malloc(sizeof(stringtype));
    str->data = (char*)malloc((s->length - j + t->length) * sizeof(char));
    str->length = 0;
    if(i <= 0 || i > s->length || i + j - 1 > s->length)
        return str;
    for(k = 0; k < i-1; k++)
        str->data[k] = s->data[k];
    for(k = 0; k < t->length; k++)
        str->data[i+k-1] = t->data[k];
    for(k = i+j-1; k < s->length; k++)
        str->data[t->length + k - j] = s->data[k];
    str->length = s->length - j + t->length;
    return str;
}
