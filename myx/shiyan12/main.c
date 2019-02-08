#include <stdio.h>
#include <stdlib.h>
typedef struct linknode
{
    char c;
    struct linknode *next;
}linknode;

void printlink(linknode *head)
{
    linknode *temp;
    temp = head->next;
    while(temp != NULL)
    {
        printf("%c ",temp->c);
        temp = temp->next;
    }
    printf("\n");
}

void deletex(linknode *head)
{
    linknode *temp, *temp2;
    temp = head->next;
    temp2 = head;
    while(temp != NULL)
    {
        if(temp->c == 'x')
        {
            temp2->next = temp->next;
            free(temp);
            temp = temp2->next;
        }
        else
        {
            temp = temp->next;
            temp2 = temp2->next;
        }
    }
}

int main()
{
    linknode *tail, *temp, *head;
    int i;

    head = (linknode*)malloc(sizeof(linknode));
    head->next = NULL;
    head->c = 0;
    tail = head;
    for(i = 'a'; i <= 'z'; i++)
    {
        tail->next = (linknode*)malloc(sizeof(linknode));
        tail->next->c = i;
        tail->next->next = NULL;
        tail = tail->next;
    }
    printlink(head);
    deletex(head);
    printlink(head);
    return 0;
}
