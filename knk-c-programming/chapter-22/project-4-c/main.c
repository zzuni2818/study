#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	int ch, line_count = 0;

	if(argc < 2) {
		fprintf(stderr, "usage: line_count [filename]\n");
		exit(EXIT_FAILURE);
	}

	if((fp = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while((ch = getc(fp)) != EOF) {
		if(ch == '\n') {
			line_count++;
		}
	}
	fclose(fp);

	printf("line_count: %d in %s\n", line_count, argv[1]);

	return 0;
}
