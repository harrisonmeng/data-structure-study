#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

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
				case 4:
					printf("0");
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
	queuetype *q;
	datatype d;
	int i;
	int tag;
	
	InitQueue(&q);
	d.parent = 0;
	d.x = 0;
	d.y = 0;
	d.tag = 0;
	tag = 0;
	enQueue(q, entry_x, entry_y, 0, tag);
	d = deQueue(q);
	while(d.x != exit_x || d.y != exit_y)
	{
		if(maze[d.x - 1 + (d.y - 2) * width] == 0)
		{
			enQueue(q, d.x, d.y - 1, d.tag, ++tag);	
			//maze[d.x - 1 + (d.y - 2) * width] = 4;
		}
		if(maze[d.x - 2 + (d.y - 1) * width] == 0)
		{
			enQueue(q, d.x - 1 , d.y, d.tag, ++tag);
			//maze[d.x - 2 + (d.y - 1) * width] = 4;
		}
 		if(maze[d.x + (d.y - 1 ) * width] == 0)
		{
			enQueue(q, d.x + 1, d.y, d.tag, ++tag);
			//maze[d.x + (d.y - 1 ) * width] = 4;
		}
		if(maze[d.x -1 + d.y * width] == 0)
		{
			enQueue(q, d.x, d.y + 1, d.tag, ++tag);
			//maze[d.x -1 + d.y * width] = 4;
		}
		maze[d.x - 1 + (d.y - 1) * width] = 3;
		d = deQueue(q);
		printf("%d,%d,%d,%d\n", d.x, d.y, d.parent, d.tag);
	}
	
	while(d.x != 2 || d.y != 2)
	{
		maze[d.x - 1 + (d.y - 1) * width] = 2;
	
		d.x = q->info[d.parent].x;
		d.y = q->info[d.parent].y; 
		d.tag = q->info[d.parent].tag;	
		d.parent = q->info[d.parent].parent;
	}
	maze[width + 1] = 2;
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
