#define Maxsize 1000
typedef struct Coordinate
{
    int x;
    int y;
}coordinate;

typedef struct Stack
{
    int length;
    int top;
    coordinate  coordinate[Maxsize];
}stacktype;

void InitStack(stacktype **s);
void FreeStack(stacktype *s);
void Push(coordinate c, stacktype *s);
coordinate Pop(stacktype *s);
coordinate GetTop(stacktype *s);
void PrintStack(stacktype *s);
int StackEmpty(stacktype *s);
