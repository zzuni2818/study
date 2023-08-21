#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	int ch, word_count = 0;
	bool in_word;

	if(argc < 2) {
		fprintf(stderr, "usage: word_count [filename]\n");
		exit(EXIT_FAILURE);
	}

	if((fp = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while((ch = getc(fp)) != EOF) {
		if(isspace(ch)) {
			if(in_word) {
				in_word = false;
				word_count++;
			}
		} else {
			if(!in_word) {
				in_word = true;
			}
		}
	}
	fclose(fp);

	printf("word_count: %d in %s\n", word_count, argv[1]);

	return 0;
}
