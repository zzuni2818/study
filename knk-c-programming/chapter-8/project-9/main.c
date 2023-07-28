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

int main()
{
	char matrix[ROW_SIZE][COL_SIZE];
	bool visited[ROW_SIZE][COL_SIZE];
	int direction, current_x = 0, current_y = 0;
	int i, j;
	char label;

	for(i = 0; i < ROW_SIZE; i++) {
		for(j = 0; j < COL_SIZE; j++) {
			matrix[i][j] = '.';
			visited[i][j] = false;
		}
	}
	matrix[0][0] = 'A';
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
				matrix[current_y][current_x] = label;
				label++;
			}
			break;
		case UP:
			if(current_y - 1 >= 0 && !visited[current_y - 1][current_x]) {
				current_y -= 1;
				visited[current_y][current_x] = true;
				matrix[current_y][current_x] = label;
				label++;
			}
			break;
		case RIGHT:
			if(current_x + 1 < COL_SIZE && !visited[current_y][current_x + 1]) {
				current_x += 1;
				visited[current_y][current_x] = true;
				matrix[current_y][current_x] = label;
				label++;
			}
			break;
		case DOWN:
			if(current_y + 1 < ROW_SIZE && !visited[current_y + 1][current_x]) {
				current_y += 1;
				visited[current_y][current_x] = true;
				matrix[current_y][current_x] = label;
				label++;
			}
			break;
		}
	}

	for(i = 0; i < ROW_SIZE; i++) {
		for(j = 0; j < COL_SIZE; j++) {
			printf("%c ", matrix[i][j]);
		}
		printf("\n");
	}

	return 0;
}
