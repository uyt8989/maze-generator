
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
// #include <unistd.h>

#define ROW 10
#define COL 7

enum direction { RIGHT, DOWN };

typedef struct MAZE{
	// 0: right
	// 1: down
	int wall[2];
} maze_t;

maze_t maze[ROW][COL];
bool visit[ROW][COL];

void init_maze();
void print_maze();
void binary_generator();

int main() {
	init_maze();
	print_maze();

	return 0;
}

void init_maze() {
	int i, j, w;
	for (i = 0; i < ROW; i++) for (j = 0; j < COL; j++) {
		for (w = 0; w < 2; w++) maze[i][j].wall[w] = 1;	
	}
}

void print_maze() {
	int i, j, w;
	for (j = 0; j < COL; j++) printf(" -");
	printf("\n");

	for (i = 0; i < ROW; i++) {
		if (i != 0) {
			for (j = 0; j < COL; j++) {
				printf(" ");
				if (maze[i - 1][j].wall[DOWN] == 1) printf("-");
				else printf(" ");
			}
			printf("\n");
		}

		printf("|");
		for (j = 0; j < COL; j++) {
			printf(" ");
			if (maze[i][j].wall[RIGHT] == 1) printf("|");
			else printf(" ");
		}
		printf("\n");
	}

	for (j = 0; j < COL; j++) printf(" -");
	printf("\n");
}

void binary_generator() {
	int i, j, w;

	// top
	for (i = 0; i < ROW - 1; i++) for (j = 0; j < COL; j++) {
		if (j == COL - 1) {
			maze[i][j].wall[DOWN] = 0;
			continue;
		}

		Sleep(1000);
		srand(time(NULL));
		// sleep(1);
		if (rand() % 2 == 0) {
			maze[i][j].wall[RIGHT] = 0;
		}
		else {
			maze[i][j].wall[DOWN] = 0;
		}
	}

	//bottom
	for (j = 0; j < COL - 1; j++) {
		maze[ROW - 1][j].wall[RIGHT] = 0;
	}
}