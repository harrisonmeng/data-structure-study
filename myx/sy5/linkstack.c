#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkstack.h"

void LinkStackInit(linkstack **s)
{
	linkstack *p;
	p=(linkstack *)malloc(sizeof(linkstack));
	p->node=NULL;
	p->length=0;
	*s=p;
}

void LinkStackFree(linkstack *s)
{
	free(s); 
}

void LinkStackPush(int m,int n,linkstack *s)
{
	linknode *p;
	p=(linknode *)malloc(sizeof(linknode));
	p->data=m;
	p->number=n;
	p->next=s->node;
	s->node=p;
	s->length++;
}

int LinkStackEmpty(linkstack *s)
{
	return s->node==NULL?0:1;
}

linknode* LinkStackPop(linkstack *s)
{
	if(LinkStackEmpty(s)!=0)
	{
		linknode *p;
		char x;
		p=s->node;
		s->node=p->next;
		s->length--;
		return p;
	}	
	return 0;
}

void PrintStack(linkstack *s)
{
	linknode *p=s->node;
	while(p!=NULL)
	{
		printf("%c",p->data);
		p=p->next;
	}
	printf("\n");
}
