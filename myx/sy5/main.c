#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkstack.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int *ReadMaze(int *width,int *height)
{
	FILE *fmaze;
	fmaze = fopen("maze.txt", "r");
	int *a;
	int i = 0, j = 0, x = 0, y = 0;
	int temp = 0;
	
	while(fgetc(fmaze) != '\n')
	{
		x++;
	}
	rewind(fmaze);
	while(!feof(fmaze))
	{
		if(fgetc(fmaze) == '\n')
			y++;
	}
	y++;
	
	i = x * y;
	printf("%d\n", i);
	a = (int *)malloc(sizeof(int*) * i);
	rewind(fmaze);
	for(j = 0; j < i; )
	{
		if((temp = fgetc(fmaze)) != '\n')
		{
			a[j] = (temp == '*' ? 1 : 0);
			j++;
		}	
	}
	fclose(fmaze);
	*width = x;
	*height = y;
	return a;
}

void PrintMaze(int *maze, int width, int height)
{
	int i, j;
	for(i = 0; i < height; i++)
	{
		for(j = 0; j < width; j++)
		{
			switch (maze[i*width+j])
			{
				case 0:
				case 3:
					printf(" ");
					break;
				case 1:
					printf("@");
					break;
				case 2:
					printf("#");
					break;
			}
		}
		printf("\n");
	}
}

int *Find(int *maze, int width, int height, int entry_x, int entry_y, int exit_x, int exit_y)
{
	void *s;
	linknode *p;
	int i;
	
	i = (entry_y-1) * width + entry_x - 1;
	LinkStackInit(&s);
	LinkStackPush(entry_x, entry_y, s);
	p = LinkStackPop(s);
	while(p->x != exit_x || p->y != exit_y)
	{
		if(maze[i] != 0)
		{
			p = LinkStackPop(s);
			maze[i] = 3;
		}
		else
		{
			LinkStackPush(p->x, p->y, s);
			if(maze[i-width] == 0)
				LinkStackPush(i%width+1, i/width, s);
			if(maze[i+1] == 0)
				LinkStackPush(i%width+2, i/width+1, s);
	 		if(maze[i-1] == 0)
				LinkStackPush(i%width, i/width+1, s);
			if(maze[i+width] == 0)
				LinkStackPush(i%width+1, i/width+2, s);
			maze[i] = 2;
			p = LinkStackPop(s);
		}
		i = (p->x - 1)+(p->y - 1) * width;
	}
	i = height*width-width-2;
	maze[i] = 2;
	LinkStackPush(width-1, height-1, s);
	LinkStackFree(s);
	
	return maze;
}

int main(int argc,  char** argv) {
	int *maze;
	int i = 0;
	int width, height;
	maze = ReadMaze(&width, &height);
	PrintMaze(maze, width, height);
	
	printf("\n");
	for(i = 0;i<width;i++)
		printf("=");
	printf("\n\n");
	
	maze = Find(maze, width, height, 2, 2, width-1, height-1);
	PrintMaze(maze, width, height);
	free(maze); 
	return 0;
}
