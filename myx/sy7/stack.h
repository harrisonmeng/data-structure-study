#define Maxsize 20
typedef struct Stack
{
    int length;
    int top;
    int data[Maxsize];
}stacktype;
void InitStack(stacktype **s);
int StackEmpty(stacktype *s);
int StackFull(stacktype *s);
void Push(int x,stacktype *s);
int Pop(stacktype *s);
void FreeStack(stacktype *s);
int GetTop(stacktype *s);
void PrintStack(stacktype *s);
