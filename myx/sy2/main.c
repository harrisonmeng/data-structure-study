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
	char data;
	struct Stack *next;
}stacktype;

typedef struct LinkStack
{
	stacktype *top;
}linkstack;

void InitLinkStack(linkstack **s)
{
	linkstack *p;
	p=(linkstack *)malloc(sizeof(linkstack));
	p->top=NULL;
	*s=p;
}

void Push(char x,linkstack *s)
{
	stacktype *p;
	p=(stacktype *)malloc(sizeof(stacktype));
	p->data=x;
	p->next=s->top;
	s->top=p;
}

int LinkStackEmpty(linkstack *s)
{
	return s->top==NULL?0:1;
}

char Pop(linkstack *s)
{
	if(LinkStackEmpty(s)!=0)
	{
		stacktype *p;
		char x;
		p=s->top;
		x=p->data;
		s->top=p->next;
		free(p);
		return x;
	}	
	return 0;
}

void PrintStack(linkstack *s)
{
	stacktype *p=s->top;
	while(p!=NULL)
	{
		printf("%c",p->data);
		p=p->next;
	}
	printf("\n");
}

int main()
{
	linkstack *s;
	InitLinkStack(&s);
	printf("%d\n",LinkStackEmpty(s));
	Push('a',s);
	Push('b',s);
	Push('c',s);
	Push('d',s);
	Push('e',s);
	printf("%d\n",LinkStackEmpty(s));
	PrintStack(s);
	printf("%d\n",LinkStackEmpty(s));
	free(s);
}
