#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define Maxsize 20
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//实现环形队列的各种基本运算的算法
//实现环形队列（元素类型为char）的各种基本运算，并在此基础上设计一个程序，完成以下功能： 
//1.初始化队列q
//2.判断队列q是否非空
//3.依次进队元素a, b, c
//4.出队一个元素，输出该元素
//5.依次进队元素d, e, f
//6.输出出队序列
//7.释放队列 

typedef struct Queue
{
	char data[Maxsize];
	int front,rear;
}queuetype;

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
	return 1;
}

char deQueue(queuetype *q)
{
	char e;
	if(q->front==q->rear)
		return 0;
	q->front=(q->front+1)%Maxsize;
	e = q->data[q->front];
	q->data[q->front]='.';
	return e;
}

void OutQueue(queuetype *q)
{
	while(QueueEmpty(q)==0)
		printf("%c ",deQueue(q));
}

void DisplayQueue(queuetype* q)
{
	for(int i=0;i<Maxsize;i++)
	{
		printf("%c ", q->data[i]);
	}
	printf("\n");
}


int main(int argc, char** argv) {
	queuetype *q;
	InitQueue(&q);

    enQueue(q,'a');
	enQueue(q,'b');
	enQueue(q,'c');
	enQueue(q,'d');
	enQueue(q,'e');
	enQueue(q,'f');	

    for(int i=0;i<20;i++)
    {
    	DisplayQueue(q);
    	enQueue(q,'g'+i);
		deQueue(q);

	}

	FreeQueue(q);
	return 0;
}
