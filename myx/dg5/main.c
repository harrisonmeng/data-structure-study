#include <stdio.h>
#include <stdlib.h>

typedef struct link
{
    int data;
    struct link *next;
}linknode;

int length(linknode *p)
{
    p = p->next;
    if(p->next == NULL)
        return 1;
    else
        return 1 + length(p);
}

int main()
{
    linknode *head, *tail;
    int i;
    head = (linknode *)malloc(sizeof(linknode));
    head->data = 0;
    head->next = NULL;
    tail = head;
    for(i = 0; i < 10; i++)
    {
        tail->next = (linknode*)malloc(sizeof(linknode));
        tail->next->next = NULL;
        tail->next->data = 0;
        tail = tail->next;
    }
    printf("%d", length(head));
    return 0;
}
