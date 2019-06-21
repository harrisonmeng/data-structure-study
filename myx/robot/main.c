#include <stdio.h>
#include <stdlib.h>

void fun(int maze, int starty, int startx, int endy, int endx)
{
    int m = starty, n = startx;
    if(m == endy && n == endx)
    {
        printf("(%d,%d) ", m, n);
        printf("\n");
        return;
    }
    else
    {
        if(m < endy)
        {
            printf("(%d,%d) ", m, n);
            fun(maze, m+1, n, endy, endx);
        }

        if(n < endx)
        {
            printf("(%d,%d) ", m, n);
            fun(maze, m, n+1, endy, endx);
        }
    }
}

int main()
{
    int maze[2][5]={0};
    fun(maze,1,1,2,5);
    return 0;
}
