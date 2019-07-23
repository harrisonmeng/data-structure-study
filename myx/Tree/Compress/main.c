#include <stdio.h>
#include <stdlib.h>

char list[32] = "\0";

typedef struct BTNode
{
    struct BTNode *lchild;
    struct BTNode *rchild;
    struct BTNode *next;
    int data;
//    int tag;
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

BTNode *CreateTree(BTNode *l)
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
//        p->tag = 0;

        l->next = y->next;
        x->next = NULL;
//        x->lchild = NULL;
//        x->rchild = NULL;
//        x->tag = 0;
        y->next = NULL;
//        y->lchild = NULL;
//        y->rchild = NULL;
//        y->tag = 0;

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
 //   FILE *out;
    char s[9] = {0};
 //   int f[256] = {0};
    int frequncy[256] = {0};
    int total = 0;
    int c,i,j;
//    BTNode *huffman = (BTNode *) malloc(sizeof(BTNode));
    picture = fopen("1.bmp","rb");
    // out = fopen("out.txt","ws");
    while(!feof(picture))
    {
        c = fgetc(picture);
        //sprintf(s,"%x ",c);
        frequncy[c]++;
        //fputs(s,out);
        total++;
    }

    for(i = 0; i < 256; i++)
        printf("0x%02X: %d\n", i, frequncy[i]);

    fclose(picture);

    BTNode *l = (BTNode*)malloc(sizeof(BTNode));
    l->freq = 0;
    l->next = NULL;
    BTNode *p, *prev, *temp;
    for(i = 0; i < 256; i++)
    {
        if(frequncy[i] == 0)
            continue;
        p = (BTNode *)malloc(sizeof(BTNode));
        p->next = NULL;
        p->data = i;
        p->tag = 0;
        p->freq = frequncy[i];
        p->lchild = NULL;
        p->rchild = NULL;

        prev = l;
        temp = l->next;
        if(l->next)
        {
            while(temp && temp->freq < p->freq)
            {
                prev = temp;
                temp = temp->next;
            }
            if(temp)
            {
                prev->next = p;
                p->next = temp;
            }
            else
            {
                prev->next = p;
            }
        }
        else
        {
            l->next = p;
        }
    }

    p = l->next;
    while(p)
    {
        printf("0x%02x --- freq = %d\n", p->data, p->freq);
        p = p->next;
    }

    CreateTree(l);
    GiveValue(l, list);
    return 0;
}
