typedef struct LinkNodeStruct
{
	int number;
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
void LinkStackPush(int m,int n,linkstack *s);
linknode* LinkStackPop(linkstack *s);
