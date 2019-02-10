#include <stdio.h>
#include <stdlib.h>

typedef struct link
{
    int data;
    struct link *next;
}linknode;

void printlink(linknode *p)
{
    linknode *a = p->next;
    while(a!=NULL)
    {
        printf("%d ", a->data);
        a = a->next;
    }
}

int Max(linknode *p)
{
    if(p->next == NULL)
        return p->data;
    else
        return (p->data > Max(p->next) ? p->data : Max(p->next));
}

int Min(linknode *p)
{
    if(p->next == NULL)
        return p->data;
    else
        return (p->data < Max(p->next) ? p->data : Max(p->next));
}

int main()
{
    linknode *head, *tail;
    head = (linknode*)malloc(sizeof(linknode));
    head->next = NULL;
    head->data = 0;
    tail = head;
    for(int i = 0; i < 5; i++)
    {
        tail->next = (linknode*)malloc(sizeof(linknode));
        tail->next->data = i;
        tail->next->next = NULL;
        tail = tail->next;
    }
    printlink(head);
    printf("\n");
    printf("%d ", Max(head));
    printf("\n");
    printf("%d ", Min(head));
    printf("\n");
    return 0;
}
