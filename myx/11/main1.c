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

void InitQueue(QueueType *q)                 //input parameter should be **
{
	q=(QueueType*)malloc(sizeof(QueueType));
	q->front=q->rear=0;
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

//no need this function, merge it into main()
void fun(QueueType *q)
{
	char a;
	while(1)
	{
		a=100;                       
		printf("enter:");            
		scanf("%c",&a);
		
		if(a<=57&&a>=48)             //for better readable, use a <= '9' && a >= '0' 
			enQueue(q,a);
		else if((a>=97&&a<=122)&&(QueueEmpty(q)==0))
			deQueue(q);
		else
			break;
	}
}
int main(int argc, char** argv) {
	QueueType *q;
	char a[100]; 
	
	
	q=(QueueType*)malloc(sizeof(QueueType));  //use InitQueeu
	q->front=q->rear=0;
	fun(q);
	FreeQueue(q);
	return 0;
}
