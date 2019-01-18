#include <stdio.h>
#include <stdlib.h>
#define Maxsize 20
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//ʵ�ֻ��ζ��еĸ��ֻ���������㷨
//ʵ�ֻ��ζ��У�Ԫ������Ϊchar���ĸ��ֻ������㣬���ڴ˻��������һ������������¹��ܣ� 
//1.��ʼ������q
//2.�ж϶���q�Ƿ�ǿ�
//3.���ν���Ԫ��a, b, c
//4.����һ��Ԫ�أ������Ԫ��
//5.���ν���Ԫ��d, e, f
//6.�����������
//7.�ͷŶ��� 

typedef struct Queue
{
	char data[Maxsize];
	int front,rear;
}queuetype;

void InitQueue(queuetype **q)
{
	queuetype *p;
	p=(queuetype*)malloc(sizeof(queuetype));
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
	int e;
	if(q->front==q->rear)
		return 0;
	q->front=(q->front+1)%Maxsize;
	return q->data[q->front];
}

void OutQueue(queuetype *q)
{
	while(QueueEmpty(q)==0)
		printf("%c ",deQueue(q));
}

int main(int argc, char** argv) {
	queuetype *q;
	InitQueue(&q);
	printf("%d\n",QueueEmpty(q));
	enQueue(q,'a');
	enQueue(q,'b');
	enQueue(q,'c');
	printf("%c\n",deQueue(q));
	enQueue(q,'d');
	enQueue(q,'e');
	enQueue(q,'f');
	OutQueue(q);
	FreeQueue(q);
	return 0;
}
