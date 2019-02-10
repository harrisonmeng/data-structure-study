#include <stdio.h>
#include <stdlib.h>

typedef struct link
{
    int data;
    struct link *next;
}linknode;

void fun(linknode *p)
{
    p = p->next;
    if(p == NULL)
        return;
    else
    {
        printf("%d ", p->data);
        fun(p);
    }
}

void fun1(linknode *p)
{
    p = p->next;
    if(p == NULL)
        return;
    else
    {
        fun1(p);
        printf("%d ", p->data);
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
    fun(head);
    printf("%\n");
    fun1(head);
    printf("%\n");
    return 0;
}
