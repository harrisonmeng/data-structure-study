#include <stdio.h>
#include <stdlib.h>
#define size 5
//计算一个用三元组表示的稀疏矩阵的对角线元素之和
//
//
//把下面这个稀疏矩阵用三元组表示，然后求对角线之和
//1 0 3 0 0
//0 2 0 0 1
//0 0 0 1 0
//0 5 0 0 0
//0 0 0 0 4

typedef struct trielement
{
    int x;
    int y;
    int data;
}trielement;

typedef struct List
{
    int length;
    int width;
    trielement element[7];
}List;

int Sum(List *a, int num)
{
    int i, sum;
    sum = 0;
    for(i = 0; i < num; i++)
    {
        if((a->element[i].x - a->element[i].y == 0) || (a->element[i].x + a->element[i].y == size + 1))
        {
            sum += a->element[i].data;
        }
    }
    return sum;
}

int main()
{
    List *a = malloc(sizeof(struct List));
    a->length = a->width = 5;
    int array[5][5] = {1,0,3,0,0,0,2,0,0,1,0,0,0,1,0,0,5,0,0,0,0,0,0,0,4};
    int i,j,k, num;
    i = j = k = num = 0;
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            if(array[i][j] != 0)
            {
                a->element[k].x = i + 1;
                a->element[k].y = j + 1;
                a->element[k].data = array[i][j];
                k++;
                num++;
            }
        }
    }

    printf("%d", Sum(a, num));
    return 0;
}
