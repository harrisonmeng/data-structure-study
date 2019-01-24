#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "queue.h"

void InitQueue(queuetype **q)
{
	queuetype *p;
	p=(queuetype*)malloc(sizeof(queuetype));
	memset(p, 101, Maxsize);
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
    if (QueueEmpty(q) == 1)
    {
        printf("No patient.");
        return -1;
    }
    else
    {

        q->front=(q->front+1)%Maxsize;
        e = q->data[q->front];
        q->data[q->front]=101;
        return e;
    }
}

void OutQueue(queuetype *q)
{
    if (QueueEmpty(q) == 1)
        printf("No patient.");
    else
    {
        while(QueueEmpty(q)==0)
            printf("%d ",deQueue(q));
        printf("\n");
    }
}

void DisplayQueue(queuetype* q)
{
    if (QueueEmpty(q) == 1)
        printf("No patient.");
    else
    {
        for(int i = 0; i < Maxsize; i++)
        {
            if (q->data[i] < 20 && q->data[i] >= 0)
                printf("%d ", q->data[i]);
        }
        printf("\n");
    }
}
