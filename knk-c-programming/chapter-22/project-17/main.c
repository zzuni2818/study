#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define LINE_SIZE 20
#define PHONE_NUMBER_SIZE 10

int main(int argc, char *argv[])
{
	FILE *fp;
	int ch;
	char line[LINE_SIZE + 1], phone_number[PHONE_NUMBER_SIZE];
	int i, j;

	if(argc < 2) {
		fprintf(stderr, "usage: [filename]\n");
		exit(EXIT_FAILURE);
	}

	if((fp = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while(fgets(line, LINE_SIZE, fp) != NULL) {
		for(i = 0, j = 0; i < LINE_SIZE && line[i] != '\0'; i++) {
			if(!isdigit(line[i])) {
				continue;
			}
			phone_number[j++] = line[i];
		}
		if(j == 10) {
			printf("(%c%c%c) %c%c%c-%c%c%c%c\n", 
				phone_number[0], phone_number[1], phone_number[2],
				phone_number[3], phone_number[4], phone_number[5],
				phone_number[6], phone_number[7], phone_number[8], phone_number[9]);
		}
	}

	fclose(fp);

	return 0;
}
