#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define STACK_SIZE 20

typedef struct Stack
{
    int length;
    int top;
    char data[STACK_SIZE];
}stacktype;

void InitStack(struct Stack *s)
{
	s = (struct Stack*)malloc(sizeof(struct Stack));
	s->top = -1;
	s->length = STACK_SIZE;
}

int StackEmpty(struct Stack *s)
{
	if(s->top==-1)
    	return 1;
    return 0;
}

int StackFull(struct Stack *s)
{
    if(s->length==s->top+1)
    	return 1;
    return 0;
}

void Push(int x,struct Stack *s)
{
    if(StackFull(s))
    {
        printf("Full struct Stack!\n");
        return;
    }
    else
        s->data[++s->top] = x;
}

void Pop(struct Stack *s)
{
    if(StackEmpty(s))
    {
        printf ("Empty stack\n");
        return;
    }
    else
        s->top--;
}

void FreeStack(struct Stack *s)
{
	free(s);
}

int GetTop(struct Stack *s)
{
	if(s->top!=-1)
		return s->data[s->top];
	return -1;
}

int fun(char str[],int length)
{
	struct Stack *a,*b,*c;
	int i=0,e;
	InitStack(a);
	InitStack(b);
	InitStack(c);
	while(i<length&&!StackEmpty(a)&&!StackEmpty(b)&&!StackEmpty)
	{
		if(str[i]=='('||str[i]=='['||str[i]=='{')
			Push(str[i],a);
		if(StackEmpty(a)==0)
		{
			e=GetTop(a);
			if(e==str[i])
			{
				Pop(a);
			}
		}
		else
			return 0;
		i++;
	}
	if(StackEmpty(a)==0)
		return 0; 
	FreeStack(a);
	return 1;
}

int main(int argc, char** argv)
{
	char a[]="{3+5x[23-(6+7)]+10}";
	printf("%d",fun(a,sizeof(a)));	
	return 0;
}
