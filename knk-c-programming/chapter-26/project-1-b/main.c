#include <stdio.h>
#include <stdlib.h>

#define N 10

int main()
{
	int i, count = 1000;

	for(i = 0; i < count; i++) {
		//rand() / (RAND_MAX / N + 1) is better than rand() % N
		printf("%d", (rand() / (RAND_MAX / N + 1)) & 1);
	}
	printf("\n");

	return 0;
}
