#include <stdio.h>
#include <stdlib.h>
#define Maxsize 20

typedef struct BTNode
{
    struct BTNode *lchild;
    struct BTNode *rchild;
    int data;
}BTNode;

void TreeToNode(BTNode *b, char *a, int i)
{
    if(b == NULL)
    {
        a[i] = '#';
    }
    else
    {
        a[i] = b->data;
        TreeToNode(b->lchild, a, 2 * i);
        TreeToNode(b->rchild, a, 2 * i + 1);
    }
}

int Leaf(char *n, int i)
{
    int left,right,num;
    left = right = num = 0;
    if(i >= Maxsize)
        return 0;
    if(n[i]!='#')
    {
        if(n[2 * i] == '#' && n[2 * i + 1] == '#')
            num++;
        else
        {
            left = Leaf(n, 2*i);
            right = Leaf(n, 2*i+1);
        }
        return left+right+num;
    }
    else
        return 0;
}

int FindSingle(BTNode *a)
{
    int n = 0;
    if(a == NULL)
        return 0;
    if(a->lchild == NULL && a->rchild != NULL || a->lchild != NULL && a->rchild == NULL)
        n = 1;
    return FindSingle(a->lchild) + FindSingle(a->rchild) +n;
}

char FindMin(BTNode *a)
{
    if(a->lchild == NULL && a->rchild == NULL)
        return a->data;
    char left, right;
    left = right = 999;
    if(a->lchild != NULL)
        left = FindMin(a->lchild);
    if(a->rchild != NULL)
        right = FindMin(a->rchild);
    return left>right?right:left;
}

void Copy(BTNode *a, BTNode *b)
{
    if(a == NULL)
        b = a;
    else
    {
        b = (BTNode *)malloc(sizeof(BTNode));
        b->data = a->data;
        Copy(a->lchild, b->lchild);
        Copy(a->rchild, b->rchild);
    }
}

int main()
{
    return 0;
}
