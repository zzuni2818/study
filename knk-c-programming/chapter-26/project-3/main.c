#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000

int comp(const void *p1, const void *p2);

int main()
{
	int i, arr[N];
	clock_t start_clock, end_clock;

	for(i = 0; i < N; i++) {
		arr[i] = N - i;
	}

	start_clock = clock();
	qsort(arr, N, sizeof(arr[0]), comp);
	end_clock = clock();

	printf("%g sec\n", (end_clock - start_clock) / (double) CLOCKS_PER_SEC);

	return 0;
}

int comp(const void *p1, const void *p2)
{
	return *(int *)p1 - *(int *)p2;
}
