#include <stdio.h>
#include <stdlib.h>

char list[32] = "\0";

typedef struct BTNode
{
    struct BTNode *lchild;
    struct BTNode *rchild;
    struct BTNode *next;
    int data;
    int tag;
    int freq;
}BTNode;

void GiveValue(BTNode *l, char *n)
{
    char a[32];
    int i = 0;
    for(i = 0; i< 32; i++)
    {
        a[i] = n[i];
    }
    if(l->lchild == NULL && l->rchild == NULL)
    {

        printf("%x:%s\n", l->data, a);
        return;
    }
    if(l->lchild == NULL)
    {
        a[i+1] = '0';
        printf("%d:%d\n", l->rchild->freq, l->rchild->tag);
        GiveValue(l->rchild,a);
    }
    if(l->rchild == NULL)
    {
        a[i+1] = '1';
        printf("%d:%d\n", l->lchild->freq, l->lchild->tag);
        GiveValue(l->lchild, a);
    }
}

//void GiveValue(BTNode *l)

BTNode *CreateTree(BTNode *l, BTNode *a)
{
    BTNode *x;
    BTNode *y;
    BTNode *p;
    BTNode *q;
    BTNode *r;
    for(;l->next->next != NULL;)
    {
        x = l->next;
        y = l->next->next;
        p = (BTNode *)malloc(sizeof(BTNode));
        p->data = -1;
        p->lchild = x;
        p->rchild = y;
        p->freq = x->freq + y->freq;
        p->tag = 0;

        l->next = y->next;
        x->next = NULL;
        x->lchild = NULL;
        x->rchild = NULL;
        x->tag = 0;
        y->next = NULL;
        y->lchild = NULL;
        y->rchild = NULL;
        y->tag = 0;

        printf("%d + %d = %d\n", x->freq, y->freq, p->freq);
        q = l->next;
        r = l;
        while(q!=NULL && p->freq > q->freq)
        {
            q = q->next;
            r = r->next;
        }
        r->next = p;
        p->next = q;
    }
}

int main()
{
    FILE *picture;
    FILE *out;
    char s[9] = {0};
    int f[256] = {0};
    int frequncy[256] = {0};
    int total = 0;
    int c,i,j;
    BTNode *huffman = (BTNode *) malloc(sizeof(BTNode));
    picture = fopen("1.bmp","rb");
    out = fopen("out.txt","ws");
    while(!feof(picture))
    {
        c = fgetc(picture);
        sprintf(s,"%x ",c);
        f[c]++;
        fputs(s,out);
        total++;
    }
    for(i = 0; i < 256; i++)
    {
       frequncy[i] = f[i];
    }
    for(i = 0; i < 256; i++)
        printf("%x:%d:%d\n", i, f[i], frequncy[i]);

    BTNode *l = (BTNode*)malloc(sizeof(BTNode));
    BTNode *p = l;
    int min;
    int minnum;
    for(i = 0; i < 256; i++)
    {
        min = 9999999;
        min = 9999999;
        p->next = (BTNode *)malloc(sizeof(BTNode));
        p->next->next = NULL;
        for(j = 0; j < 256; j++)
        {
            if(frequncy[j] < min)
            {
                min = frequncy[j];
                minnum = j;
            }
        }
        frequncy[minnum] = 99999999;
        p->next->freq = min;
        p->next->data = minnum;
        p->next->tag = 0;
        p = p->next;
    }

    CreateTree(l, huffman);
    GiveValue(huffman, list);
    return 0;
}
