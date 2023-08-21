#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define OFFSET 10

int main(int argc, char *argv[])
{
	FILE *fp;
	int i, offset = 0;
	char buffer[OFFSET];
	size_t read_length;

	if(argc < 2) {
		fprintf(stderr, "usage: [filename]\n");
		exit(EXIT_FAILURE);
	}

	if((fp = fopen(argv[1], "rb")) == NULL) {
		fprintf(stderr, "Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}


	printf("Offset              Bytes              Characters\n");
	printf("------  -----------------------------  ----------\n");
	
	for(offset = 0; ; offset += 10) {
		read_length = fread(buffer, sizeof(buffer[0]), OFFSET, fp);
		if(read_length == 0) {
			break;
		}

		//print Offset
		printf("%6d", offset);
		printf("  ");

		//print Bytes
		for(i = 0; i < OFFSET; i++) {
			if(i < read_length) {
				printf("%.2X", buffer[i]);
			} else {
				printf("  ");
			}

			if(i != OFFSET - 1) {
				printf(" ");
			}
		}
		printf("  ");

		//print Characters
		for(i = 0; i < read_length; i++) {
			if(isprint(buffer[i])) {
				printf("%c", buffer[i]);
			} else {
				printf("%c", '.');
			}
		}
		printf("\n");
	}
	fclose(fp);

	return 0;
}
