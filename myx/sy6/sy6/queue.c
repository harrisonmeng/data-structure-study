#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "queue.h"

void InitQueue(queuetype **q)
{
	queuetype *p;
	p=(queuetype*)malloc(sizeof(queuetype));
	memset(p, -1, Maxsize);
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

int enQueue(queuetype *q,int i)
{
	if((q->rear+1)%Maxsize==q->front)
		return 0;
	q->rear=(q->rear+1)%Maxsize;
	q->data[q->rear]=i;
	return 1;
}

int deQueue(queuetype *q)
{
	int e;
	if(q->front==q->rear)
		return 0;
	q->front=(q->front+1)%Maxsize;
	e = q->data[q->front];
	q->data[q->front]=0;
	return e;
}

void OutQueue(queuetype *q)
{
	while(QueueEmpty(q)==0)
		printf("%d ",deQueue(q));
    printf("\n");
}

void DisplayQueue(queuetype* q)
{
    int i = 0;
	while(q->data[i] != -1 && i < Maxsize);
	{
		printf("%d ", q->data[i]);
		i++;
	}
	printf("\n");
}
