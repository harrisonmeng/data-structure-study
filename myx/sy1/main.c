#include <stdio.h>
#include <stdlib.h>
#define Maxisize 20 
//实现顺序栈（假设栈中元素的类型为char）的各种基本运算，并在此基础上设计一个程序，完成以下功能：
//1.初始化栈s
//2.判断栈s是否非空 
//3.依次进栈元素a, b, c, d, e
//4.判断栈s是否非空
//5.输出出栈序列
//6.判断栈s是否非空
//7.释放栈s 

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
