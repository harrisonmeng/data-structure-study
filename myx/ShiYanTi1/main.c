#include <stdio.h>
#include <stdlib.h>
#include "str.h"

int main()
{
    stringtype *s, *s1, *s2, *s3, *s4;
    char sc[] = "abcdefghijklmn";
    char s1c[] = "xyz";

    StrAssign(&s, sc);
    StrAssign(&s1, s1c);

    DisStr(s);
    printf("%d\n",StrLength(s));
    s2 = InsStr(s, 9, s1);
    DisStr(s2);
    s2 = DelStr(s, 2, 5);
    DisStr(s2);
    s2 = RepStr(s, 2, 5, s1);
    DisStr(s2);
    s3 = SubStr(s, 2, 10);
    DisStr(s3);
    s4 = Concat(s1, s2);
    DisStr(s4);
    return 0;
}
