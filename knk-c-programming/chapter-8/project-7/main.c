#include <stdio.h>

#define ROW_SIZE 5
#define COLUMN_SIZE 5

int main()
{
	int m[ROW_SIZE][COLUMN_SIZE];
	int row_sum[ROW_SIZE] = {0}, col_sum[COLUMN_SIZE] = {0};
	int i, j;
	
	//enter numbers
	for(i = 0; i < ROW_SIZE; i++) {
		printf("Enter row %d: ", i+1);
		for(j = 0; j < COLUMN_SIZE; j++) {
			scanf("%d", &m[i][j]);
		}
	}

	//calulate sum of row and column
	for(i = 0; i < ROW_SIZE; i++) {
		for(j = 0; j < COLUMN_SIZE; j++) {
			row_sum[i] += m[i][j];
			col_sum[j] += m[i][j];
		}
	}

	//print
	printf("Row totals:");
	for(i = 0; i < ROW_SIZE; i++) {
		printf(" %d", row_sum[i]);
	}
	printf("\n");
	printf("Column totals:");
	for(j = 0; j < COLUMN_SIZE; j++) {
		printf(" %d", col_sum[j]);
	}
	printf("\n");

	return 0;
}
