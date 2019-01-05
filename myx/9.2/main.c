#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct Stack
{
    int length;
    int top;
    char data[10];
}StackType;

void InitStack(StackType *s)
{
	s=(StackType*)malloc(sizeof(StackType));
	s->top=-1;
}

int StackEmpty(StackType *s)
{
	if(s->top==-1)
    	return 1;
    return 0;
}

int StackFull(StackType *s)
{
    if(s->length==s->top+1)
    	return 1;
    return 0;
}

void Push(int x,StackType *s)
{
    if(StackFull(s))
    {
        printf("Full struct Stack!\n");
        return;
    }
    else
        s->data[++s->top] = x;
}

void Pop(StackType *s)
{
    if(StackEmpty(s))
    {
        printf ("Empty stack\n");
        return;
    }
    else
        s->top--;
}

void FreeStack(StackType *s)
{
	free(s);
}

int GetTop(StackType *s)
{
	if(s->top!=-1)
		return s->data[s->top];
	return -1;
}

int fun(char str[],int length)
{
	int i=0;
	int x;
	StackType *p;
	int a=1;
	InitStack(p);
	while(i<length&&a!=0)
	{
		if(str[i]=='I')
			Push(str[i],p);
		else if(str[i]=='O')
		{
			if(StackEmpty(p)==1)
				a=0;
			else
				Pop(p);
		}
		else
			a=0;
		i++;
	}
	FreeStack(p);
	return a;
}

int main(int argc, char** argv) {
	char a[]={'I','O','O','I','O','I','I','O'};
	printf("%d",fun(a,sizeof(a)));
	return 0;
}
