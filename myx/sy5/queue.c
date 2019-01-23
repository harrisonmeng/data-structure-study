#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "queue.h" 
void InitQueue(queuetype **q)
{
	queuetype *p;
	p = (queuetype *)malloc(sizeof(queuetype));
	p->front = p->rear = 0;
	memset(p->info, 0, sizeof(p->info));
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

int enQueue(queuetype *q, int x, int y, int parent, int tag)
{
	if((q->rear+1)%Maxsize==q->front)
		return 0;
	q->info[q->rear].x = x;
	q->info[q->rear].y = y;
	q->info[q->rear].parent = parent;
	q->info[q->rear].tag = tag;
	q->rear=(q->rear+1)%Maxsize;
	return 1;
}

datatype deQueue(queuetype *q)
{
	datatype e;
	if(q->front != q->rear)
	{
		e.parent = q->info[q->front].parent;
		e.x = q->info[q->front].x;
		e.y = q->info[q->front].y;
		e.tag = q->info[q->front].tag;
		q->front=(q->front+1)%Maxsize;
		return e;
	}
}

void OutQueue(queuetype *q)
{
	datatype e;
	e = deQueue(q);
	while(QueueEmpty(q)==0)
		printf("(%d,%d) ", e.x, e.y);
}
