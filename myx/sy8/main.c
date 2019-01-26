#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#define SIDE 6

void PrintBoard (int board[SIDE][SIDE], int side)
{
    int i,j;

    for(i = 0; i < side; i++)
    {
        for(j = 0; j < side; j++)
            printf("%c ", board[i][j] == 0 ? '.' : 'W');
        printf("\n");
    }
    printf("\n");
}

void InitBoard(int board[][SIDE])
{
    int i, j;
    for(i = 0; i < SIDE; i++)
        for(j = 0; j < SIDE; j++)
            board[i][j] = 0;
}

int Check(int board[SIDE][SIDE], coordinate c, int side)
{
    int i, j;

    i = c.x;
    j = c.y;
    while(i >= 0 && j >= 0)
    {
        if(board[j][i] == 1)
            return 1;
        i--;
        j--;
    }

    i = c.x;
    j = c.y;
    while(i < side && j >= 0)
    {
        if(board[j][i] == 1)
            return 1;
        i++;
        j--;
    }

    i = c.x;
    for(j = c.y; j < side; j++)
    {
        if(board[j][i] == 1)
            return 1;
    }
    for(j = c.y; j >= 0; j--)
    {
        if(board[j][i] == 1)
            return 1;
    }

    i = c.y;
    for(j = c.x; j < side; j++)
    {
        if(board[i][j] == 1)
            return 1;
    }
    for(j = c.x; j >= 0; j--)
    {
        if(board[i][j] == 1)
            return 1;
    }
    return 0;
}

int BoardCheck (int board[SIDE][SIDE], int side)
{
    int i, j, sum = 0;
    for(i = 0; i < side; i++)
    {
        for(j = 0; j < side; j++)
        {
            sum += board[i][j];
        }
    }
    if(sum == side)
        return 0;
    else
        return 1;
}

void QueenProblem (int board[SIDE][SIDE], int side)
{
    int j, k, i;
    stacktype *s;
    coordinate c;

    InitStack(&s);
    j = 0;
    k = 0;
    i = 0;
    c.x = 0;
    c.y = 0;
    for(j = 0; j < side; j++)
    {
        c.y = j;
        while(Check(board, c, side) != 0)
        {
            c.x = k;
            if(k == side)
            {
                board[GetTop(s).y][GetTop(s).x] = 0;
                if(GetTop(s).y == 0 && GetTop(s).x == side - 1)
                    return;
                k = Pop(s).x + 1;
                if(k == side)
                {
                    k--;
                    board[GetTop(s).y][GetTop(s).x] = 0;
                    k = Pop(s).x + 1;
                    j--;
                }
                j--;
                c.y = j;
                c.x = k;
            }
            else
                k++;
        }
        Push(c, s);
        board[c.y][c.x] = 1;
        c.x = k = 0;
        if(BoardCheck(board, side) == 0)
        {
            PrintBoard(board, side);
            InitBoard(board);
            i++;
            j = -1;
            c.x = k = i;
        }
    }
    /*j = 0;
    for(k = 0; k < side;)
    {
        c.x = k;
        c.y = j;
        if(Check(board, c, side) == 0)
        {
            Push(c, s);
            board[c.y][c.x] = 1;
            if(BoardCheck(board, side) == 0)
                PrintBoard(board, side);
            j++;
            k = 0;
            continue;
        }
        k++;
        if(k == side)
        {
            board[GetTop(s).y][GetTop(s).x] = 0;
            k = Pop(s).x + 1;
            if(StackEmpty(s) == 1)
                return;
            if(k == side)
            {
                k--;
                board[GetTop(s).y][GetTop(s).x] = 0;
                k = Pop(s).x + 1;
                j--;
            }
            j--;
        }
    }*/
}

int main()
{
    int board[SIDE][SIDE];
    int i,j;
    int side;

    side = SIDE;
    for(i = 0; i < SIDE; i++)
        for(j = 0; j < SIDE; j++)
            board[i][j] = 0;

    QueenProblem(board, side);
    return 0;
}
