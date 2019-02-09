#include <stdio.h>
#include <stdlib.h>

void fun(char n[], int length)
{
    int i = 0;
    char temp = '0';
    if(length != 1)
    {
        temp = n[0];
        for(i = 0; i < length - 1; i++)
            n[i] = n[i + 1];
        n[length-1] = temp;
        fun(n, length - 1);
    }
}

int main()
{
    char n[]={'a','b','c','d','e','f','g'};
    int length = sizeof(n) / sizeof(char);
    fun(n, length);
    for(int i = 0; i<length; i++)
    {
        printf("%c ", n[i]);
    }
    printf("\n");
}
