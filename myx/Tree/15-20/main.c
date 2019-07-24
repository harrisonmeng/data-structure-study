#include <stdio.h>
#include <stdlib.h>
#define Maxsize 20

typedef struct BTNode
{
    struct BTNode *lchild;
    struct BTNode *rchild;
    char data;
}BTNode;

//15
int KLevel(BTNode *b, int k)
{
    if(b == NULL)
        return 0;
    if(k-1 == 0)
        return 1;
    return KLevel(b->lchild, k-1) + KLevel(b->rchild, k-1);
}

//16
int IfBrother(BTNode *b, char x, char y)
{
    if(b->lchild == NULL || b->rchild == NULL)
        return 0;
    if(b->lchild->data == x && b->rchild->data == y || b->lchild->data == y && b->rchild->data == x)
        return 1;
    return IfBrother(b->lchild, x, y) || IfBrother(b->rchild, x, y);
}

//17
void FindXChild(BTNode *b, char x, int tag)
{
    if(b == NULL)
        return;
    if(tag == 1)
        printf("%c ", b->data);
    if(b->data == x)
        tag = 1;
    FindXChild(b->lchild, x, tag);
    FindXChild(b->rchild, x, tag);
}

//18
void ExchangeBranch(BTNode *b)
{
    BTNode *p;
    p = b->rchild;
    b->rchild = b->lchild;
    b->lchild = p;
}

//19
int IfSimilar(BTNode *a, BTNode *b)
{
	if(a == NULL || b == NULL)
		return (a == b)? 1 : 0;
	if(a->data != b->data)
		return 0;
	return IfSimilar(a->lchild, b->lchild) && IfSimilar(a->rchild, b->rchild) || IfSimilar(a->lchild, b->rchild) && IfSimilar(a->rchild, b->lchild);
}

//20


int main()
{
    BTNode *a;
    a = (BTNode*)malloc(sizeof(BTNode));
    a->data = '1';
    a->lchild = (BTNode*)malloc(sizeof(BTNode));
    a->lchild->data = '2';
    a->rchild = (BTNode*)malloc(sizeof(BTNode));
    a->rchild->data = '3';
    a->lchild->lchild = (BTNode*)malloc(sizeof(BTNode));
    a->lchild->lchild->data = '4';
    a->lchild->rchild = (BTNode*)malloc(sizeof(BTNode));
    a->lchild->rchild->data = '5';
    a->rchild->lchild = NULL;
    a->rchild->rchild = NULL;
    a->lchild->lchild->lchild = NULL;
    a->lchild->lchild->rchild = NULL;
    a->lchild->rchild->lchild = NULL;
    a->lchild->rchild->rchild = NULL;
    printf("%d\n", KLevel(a, 2));
    printf("%d\n", IfBrother(a, '4', '5'));
    FindXChild(a, '2', 0);
    printf("\n");
    ExchangeBranch(a);
    printf("%c\n", a->rchild->data);
    printf("%d\n", IfSimilar(a->lchild, a->rchild));
    return 0;
}
