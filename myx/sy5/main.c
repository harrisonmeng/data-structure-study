#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkstack.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int *ReadMaze(int *width,int *height)
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
	*width=x;
	*height=y;
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

int *Find(int *maze,int width,int height)
{
	linkstack *s;
	LinkStackInit(&s);
	int i=width+1;
	LinkStackPush(maze[width+1],2,2,s);
	while(s->node->x!=25||s->node->y!=21)
	{
		if(maze[i]!=0)
		{
			LinkStackPop(s);
			maze[i]=3;
		}
		else
		{
			if(maze[i-width]==0)
				LinkStackPush(maze[i-width],i%width+1,i/width,s);
	 		if(maze[i-1]==0)
				LinkStackPush(maze[i-1],i%width,i/width+1,s);
			if(maze[i+1]==0)
				LinkStackPush(maze[i+1],i%width+2,i/width+1,s);
			if(maze[i+width]==0)
				LinkStackPush(maze[i+width],i%width+1,i/width+2,s);
			if((maze[i-width]!=0)&&(maze[i-1]!=0)&&(maze[i+1]!=0)&&(maze[i+width]!=0))
			{
				LinkStackPop(s);
				maze[i]=3;
			}
			else
				maze[i]=2;
		}
		i=(s->node->x-1)+(s->node->y-1)*width;
	}
	i=height*width-width-2;
	maze[i]=2;
	LinkStackPush(maze[i],width-1,height-1,s);
	LinkStackFree(s);
	
	return maze;
}

int main(int argc, char** argv) {
	int *maze;
	int i=0;
	int width,height;
	maze=ReadMaze(&width,&height);
	PrintMaze(maze,width,height);
	
	printf("\n");
	for(i=0;i<width;i++)
		printf("=");
	printf("\n\n");
	
	maze=Find(maze,width,height);
	PrintMaze(maze,width,height);
	free(maze);
	return 0;
}
