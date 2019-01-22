typedef struct LinkNodeStruct
{
	int x;
	int y;
	LinkNodeStruct* next;
}linknode;

void LinkStackInit(void **s);
void LinkStackFree(void *s);
void LinkStackPush(int x, int y, void *s);
void PrintStack(void *s); 
linknode* LinkStackPop(void *s);
