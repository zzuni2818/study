#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	//answer1
	/*
	int i, sum = 0;
	
	for(i = 1; i < argc; i++) {
		sum += atoi(argv[i]);
	}

	printf("Total: %d\n", sum);
	*/

	//answer2
	int sum = 0;
	
	while(*++argv) {
		sum += atoi(*argv);
	}

	printf("Total: %d\n", sum);

	return 0;
}
