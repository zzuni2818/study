#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *fp1, *fp2;
	int ch1, ch2;

	if(argc < 3) {
		fprintf(stderr, "usage: compare_file [filename][filename]\n");
		exit(EXIT_FAILURE);
	}

	if((fp1 = fopen(argv[1], "rb")) == NULL) {
		fprintf(stderr, "Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	if((fp2 = fopen(argv[2], "rb")) == NULL) {
		fprintf(stderr, "Can't open %s\n", argv[2]);

		fclose(fp1);
		exit(EXIT_FAILURE);
	}

	ch1 = getc(fp1);
	ch2 = getc(fp2);
	while(ch1 != EOF && ch2 != EOF) {
		if(ch1 != ch2) {
			break;
		}

		ch1 = getc(fp1);
		ch2 = getc(fp2);
	}

	if(ch1 == ch2) {
		printf("%s is same with %s\n", argv[1], argv[2]);
	} else {
		printf("%x %x\n", ch1, ch2);
		printf("%s is not same with %s\n", argv[1], argv[2]);
	}

	fclose(fp1);
	fclose(fp2);

	return 0;
}
