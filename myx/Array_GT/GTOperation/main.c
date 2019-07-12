//
//建立广义表g=(b, (b, a, (#)，d), ((a, b), c, ((#))))的链式存储结构 (#)代表空表
//输出广义表g的长度和深度
//输出广义表g的值最大的原子，应该是d (ascii值最大)

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
        else if(ch == '#')
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

int FindDepth(GLNode *a)
{
    if(a == NULL)
    {
        return 1;
    }

    int max,dep;
    GLNode *p;

    max = dep = 0;

    for(p = a; p != NULL; p = p->next)
    {
        if(p->tag == 1)
        {
            dep = FindDepth(p->val.sublist);
            if(dep > max)
            {
                max = dep;
            }
        }
    }
    return max + 1;
}

int FindLength(GLNode *a)
{
    int length = 0;
    GLNode *p;
    p = a;
    while(p)
    {
        length++;
        p = p->next;
    }
    return length;
}

char FindLargest(GLNode *a)
{
    char max1,max2;
    if(a != NULL)
    {
        if(a->tag == 0)
        {
            max1 = FindLargest(a->next);
            return(a->val.data > max1 ? a->val.data : max1);
        }
        else
        {
            max1 = FindLargest(a->val.sublist);
            max2 = FindLargest(a->next);
            return(max1 > max2 ? max1 : max2);
        }
    }
    else
        return 0;
}

int main()
{
    GLNode *a;
    char list[] = "(b,(b,a,(#),d),((a,b),c,((#))))";

    a = CreateList(list);

    printf("Depth:%d\n", FindDepth(a->val.sublist));
    printf("Length:%d\n", FindLength(a->val.sublist));
    printf("Largest atom:%c", FindLargest(a->val.sublist));
    return 0;
}
