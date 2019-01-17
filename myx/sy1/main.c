#include <stdio.h>
#include <stdlib.h>
#define Maxisize 20 
//ʵ��˳��ջ������ջ��Ԫ�ص�����Ϊchar���ĸ��ֻ������㣬���ڴ˻��������һ������������¹��ܣ�
//1.��ʼ��ջs
//2.�ж�ջs�Ƿ�ǿ� 
//3.���ν�ջԪ��a, b, c, d, e
//4.�ж�ջs�Ƿ�ǿ�
//5.�����ջ����
//6.�ж�ջs�Ƿ�ǿ�
//7.�ͷ�ջs 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct Stack
{
    int length;
    int top;
    char data[Maxsize];
}stacktype;

void InitStack(stacktype **s)
{
	stacktype *p;
	int i;
	p=(stacktype*)malloc(sizeof(stacktype));
	p->length=10; 
	p->top=-1;
	for(i=0;i<p->length;i++)
	{
		p->data[i]='0';
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

void Push(char x,stacktype *s)
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

void PrintStack(stacktype *s)
{
	int i;
	for(i=s->top;i>=0;i--)
		printf("%c",s->data[i]);
	printf("\n");
}

int main(int argc, char** argv) {
	stacktype *s;
	InitStack(&s);
	printf("%d\n",StackEmpty(s));
	Push('a',s);
	Push('b',s);
	Push('c',s);
	Push('d',s);
	Push('e',s);
	printf("%d\n",StackEmpty(s));
	PrintStack(s);
	printf("%d\n",StackEmpty(s));
	FreeStack(s);
	return 0;
}
