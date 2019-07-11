//
//把下面两个广义表用单链表存储，然后用递归方式遍历并且比较两个表，打印出不同的地方
//A( 'a', 'b', 'c', (1, 2, 3, (x, y, z), 4), 'd')
//B( 'a', 'b', 'c', (1, 2, 3, (x, y, u), 4), 'd')

#include <stdio.h>
#include <stdlib.h>

typedef struct GLNode
{
    int tag;
    union
    {
        char data;
        struct GLNode *sublist;
    }val;
    struct GLNode *next;
}GLNode;

GLNode *CreateList(char *s)
{
    int i = 0;
    GLNode *g;
    char ch = *s++;
    if(ch != '\0')
    {
        g = (GLNode*)malloc(sizeof(struct GLNode));
        if(ch == '(')
        {
            g->tag = 1;
            g->val.sublist = CreateList(s);
            i++;
            while(i != 0)
            {
                ch = *s++;
                if(ch == '(')
                    i++;
                if(ch == ')')
                    i--;
            }
        }
        else if(ch == ')')
        {
            g = NULL;
        }
        else
        {
            g->tag = 0;
            g->val.data = ch;
        }
    }
    else
    {
        g = NULL;
    }
    ch = *s++;
    if(g != NULL)
    {
        if(ch == ',')
        {
            g->next = CreateList(s);
        }
        else
        {
            g->next = NULL;
        }
    }
    return g;
}

void FindDifference(GLNode *A, GLNode *B)
{
    if(A == NULL || B == NULL)
        return;
    else
    {
        if(A->tag == 0 && B->tag == 0)
        {
            if(A->val.data != B->val.data)
            {
                printf("Difference:\nA:%c,B:%c\n",A->val.data,B->val.data);
            }
        }
        else
        {
            FindDifference(A->val.sublist,B->val.sublist);
        }
        FindDifference(A->next, B->next);
    }
    return;
}

int main()
{
    GLNode *A = (GLNode*)malloc(sizeof(GLNode));
    GLNode *B = (GLNode*)malloc(sizeof(GLNode));
    char a[]="(a,b,c,(1,2,3,(x,y,z),4),d)";
    char b[]="(a,b,c,(1,2,3,(x,y,u),4),d)";

    A->tag = 1;
    A->val.sublist = CreateList(a);
    B->tag = 1;
    B->val.sublist = CreateList(b);
    FindDifference(A->val.sublist, B->val.sublist);
    return 0;
}
