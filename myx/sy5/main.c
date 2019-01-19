#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
			printf("%c",maze[i*y+j]==1?'1':' ');
		}
		printf("\n");
	}
}

int main(int argc, char** argv) {
	int *maze;
	int i=0;
	int h,l;
	maze=ReadMaze(&h,&l);
	PrintMaze(maze,h,l);
	return 0;
}
