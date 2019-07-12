//编写程序用递归方法输出以下螺旋方阵（按顺时针方向旋进）
//  1  2  3  4  5
// 16 17 18 19  6
// 15 24 25 20  7
// 14 23 22 21  8
// 13 12 11 10  9

#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

void spiral(int matrix[][SIZE], int start, int num)
{
    if(matrix[start][start] != 0)
        return;
    if(2 * start + 1 == SIZE)
    {
        matrix[start][start] = SIZE * SIZE;
        return;
    }

    int i,j;
    i = j = 0;
    i = start;
    for(j = start; j < SIZE - start - 1; j++)
    {
        matrix[i][j] = num++;
    }
    j = SIZE - 1 - start;
    for(i = start; i < SIZE - start - 1; i++)
    {
        matrix[i][j] = num++;
    }
    i = SIZE - start - 1;
    for(j = SIZE - start - 1; j > start; j--)
    {
        matrix[i][j] = num++;
    }
    j = start;
    for(i = SIZE - start - 1; i > start; i--)
    {
        matrix[i][j] = num++;
    }
    spiral(matrix, start+1, num++);
    //print(matrix);
}

void print(int matrix[][SIZE])
{
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
            printf("\t%d",matrix[i][j]);
        printf("\n");
    }
}

int main()
{
    int matrix[SIZE][SIZE] = {0};
    spiral(matrix, 0, 1);
    print(matrix);
    return 0;
}
