#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkstack.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int *ReadMaze(int *h,int *l)
{
	FILE *maze;
	maze=fopen("maze.txt","r");
	int *a;
	int i=0,j=0,x=0,y=0;
	int temp=0;
	
	while(fgetc(maze)!='\n')
	{
		x++;
	}
	rewind(maze);
	while(!feof(maze))
	{
		if(fgetc(maze)=='\n')
			y++;
	}
	y++;
	
	i=x*y;
	printf("%d\n",i);
	a=(int *)malloc(sizeof(int*)*i);
	rewind(maze);
	for(j=0;j<i;)
	{
		if((temp=fgetc(maze))!='\n')
		{
			a[j]=(temp==42?1:0);
			j++;
		}	
	}
	fclose(maze);
	*h=x;
	*l=y;
	return a;
}

void PrintMaze(int *maze,int y,int x)
{
	int i,j;
	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
		{
			printf("%c",maze[i*y+j]==0?' ':(maze[i*y+j]==1?'@':(maze[i*y+j]==2?'#':' ')));
		}
		printf("\n");
	}
}

int *Find(int *maze,int h,int l)
{
	linkstack *s;
	LinkStackInit(&s);
	int i=h+1;
	LinkStackPush(maze[h+1],h+1,s);
	while(s->node->number!=h*l-h-2)
	{
		if(maze[i]!=0)
		{
			LinkStackPop(s);
			maze[i]=3;
		}
		else
		{
			if(maze[i-h]==0)
				LinkStackPush(maze[i-h],i-h,s);
	 		if(maze[i-1]==0)
				LinkStackPush(maze[i-1],i-1,s);
			if(maze[i+1]==0)
				LinkStackPush(maze[i+1],i+1,s);
			if(maze[i+h]==0)
				LinkStackPush(maze[i+h],i+h,s);
			if((maze[i-h]!=0)&&(maze[i-1]!=0)&&(maze[i+1]!=0)&&(maze[i+h]!=0))
			{
				LinkStackPop(s);
				maze[i]=3;
			}
			else
				maze[i]=2;
		}
		i=s->node->number;
	}
	i=l*h-h-2;
	maze[i]=2;
	LinkStackPush(maze[i],i,s);
	LinkStackFree(s);
	
	return maze;
}

int main(int argc, char** argv) {
	int *maze,*way;
	int i=0;
	int h,l;
	maze=ReadMaze(&h,&l);
	PrintMaze(maze,h,l);
	
	printf("\n");
	for(i=0;i<h;i++)
		printf("=");
	printf("\n\n");
	
	maze=Find(maze,h,l);
	PrintMaze(maze,h,l);
	free(maze);
	return 0;
}
