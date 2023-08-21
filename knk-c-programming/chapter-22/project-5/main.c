#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define KEY '&'

int main(int argc, char *argv[])
{
	FILE *in_fp, *out_fp;
	int orig_char, new_char;

	if(argc < 3) {
		fprintf(stderr, "usage: xor [input filename][output filename]\n");
		exit(EXIT_FAILURE);
	}

	if((in_fp = fopen(argv[1], "rb")) == NULL) {
		fprintf(stderr, "Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if((out_fp = fopen(argv[2], "wb")) == NULL) {
		fprintf(stderr, "Can't open %s\n", argv[2]);
		fclose(in_fp);
		exit(EXIT_FAILURE);
	}

	while((orig_char = getc(in_fp)) != EOF) {
		new_char = orig_char ^ KEY;
		putc(new_char, out_fp);
	}


	fclose(in_fp);
	fclose(out_fp);

	return 0;
}
