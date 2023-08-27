#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, count = 1000;

	for(i = 0; i < count; i++) {
		printf("%d", rand() & 1);
	}
	printf("\n");

	return 0;
}
