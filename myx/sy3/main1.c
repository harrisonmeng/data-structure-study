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
};

void InitQueue(struct Queue *q)
{
	q=(struct Queue*)malloc(sizeof(struct Queue));
	q->front=q->rear=0;
}

void FreeQueue(struct Queue *q)
{
	free(q);
}

int QueueEmpty(struct Queue *q)
{
	return (q->front==q->rear);
}

int enQueue(struct Queue *q,char i)
{
	if((q->rear+1)%Maxsize==q->front)
		return 0;
	q->rear=(q->rear+1)%Maxsize;
	q->data[q->rear]=i;
	return 1;
}

char deQueue(struct Queue *q)
{
	int e;
	if(q->front==q->rear)
		return 0;
	q->front=(q->front+1)%Maxsize;
	return q->data[q->front];
}

void OutQueue(struct Queue *q)
{
	while(QueueEmpty(q)==0)
		printf("%c ",deQueue(q));
}

int main(int argc, char** argv) {
	struct Queue *q;
	q=(struct Queue*)malloc(sizeof(struct Queue));
	q->front=q->rear=0;
	InitQueue(q);
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
