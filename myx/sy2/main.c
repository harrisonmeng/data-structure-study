#include <stdio.h>
#include <stdlib.h>

//实现链栈（假设栈中元素的类型为char）的各种基本运算，并在此基础上设计一个程序，完成以下功能：
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
