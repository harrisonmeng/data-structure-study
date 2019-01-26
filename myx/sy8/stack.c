#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
		p->coordinate[i].x = -1;
		p->coordinate[i].y = -1;
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

void Push(coordinate c,stacktype *s)
{
    if(StackFull(s))
    {
        printf("Full stacktype!\n");
        return;
    }
    else
    {
    	s->top++;
        s->coordinate[s->top].x = c.x;
        s->coordinate[s->top].y = c.y;
	}
}

coordinate Pop(stacktype *s)
{
    coordinate e = {0};
    if(!StackEmpty(s))
    {
        e.x = s->coordinate[s->top].x;
        e.y = s->coordinate[s->top].y;
        s->coordinate[s->top].x = -1;
        s->coordinate[s->top].y = -1;
        s->top--;
    }
    return e;
}

void FreeStack(stacktype *s)
{
	free(s);
}

coordinate GetTop(stacktype *s)
{
    coordinate e = {0};

	if(s->top!=-1)
		return s->coordinate[s->top];
    else
        return e;
}

void PrintStack(stacktype *s)
{
	int i;
	for(i=s->top;i>=0;i--)
		printf("(%d,%d) ",s->coordinate[i].x, s->coordinate[i].y);
	printf("\n");
}
