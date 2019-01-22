#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "queue.h" 

void InitQueue(queuetype **q)
{
	queuetype *p;
	p=(queuetype*)malloc(sizeof(queuetype));
	memset(p, '.', Maxsize);
	p->front=p->rear=0;
	*q=p;
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
	q->rear=(q->rear+1)%Maxsize;
	q->data[q->rear]=i;
}

int deQueue(queuetype *q)
{
	int e;
	if(q->front==q->rear)
		return 0;
	q->front=(q->front+1)%Maxsize;
	e = q->data[q->front];
	q->data[q->front]='.';
	return e;
}

void DisplayQueue(queuetype* q)
{
	int i;
	for(i=0;i<Maxsize;i++)
	{
		printf("%c ", q->data[i]);
	}
	printf("\n");
}
