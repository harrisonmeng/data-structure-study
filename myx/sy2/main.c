#include <stdio.h>
#include <stdlib.h>

//ʵ����ջ������ջ��Ԫ�ص�����Ϊchar���ĸ��ֻ������㣬���ڴ˻��������һ������������¹��ܣ�
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
    char data[];
};

void InitStack(struct Stack *s)
{
	s=(struct Stack*)malloc(sizeof(struct Stack));
	s->top=-1;
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

void Push(char x,struct Stack *s)
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

void PrintStack(struct Stack *s)
{
	int i;
	for(i=0;i<s->length;i++)
		printf("%c",s->data[i]);
}

int main(int argc, char** argv) {
	struct Stack *s;
	s=(struct Stack*)malloc(sizeof(struct Stack));
	s->length=10;
	InitStack(s);
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
