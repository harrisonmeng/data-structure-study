#define Maxsize 1000 

typedef struct Stack
{
    int length;
    int top;
    char data[Maxsize];
    int number[Maxsize];
}stacktype;

void InitStack(stacktype **s);
void FreeStack(stacktype *s);
void Push(char x,int n,stacktype *s);
void Pop(stacktype *s);
int GetTop(stacktype *s); 
void PrintStack(stacktype *s);
