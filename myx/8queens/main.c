#include <stdio.h>
#include <stdlib.h>
#define SIZE 7

void PrintBoard(int board[][SIZE])
{
    int i, j;
    for(i = 0; i < 8; i++)
    {
        for(j = 0; j < 8; j++)
        {
            switch (board[i][j])
            {
                case 0:
                    printf("+");
                    continue;
                case 1:
                    printf("Q");
                    continue;
            }
        }
        printf("\n");
    }
    printf("\n");
    return;
}

int Check(int board[][SIZE], int x, int y)
{
    int i = x;
    int j = y;

    if(i > SIZE || j > SIZE)
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
    while(i >= 0 && j <= SIZE)
    {
        if(board[i][j] == 1)
            return 0;
        i--;
        j++;
    }

    i = x;
    j = y;
    while(i <= SIZE && j >= 0)
    {
        if(board[i][j] == 1)
            return 0;
        i++;
        j--;
    }

    i = x;
    j = y;
    while(i <= SIZE && j <= SIZE)
    {
        if(board[i][j] == 1)
            return 0;
        i++;
        j++;
    }
    return 1;
}

void InitBoard(int board[][SIZE])
{
    int i,j;

    for(i = 0; i <= SIZE; i++)
    {
        for(j = 0; j <= SIZE; j++)
        {
            board[i][j] = 0;
        }
    }
}

int Solve(int board[][SIZE], int x, int y)
{
    int i = 0;
    int j = 0;
    int prep;

    if(Check(board, x, y) == 1)
    {
        board[x][y] = 1;
        PrintBoard(board);
        if(x == SIZE)
        {
            PrintBoard(board);
            for(j = 0; j <= SIZE; j++)
            {
                if(board[0][j] == 1)
                {
                    if(j != SIZE)
                    {
                        prep = j;
                        InitBoard(board);
                        Solve(board, prep + 1, 0);
                    }
                    else
                        return;
                }
            }
        }
        else
            Solve(board, x+1, 0);
    }
    else
    {
        if(y >= SIZE)
        {
            if(x == 0)
                return;
            for(j = 0; j <= SIZE; j++)
            {
                if(board[x-1][j] == 1)
                {
                    prep = j;
                    board[x-1][j] = 0;
                    PrintBoard(board);
                    Solve(board, x-1, j+1);
                }
            }
        }
        else
        {
            Solve(board, x, y+1);
        }
    }
}

int main()
{
    int board[8][8] = {0};
    PrintBoard(board);
    Solve(board, 0, 0);
    return 0;
}
