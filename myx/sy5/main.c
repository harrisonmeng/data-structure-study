#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

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

void PrintMaze(int *maze,int x,int y)
{
	int i,j;
	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
		{
			printf("%c",maze[i*y+j]==0?' ':(maze[i*y+j]==1?maze[i*y+j]+48:'*'));
		}
		printf("\n");
	}
}

int *Find(stacktype *s,int *maze)
{
	int i=21;
	Push(maze[20+2-1],20+2-1,s);
	while(s->number[s->top]!=378)
	{
		if(maze[i]!=0)
			Pop(s);
		else
		{
			if(maze[i-20]==0)
				Push(maze[i-20],i-20,s);
	 		if(maze[i-1]==0)
				Push(maze[i-1],i-1,s);
			if(maze[i+1]==0)
				Push(maze[i+1],i+1,s);
			if(maze[i+20]==0)
				Push(maze[i+20],i+20,s);
			if((maze[i-20]!=0)&&(maze[i-1]!=0)&&(maze[i+1]!=0)&&(maze[i+20]!=0))
				Pop(s);
		}
		maze[i]=2;
		i=s->number[s->top];
	}
	maze[378]=2;
	Push(maze[378],i,s);
	return maze;
}

int main(int argc, char** argv) {
	int *maze;
	int i=0;
	int h,l;
	stacktype *s; 
	maze=ReadMaze(&h,&l);
	PrintMaze(maze,h,l);
	
	printf("\n--------------------\n\n");
	
	InitStack(&s);
	maze=Find(s,maze);
	PrintMaze(maze,h,l);
	return 0;
}
