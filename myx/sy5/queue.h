#define Maxsize 1000 

typedef struct Queue
{
	int data[Maxsize];
	int x[Maxsize];
	int y[Maxsize];
	int front,rear;
}queuetype;

void InitQueue(queuetype **q)
void FreeQueue(queuetype *q)
int QueueEmpty(queuetype *q)
int enQueue(queuetype *q,char i)
int deQueue(queuetype *q)
void DisplayQueue(queuetype* q)
