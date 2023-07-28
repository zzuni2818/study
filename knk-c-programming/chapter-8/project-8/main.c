#include <stdio.h>

#define QUIZ_SIZE 5
#define STUDENT_SIZE 5

int main()
{
	int m[STUDENT_SIZE][QUIZ_SIZE];
	int total_scores[STUDENT_SIZE] = {0}, high_scores[QUIZ_SIZE], low_scores[QUIZ_SIZE];
	int i, j;
	
	//enter numbers
	for(i = 0; i < STUDENT_SIZE; i++) {
		printf("Enter five quiz grades of student %d: ", i+1);
		for(j = 0; j < QUIZ_SIZE; j++) {
			scanf("%d", &m[i][j]);
		}
	}

	//calulate sum of total_score of each student, high_score and low_score of each quiz
	for(i = 0; i < STUDENT_SIZE; i++) {
		for(j = 0; j < QUIZ_SIZE; j++) {
			total_scores[i] += m[i][j];

			if(i == 0) {
				high_scores[j] = m[i][j];
				low_scores[j] = m[i][j];
			} else {
				high_scores[j] = m[i][j] > high_scores[j] ? m[i][j] : high_scores[j];
				low_scores[j] = m[i][j] < low_scores[j] ? m[i][j] : low_scores[j];
			}
		}
	}

	//print
	printf("\n");
	for(i = 0; i < STUDENT_SIZE; i++) {
		printf("Student %d has total score: %d, average score: %.2f\n", i + 1, total_scores[i], (double) total_scores[i] / QUIZ_SIZE);
	}
	printf("\n");
	for(j = 0; j < QUIZ_SIZE; j++) {
		printf("high score and low score of quiz %d is %d, %d\n", j + 1, high_scores[j], low_scores[j]);
	}
	printf("\n");

	return 0;
}
