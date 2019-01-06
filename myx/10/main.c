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

void InitStack(stacktype **s)
{
	stacktype *p;
	p = (stacktype*)malloc(sizeof(stacktype));
	p->top = -1;
	p->length = STACK_SIZE;
	memset(p->data, 0, STACK_SIZE);
	*s = p;
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

void Pop(stacktype *s)
{
    if(StackEmpty(s))
    {
        printf ("Empty stack\n");
        return;
    }
    else
        s->top--;
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

int fun(char str[],int length)
{
	stacktype *a;
	int i=0;
	InitStack(&a);
	while(i<length)
	{
		switch (str[i])
		{
			case '(' :
				Push(str[i], a);
				break;
			case '[' :
				Push(str[i], a);
				break;
			case '{' :
				Push(str[i], a);
				break;
			case ')' :
				if (GetTop(a) == '(' && StackEmpty(a) == 0)
					Pop(a);
				else
					return 0;
				break;
			case ']' :
				if (GetTop(a) == '[' && StackEmpty(a) == 0)
					Pop(a);
				else
					return 0;
				break;
			case '}' :
				if (GetTop(a) == '{' && StackEmpty(a) == 0)
					Pop(a);
				else
					return 0;
				break;
		}
		i++;
	}
	if(StackEmpty(a)==0)
		return 1; 
	FreeStack(a);
	return 1;
}

int main(int argc, char** argv)
{
	char a[]="{3+5x[23-(6+7)+10}";
	printf("%d",fun(a,sizeof(a)));	
	return 0;
}
