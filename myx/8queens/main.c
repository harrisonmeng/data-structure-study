#include <stdio.h>
#include <stdlib.h>
#define SIZE 8

int sum = 0;

void PrintBoard(int board[SIZE][SIZE])
{
    int i, j;
    for(i = 0; i < SIZE; i++)
    {
        for(j = 0; j < SIZE; j++)
        {
            switch (board[i][j])
            {
                case 0:
                    printf("¡Á");
                    continue;
                case 1:
                    printf("ºó");
                    continue;
            }
        }
        printf("\n");
    }
    printf("\n");
    return;
}

int Check(int board[SIZE][SIZE], int x, int y)
{
    int i = x;
    int j = y;

    if(i >= SIZE || j >= SIZE)
        return 0;

    j = y;
    for(i = 0; i < SIZE; i++)
    {
        if(board[i][j] == 1)
            return 0;
    }

    i = x;
    j = y;
    while(i >= 0 && j >= 0)
    {
        if(board[i][j] == 1)
            return 0;
        i--;
        j--;
    }

    i = x;
    j = y;
    while(i >= 0 && j < SIZE)
    {
        if(board[i][j] == 1)
            return 0;
        i--;
        j++;
    }

    i = x;
    j = y;
    while(i < SIZE && j >= 0)
    {
        if(board[i][j] == 1)
            return 0;
        i++;
        j--;
    }

    i = x;
    j = y;
    while(i < SIZE && j < SIZE)
    {
        if(board[i][j] == 1)
            return 0;
        i++;
        j++;
    }
    return 1;
}

void InitBoard(int board[SIZE][SIZE])
{
    int i,j;

    for(i = 0; i < SIZE; i++)
    {
        for(j = 0; j < SIZE; j++)
        {
            board[i][j] = 0;
        }
    }
}

int Solve(int board[SIZE][SIZE], int x)
{
    int i;

    for(i = 0; i < SIZE; i++)
    {
        if(Check(board, x, i) == 1)
        {
            board[x][i] = 1;
            if(x == SIZE-1)
            {
                sum++;
                printf("%d:\n", sum);
                PrintBoard(board);
                board[x][i] = 0;
                return;
            }
            else
            {
                Solve(board, x+1);
                board[x][i] = 0;
            }
        }
    }
    return;
}

int main()
{
    int board[SIZE][SIZE] = {0};
    //PrintBoard(board);
    Solve(board, 0);
    return 0;
}
