#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 50

typedef struct elem
{
    int amount;
    char X,Y,Z;
    int flag;
}elemtype;

typedef struct Stack
{
    int length;
    int top;
    elemtype data[MAXSIZE];
}stacktype;

void InitStack(stacktype **s)
{
	stacktype *p;
	p=(stacktype*)malloc(sizeof(stacktype));
	p->length=MAXSIZE;
	p->top=-1;
	*s=p;
}

int StackEmpty(stacktype *s)
{
	if(s->top==-1)
    	return 1;
    return 0;
}

int StackFull(stacktype *s)
{
    if(s->length==s->top+1)
    	return 1;
    return 0;
}

void Push(elemtype x,stacktype *s)
{
    if(StackFull(s))
    {
        printf("Full stacktype!\n");
        return;
    }
    else
        s->data[++s->top] = x;
}

elemtype Pop(stacktype *s)
{
    if(!StackEmpty(s))
    {
        elemtype e;
        e = s->data[s->top];
        s->top --;
        return e;
    }
}

void FreeStack(stacktype *s)
{
	free(s);
}

elemtype GetTop(stacktype *s)
{
	if(s->top!=-1)
		return s->data[s->top];
}

void PrintStack(stacktype *s)
{
	int i;
	for(i=s->top;i>=0;i--)
		printf("%c",s->data[i]);
	printf("\n");
}

void H(int amount, char X, char Y, char Z)
{
    stacktype *s;
    elemtype e, e1, e2, e3;
    if (amount <= 0)
        return;
    InitStack(&s);
    e.amount = amount;
    e.flag = 0;
    e.X = X;
    e.Y = Y;
    e.Z = Z;
    Push(e, s);
    while(StackEmpty(s) == 0)
    {
        e = Pop(s);
        if(e.flag == 0)
        {
            e1.amount = e.amount-1;
            e1.X = e.Y;
            e1.Y = e.X;
            e1.Z = e.Z;
            if(e1.amount == 1)
                e1.flag = 1;
            else
                e1.flag = 0;
            Push(e1, s);
            e2.amount = e.amount;
            e2.X = e.X;
            e2.Y = e.Y;
            e2.Z = e.Z;
            e2.flag = 1;
            Push(e2, s);
            e3.amount = e.amount-1;
            e3.X = e.X;
            e3.Y = e.Z;
            e3.Z = e.Y;
            if(e3.amount == 1)
                e3.flag = 1;
            else
                e3.flag = 0;
            Push(e3, s);
        }
        else
            printf("plate%d:%c tower->%c tower\n", e.amount, e.X, e.Z);
    }
    FreeStack(s);
}

int main()
{
    char a = 'A';
    char b = 'B';
    char c = 'C';
    int amount = 3;
    H(amount, a, b, c);
    return 0;
}
