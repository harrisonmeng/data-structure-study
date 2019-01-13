#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define Maxsize 20
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct Queue
{
	char data[Maxsize];
	int front;
	int rear;
}queuetype;

typedef struct  DLinkNode{
	DLinkNode *pre;
	DLinkNode *next;
	int data;
	int freq;
}DLinkNode;

void InitQueue(struct Queue **q)
{
	queuetype *s;
	s=(queuetype*)malloc(sizeof(queuetype));
	s->front=s->rear=0;
	memset(s->data, 0, Maxsize);  
	*q=s;

}

void FreeQueue(queuetype *q)
{
	free(q);
}

int QueueEmpty(queuetype *q)
{
	return (q->front==q->rear);
}

int enQueue(queuetype *q,char i)
{
	if((q->rear+1)%Maxsize==q->front)
		return 0;
	q->data[q->rear]=i;
	q->rear=(q->rear+1)%Maxsize;
	return 1;
}

char deQueue(queuetype *q)
{
	char i=0;
	if(q->front==q->rear)
		return 0;
	i=q->data[q->front];
	q->front=(q->front+1)%Maxsize;
	return i;
}

typedef struct Stack
{
    int length;
    int top;
    char data[Maxsize];
}stacktype;

void InitStack(stacktype **s)
{
	stacktype *p;
	p = (stacktype*)malloc(sizeof(stacktype));
	p->top = -1;
	p->length = Maxsize;
	memset(p->data, 0, Maxsize);
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

int Pop(stacktype *s)
{
	int i;
    if(StackEmpty(s))
    {
        printf ("Empty stack\n");
        return 0;
    }
    else
	{
		i=s->data[s->top];
	   	s->top--;
		return i;
	}
}

void FreeStack(stacktype *s)
{
	free(s);
}

void DisplayQueue(queuetype *q)
{
	int i=q->front;
	while(i!=q->rear)              
	{                              
		printf("%c,",q->data[i]);  
		i=(i+1)%Maxsize;           
	}     
	printf("\n");
}

int main(int argc, char** argv) {
	queuetype *q;
	int i=0;
	InitQueue(&q);
	for(i=0;i<10;i++)
		enQueue(q,'a'+i);
	DisplayQueue(q);
	stacktype *s;
	InitStack(&s);
	while(QueueEmpty(q)==0)
	{
		Push(deQueue(q),s);
	}
	while(StackEmpty(s)==0)     //do not use for-loop, just use pop() until stack is empty
	{
		enQueue(q,Pop(s));
	}
	DisplayQueue(q);
	FreeQueue(q);   
	FreeStack(s);                // stack needs to be freed as well
	return 0;
}

