#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
void InitStack(stacktype **s)
{
	stacktype *p;
	int i;
	p=(stacktype*)malloc(sizeof(stacktype));
	p->length=Maxsize;
	p->top=-1;
	for(i=0;i<p->length;i++)
	{
		p->data[i] = 0;
	}
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

void Push(int x,stacktype *s)
{
    if(StackFull(s))
    {
        printf("Full stacktype!\n");
        return;
    }
    else
        s->data[++s->top] = x;
}

int Pop(stacktype *s)
{
    if(StackEmpty(s))
    {
        printf ("Empty stack\n");
        return 0;
    }
    else
    {
        char a;
        a = s->data[s->top];
        s->top--;
        return a;
    }
}

void FreeStack(stacktype *s)
{
	free(s);
}

int GetTop(stacktype *s)
{
	if(s->top!=-1)
		return s->data[s->top];
	return -1;
}

void PrintStack(stacktype *s)
{
	int i;
	for(i=s->top;i>=0;i--)
		printf("%d ",s->data[i]);
	printf("\n");
}
