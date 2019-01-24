#define Maxsize 100
typedef struct Queue
{
	int data[Maxsize];
	int front,rear;
}queuetype;
void InitQueue(queuetype **q);
void FreeQueue(queuetype *q);
int QueueEmpty(queuetype *q);
int enQueue(queuetype *q,int i);
int deQueue(queuetype *q);
void OutQueue(queuetype *q);
void DisplayQueue(queuetype *q);
