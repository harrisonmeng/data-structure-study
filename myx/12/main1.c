#include <stdio.h>
#include <stdlib.h>
#define Maxsize 20
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct Queue
{
	char data[Maxsize];
	int front;
	int rear;
}queuetype;

void InitQueue(struct Queue **q)
{
	queuetype *s;
	s=(queuetype*)malloc(sizeof(queuetype));
	s->front=s->rear=0;
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

int enQueue(queuetype *q,int i)
{
	if((q->rear+1)%Maxsize==q->front)
		return 0;
	q->rear=(q->rear+1)%Maxsize;
	q->data[q->rear]=i;
	return 1;
}

char deQueue(queuetype *q)
{
	if(q->front==q->rear)
		return 0;
	q->front=(q->front+1)%Maxsize;
	return q->data[q->front];
}

void fun(queuetype *q,int length)
{
	int i,j,temp;
	for(i=0,j=length-1;i<j;++i,--j)
	{                                   //for queue, do not operate the data items directly, only enQueue() and deQueue() can be used to access the data item of queue
		temp=q->data[i];                //you can create a temporary stack for reversing the data items of queue
		q->data[i]=q->data[j];
		q->data[j]=temp;
	} 
}
int main(int argc, char** argv) {
	queuetype *q;
	int i=0;
	InitQueue(&q);
	for(i=0;i<10;i++)
		q->data[i]='a'+i; 
	q->front=9;
	q->rear=0;
	for(i=0;i<q->front+1;i++)
	{
		printf("%c,",q->data[i]);
	}
	printf("\n");
	fun(q,q->front+1);
	i=0;
	for(i=0;i<q->front+1;i++)
	{
		printf("%c,",q->data[i]);
	}
	FreeQueue(q);
	return 0;
}
