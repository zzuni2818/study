#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define ROW_SIZE 10
#define COL_SIZE 10

#define LEFT 0
#define UP 1
#define RIGHT 2
#define DOWN 3

void generate_random_walk(char walk[ROW_SIZE][COL_SIZE]);
void print_array(char walk[ROW_SIZE][COL_SIZE]);

int main()
{
	char matrix[ROW_SIZE][COL_SIZE];

	generate_random_walk(matrix);

	print_array(matrix);

	return 0;
}

void generate_random_walk(char walk[ROW_SIZE][COL_SIZE])
{
	bool visited[ROW_SIZE][COL_SIZE];
	int direction, current_x = 0, current_y = 0;
	int i, j;
	char label;

	for(i = 0; i < ROW_SIZE; i++) {
		for(j = 0; j < COL_SIZE; j++) {
			walk[i][j] = '.';
			visited[i][j] = false;
		}
	}
	walk[0][0] = 'A';
	visited[0][0] = true;
	srand((unsigned) time(NULL));

	label = 'B';
	while(label <= 'Z') {
		if(current_x == 0 && current_y == 0) {
			if(visited[current_y][current_x + 1] && visited[current_y + 1][current_x]) {
				break;
			}
		} else if(current_x == COL_SIZE - 1 && current_y == 0) {
			if(visited[current_y][current_x - 1] && visited[current_y + 1][current_x]) {
				break;
			}
		} else if(current_x == COL_SIZE - 1 && current_y == ROW_SIZE - 1) {
			if(visited[current_y][current_x - 1] && visited[current_y - 1][current_x]) {
				break;
			}
		} else if(current_x == 0 && current_y == ROW_SIZE - 1) {
			if(visited[current_y][current_x + 1] && visited[current_y - 1][current_x]) {
				break;
			}
		} else if(current_x == 0) {
			if(visited[current_y][current_x + 1]
				&& visited[current_y - 1][current_x] && visited[current_y + 1][current_x]) {
				break;
			}
		} else if(current_x == COL_SIZE - 1) {
			if(visited[current_y][current_x - 1]
				&& visited[current_y - 1][current_x] && visited[current_y + 1][current_x]) {
				break;
			}
		} else if(current_y == 0) {
			if(visited[current_y][current_x - 1] && visited[current_y][current_x + 1]
				&& visited[current_y + 1][current_x]) {
				break;
			}
		} else if(current_y == ROW_SIZE - 1) {
			if(visited[current_y][current_x - 1] && visited[current_y][current_x + 1]
				&& visited[current_y - 1][current_x]) {
				break;
			}
		} else {
			if(visited[current_y][current_x - 1] && visited[current_y][current_x + 1]
				&& visited[current_y - 1][current_x] && visited[current_y + 1][current_x]) {
				break;
			}
		}

		direction = rand() % 4;
	
		switch(direction) {
		case LEFT:
			if(current_x - 1 >= 0 && !visited[current_y][current_x - 1]) {
				current_x -= 1;
				visited[current_y][current_x] = true;
				walk[current_y][current_x] = label;
				label++;
			}
			break;
		case UP:
			if(current_y - 1 >= 0 && !visited[current_y - 1][current_x]) {
				current_y -= 1;
				visited[current_y][current_x] = true;
				walk[current_y][current_x] = label;
				label++;
			}
			break;
		case RIGHT:
			if(current_x + 1 < COL_SIZE && !visited[current_y][current_x + 1]) {
				current_x += 1;
				visited[current_y][current_x] = true;
				walk[current_y][current_x] = label;
				label++;
			}
			break;
		case DOWN:
			if(current_y + 1 < ROW_SIZE && !visited[current_y + 1][current_x]) {
				current_y += 1;
				visited[current_y][current_x] = true;
				walk[current_y][current_x] = label;
				label++;
			}
			break;
		}
	}
}
void print_array(char walk[ROW_SIZE][COL_SIZE])
{
	int i, j;

	for(i = 0; i < ROW_SIZE; i++) {
		for(j = 0; j < COL_SIZE; j++) {
			printf("%c ", walk[i][j]);
		}
		printf("\n");
	}
}
