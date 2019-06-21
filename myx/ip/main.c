#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void find(string a)
{
    if(strlen(a) <=3 && strlen(a) > 1 && a[0] != 0 && a[0]*100+a[1]*10+a[2] <= 255)
    {
        return;
    }
    else
    {

    }
}

int main()
{
    string a = "25525511135";
    find(a);
    return 0;
}
