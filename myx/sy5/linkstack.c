#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkstack.h"

typedef struct LinkStackStruct
{
    int length;
    linknode* node; 
}linkstack;

void LinkStackInit(void **s)
{
	linkstack *p;
	
	p = (linkstack *)malloc(sizeof(linkstack));
	p->node = NULL;
	p->length = 0;
	*s = p;
}

void LinkStackFree(void *s)
{
	linkstack *sp = (linkstack*)s;
	linknode *p;
	
	if(s!=NULL)
	{
		while(sp->node != NULL)
		{
			p = sp->node;
			sp->node = p->next;
			free(p);
		}
		free(sp);
	}
}

void LinkStackPush(int a, int b, void *s)
{
	linkstack *sp = (linkstack*)s;
	linknode *p;
	
	p = (linknode *)malloc(sizeof(linknode));
	p->x = a;
	p->y = b;
	p->next = sp->node;
	sp->node = p;
	sp->length++;
}

int LinkStackEmpty(linkstack *s)
{
	return s->node == NULL?0:1;
}

linknode* LinkStackPop(void *s)
{
	linkstack *sp = (linkstack*)s;
	linknode *p;

	if(LinkStackEmpty(sp) != 0)
	{
		p = sp->node;
		sp->node = p->next;
		sp->length--;
		return p;
	}	
	return 0;
}

void PrintStack(linkstack *s)
{
	linknode *p = s->node;
	
	while(p != NULL)
	{
		printf("(%d,%d)", p->x, p->y);
		p = p->next;
	}
	printf("\n");
}
