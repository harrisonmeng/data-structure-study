typedef struct LinkNodeStruct
{
	int x;
	int y;
	int data;
	LinkNodeStruct* next;
}linknode;

typedef struct LinkStackStruct
{
    int length;
    linknode* node; 
}linkstack;

void LinkStackInit(linkstack **s);
void LinkStackFree(linkstack *s);
void LinkStackPush(int m,int x,int y,linkstack *s);
linknode* LinkStackPop(linkstack *s);
