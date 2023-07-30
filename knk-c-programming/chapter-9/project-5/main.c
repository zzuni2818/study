#include <stdio.h>

#define ROW_SIZE 99
#define COL_SIZE 99

void create_magic_square(int n, char magic_square[ROW_SIZE][COL_SIZE]);
void print_magic_square(int n, char magic_square[ROW_SIZE][COL_SIZE]);

int main()
{
	int n;
	char square[ROW_SIZE][COL_SIZE] = {0};

	printf("This program creates a magic square of a specified size.\n");
	printf("The size must be an odd number between 1 and 99.\n");
	printf("Enter size of magic square: ");
	scanf("%d", &n);

	create_magic_square(n, square);
	print_magic_square(n, square);

	return 0;
}
void create_magic_square(int n, char magic_square[ROW_SIZE][COL_SIZE])
{
	int i, previous_row, previous_col, next_row, next_col;

	previous_row = 0;
	previous_col = n / 2;
	magic_square[previous_row][previous_col] = 1;

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
			if(magic_square[next_row][next_col] != 0) {
				next_row = previous_row + 1;
				if(next_row > n - 1) {
					next_row = 0;
				}
				next_col = previous_col;
			}
			previous_row = next_row;
			previous_col = next_col;
		} while(magic_square[next_row][next_col] != 0);
		
		magic_square[next_row][next_col] = i;
	}
}

void print_magic_square(int n, char magic_square[ROW_SIZE][COL_SIZE])
{
	int i, j;

	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			printf("%3d", magic_square[i][j]);
		}
		printf("\n");
	}
}
