//1. 生成以下两个稀疏矩阵的三元组 a 和 b，矩阵转置、加法、乘法去百度查
//
// 1 0 3 0                3 0 0 0
// 0 1 0 0                0 4 0 0
// 0 0 1 0                0 0 1 0
// 0 0 1 1                0 0 0 2
//
//2. 输出a转置矩阵的三元组
//3. 输出a+b的三元组
//4. 输出axb的三元组


#include <stdio.h>
#include <stdlib.h>
#define SIZE 4
#define Maxsize 5

typedef struct triple
{
    int x;
    int y;
    int data;
}triple;

typedef struct List
{
    int length;
    int width;
    int num;
    triple element[Maxsize];
}List;

void MatrixTran(List *a, List *b)
{
    int i;
    i = 0;
    b->length = a->width;
    b->width = a->length;
    b->num = a->num;
    for(i = 0; i < a->num; i++)
    {
        b->element[i].y = a->element[i].x;
        b->element[i].x = a->element[i].y;
        b->element[i].data = a->element[i].data;
    }
}

void *CreateList(int a[][SIZE], List *p)
{
    p->length = SIZE;
    p->width = SIZE;

    int i,j,k, num;
    i = j = k = num = 0;
    for(i = 0; i < SIZE; i++)
    {
        for(j = 0; j < SIZE; j++)
        {
            if(a[i][j] != 0)
            {
                p->element[k].x = i + 1;
                p->element[k].y = j + 1;
                p->element[k].data = a[i][j];
                k++;
                num++;
            }
        }
    }
    p->num = num;
}

void PrintMatrix(List *A)
{
    int i,j,k,f;
    i = j = k = f = 0;
    for(i = 0; i < SIZE; i++)
    {
        for(j = 0; j < SIZE; j++)
        {
            for(k = 0; k < A->num; k++)
            {
                if(A->element[k].x == i+1 && A->element[k].y == j+1)
                {
                    printf("%d", A->element[k].data);
                    f = 1;
                    break;
                }
            }
            if(f == 0)
            {
                printf("0");
            }
            f = 0;
        }
        printf("\n");
    }
    printf("\n");
}

void MatrixAdd(List *a, List *b, List *apb)
{
    int i,j,k,f;
    i = j = f = k = 0;
    for(i = 0; i < a->num; i++)
    {
        apb->element[i].x = a->element[i].x;
        apb->element[i].y = a->element[i].y;
        apb->element[i].data = a->element[i].data;
    }
    for(j = 0; j < b->num; j++)
    {
        for(k = 0; k < a->num; k++)
        {
            if(a->element[k].x == b->element[j].x && a->element[k].y == b->element[j].y)
            {
                apb->element[k].data += b->element[j].data;
                f = 1;
                break;
            }
        }
        if(f == 0)
        {
            i++;
            apb->element[i].x = b->element[j].x;
            apb->element[i].y = b->element[j].y;
            apb->element[i].data = b->element[j].data;
        }
        f = 0;
    }
    apb->length = a->length;
    apb->width = b->width;
    apb->num = a->num > b->num ? a->num : b->num;
}

int find(List *a, int x, int y)
{
	int i;
	for(i = 0; i < a->num; i++)
    {
		if (a->element[i].x == x && a->element[i].y == y)
		{
			return a->element[i].data;
		}
	}
	return 0;
}

void MatrixMultiply(List *a, List *b, List *amb)
{
	int sum,num,i,j,k;
	sum = num = i = j = k = 0;
    for(i = 0; i < a->length; i++)
    {
        for(j = 0; j < b->width; j++)
        {
            sum = 0;
            for(k = 0; k < a->width; k++)
            {
                sum = sum + find(a, i, k) * find(b, k, j);
            }
            if(sum != 0)
            {
                amb->element[num].data = sum;
                amb->element[num].x = i;
                amb->element[num].y = j;
                num++;
            }
        }
    }
    amb->length = a->length;
    amb->width = b->width;
    amb->num = num;
}

int main()
{
    int a[SIZE][SIZE] = {1,0,3,0,0,1,0,0,0,0,1,0,0,0,1,1};
    int b[SIZE][SIZE] = {3,0,0,0,0,4,0,0,0,0,1,0,0,0,0,2};
    List *A,*B,*TA,*TB,*ApB,*AmB;
    A = (List *)malloc(sizeof(List));
    B = (List *)malloc(sizeof(List));
    TA = (List *)malloc(sizeof(List));
    TB = (List *)malloc(sizeof(List));
    ApB = (List *)malloc(sizeof(List));
    AmB = (List *)malloc(sizeof(List));

    CreateList(a, A);
    CreateList(b, B);
    PrintMatrix(A);
    PrintMatrix(B);

    MatrixTran(A, TA);
    PrintMatrix(TA);
    MatrixTran(B, TB);
    PrintMatrix(TB);

    MatrixAdd(A,B,ApB);
    PrintMatrix(ApB);

    MatrixMultiply(A, B, AmB);
    PrintMatrix(AmB);
    return 0;
}
