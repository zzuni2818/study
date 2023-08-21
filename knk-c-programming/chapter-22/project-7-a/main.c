#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
	const char *extension = ".rle";
	FILE *in_fp, *out_fp;
	int ch, check, count;
	char out_filename[FILENAME_MAX];

	if(argc < 2) {
		fprintf(stderr, "usage: compress_file [filename]\n");
		exit(EXIT_FAILURE);
	}

	if((in_fp = fopen(argv[1], "rb")) == NULL) {
		fprintf(stderr, "Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	
	strcpy(out_filename, argv[1]);
	strcat(out_filename, extension);

	if((out_fp = fopen(out_filename, "wb")) == NULL) {
		fprintf(stderr, "Can't open %s\n", out_filename);

		fclose(in_fp);
		exit(EXIT_FAILURE);
	}

	while((ch = getc(in_fp)) != EOF) {
		for(check = getc(in_fp), count = 1; ch == check; check = getc(in_fp), count++)
			;
		ungetc(check, in_fp);

		putc(count, out_fp);
		putc(ch, out_fp);
		printf("%x %x\n", count, ch);
	}

	fclose(in_fp);
	fclose(out_fp);

	return 0;
}
