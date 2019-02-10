#include <stdio.h>
#include <stdlib.h>

typedef struct link
{
    int data;
    struct link *next;
}linknode;

void del(linknode *p, int x)
{
    if(p->next == NULL)
        return;
    if(p->next->data == x)
    {
        linknode *temp;
        temp = p->next;
        p->next = p->next->next;
        free(temp);
        return;
    }
    else
    {
        del(p->next, x);
    }
}

void delall(linknode *p, int x)
{
    if(p->next == NULL)
        return;
    else
    {
        if(p->next->data == x)
        {
            linknode *temp;
            temp = p->next;
            p->next = p->next->next;
            free(temp);
        }
        delall(p->next, x);
    }
}

void printlink(linknode *p)
{
    linknode *a = p->next;
    while(a!=NULL)
    {
        printf("%d ", a->data);
        a = a->next;
    }
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
    head->next->data = 2;
    delall(head, 2);
    printlink(head);
    return 0;
}
