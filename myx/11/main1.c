//get string from keyboard, a1a2a3...an. design a program to implement: 
//if ai is a number then enqueue ai, 
//if ai is a lowercase letter then dequeue the queue from head,
//if ai is other character then end the input, use circle queue. 

#include <stdio.h>
#include <stdlib.h>
#define Maxsize 20
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct Queue
{
	char data[Maxsize];
	int front,rear;
}QueueType;

void InitQueue(QueueType **q)            
{
	QueueType *a; 
	int i;
	a=(QueueType*)malloc(sizeof(QueueType));
	a->front=a->rear=0;
	for(i=0;i<Maxsize;i++)
		a->data[i]='0';
	*q=a;
	//use memset to initialize queue data
}

void FreeQueue(QueueType *q)
{
	free(q);
}

int QueueEmpty(QueueType *q)
{
	return (q->front==q->rear);
}

int enQueue(QueueType *q,char i)
{
	if((q->rear+1)%Maxsize==q->front)
		return 0;
	q->rear=(q->rear+1)%Maxsize;
	q->data[q->rear]=i;
	return 1;
}

char deQueue(QueueType *q)
{
	if(q->front==q->rear)
		return 0;
	q->front=(q->front+1)%Maxsize;
	return q->data[q->front];
}



int main(int argc, char** argv) {
	QueueType *q; 
	char a=0;
	InitQueue(&q);
	
	while(1)
	{
		                       
		printf("enter:");            
		scanf("%c",&a);
		
		if(a<='9'&&a>='0')            
			enQueue(q,a);	//After this line is executed the program jumps to 'return 0;' weirdly  
		else if((a>='a'&&a<='z')&&(QueueEmpty(q)==0))
			deQueue(q);
		else
			break;
		a=0;
	}
	FreeQueue(q);
	return 0;
}
