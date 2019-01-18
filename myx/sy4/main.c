#include <stdio.h>
#include <stdlib.h> 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//ʵ�����ӵĸ��ֻ���������㷨
//ʵ�����ӣ�Ԫ������Ϊchar���ĸ��ֻ������㣬���ڴ˻�������Ƴ���������¹���:
//1.��ʼ������q
//2.�ж�����q�Ƿ�ǿ�
//3.���ν�����Ԫ��a, b, c
//4.����һ��Ԫ�أ������Ԫ��
//5.���ν�����Ԫ��d, e, f
//6.�����������
//7.�ͷ����� 

typedef struct qnode
{
	char data;
	struct qnode *next;
}queuenode;                                    //fix this compiler warning by giving name for this typedef struct

typedef struct qhead
{
	struct qnode *front;
	struct qnode *rear;
}linkqueue;

int QueueEmpty(struct qhead *q)
{
	return(q->front==NULL);
}

void InitQueue(linkqueue **q)
{
	linkqueue *p;
	p=(linkqueue *)malloc(sizeof(linkqueue));
	p->front=NULL;
	p->rear=NULL;
	*q=p;
}

void enQueue(struct qhead *q,char i)
{
	struct qnode *t;
	if(QueueEmpty(q)==1)
	{
		q->front=(struct qnode*)malloc(sizeof(struct qnode));
		q->front->data=i;
		q->front->next=NULL;
		q->rear=q->front;
	}
	else
	{
		t=q->rear;
		q->rear=(struct qnode*)malloc(sizeof(struct qnode));
		q->rear->data=i;
		q->rear->next=NULL;
		t->next=q->rear;
	}
}

char deQueue(struct qhead *q)
{
	struct qnode *t;
	char out;
	if(QueueEmpty(q)==1)
		return 0;
	t=q->front;
	out=q->front->data;
	if(q->front==q->rear)
		q->front=q->rear=NULL;
	else
		q->front=q->front->next;
	free(t);
	return out;
}

void OutQueue(struct qhead *q)
{
	struct qnode *t;
	while(QueueEmpty(q)==0)
	{
		t=NULL;
		t=q->front;
		printf("%c ",q->front->data);
		q->front=q->front->next;                      
	}
}

void FreeQueue(struct qhead *q)
{
	struct qnode *t;
	while(QueueEmpty(q)==0)
	{
		t=NULL;
		t=q->front;
		q->front=q->front->next;
		free(t);
	}
	q->front=q->rear=NULL;
	free(q);
}

int main(int argc, char** argv) {
	struct qhead *q;
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
