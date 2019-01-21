typedef struct LinkNodeStruct
{
	int x;
	int y;
	char Data;
	LinkNodeStruct* Next;
}LinkNode;

typedef struct LinkStackStruct
{
    int length;
    LinkNode* node; 
}LinkStack;

void LinkStackInit(LinkStack **s);
void LinkStackFree(LinkStack *s);
void LinkStackPush(LinkNode* node, LinkStack *s);
LinkNode* LinkStackPop(LinkStack *s);
