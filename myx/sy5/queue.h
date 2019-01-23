#define Maxsize 10000
typedef struct data
{
	int x;
	int y;
	int parent;
	int tag;
}datatype;

typedef struct Queue
{
	datatype info[Maxsize];
	int front,rear;
}queuetype;

void InitQueue(queuetype **q);
void FreeQueue(queuetype *q);
int QueueEmpty(queuetype *q);
int enQueue(queuetype *q, int x, int y, int parent, int tag);
datatype deQueue(queuetype *q);
void OutQueue(queuetype *q);
