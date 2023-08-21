#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	int char_count = 0;

	if(argc < 2) {
		fprintf(stderr, "usage: char_count [filename]\n");
		exit(EXIT_FAILURE);
	}

	if((fp = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while(getc(fp) != EOF) {
		char_count++;
	}
	fclose(fp);

	printf("the number of characters: %d in %s\n", char_count, argv[1]);

	return 0;
}
