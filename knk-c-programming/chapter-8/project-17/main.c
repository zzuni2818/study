#include <stdio.h>

#define ROW_SIZE 99
#define COL_SIZE 99

int main()
{
	int n, square[ROW_SIZE][COL_SIZE] = {0};
	int i, j, previous_row, previous_col, next_row, next_col;

	printf("This program creates a magic square of a specified size.\n");
	printf("The size must be an odd number between 1 and 99.\n");
	printf("Enter size of magic square: ");
	scanf("%d", &n);

	previous_row = 0;
	previous_col = n / 2;
	square[previous_row][previous_col] = 1;

	for(i = 2; i <= n * n; i++) {
		do {
			next_row = previous_row - 1;
			if(next_row < 0) {
				next_row = n - 1;
			}
			next_col = previous_col + 1;
			if(next_col > n - 1) {
				next_col = 0;
			}
			if(square[next_row][next_col] != 0) {
				next_row = previous_row + 1;
				if(next_row > n - 1) {
					next_row = 0;
				}
				next_col = previous_col;
			}
			previous_row = next_row;
			previous_col = next_col;
		} while(square[next_row][next_col] != 0);
		
		square[next_row][next_col] = i;
	}

	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			printf("%3d", square[i][j]);
		}
		printf("\n");
	}

	return 0;
}
