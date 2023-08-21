#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	const char *extension = ".rle";
	FILE *in_fp, *out_fp;
	int i, ch, ch_count;
	char out_filename[FILENAME_MAX], *check_extension;

	if(argc < 2) {
		fprintf(stderr, "usage: uncompress_file [filename]\n");
		exit(EXIT_FAILURE);
	}

	check_extension = strstr(argv[1], extension);
	if(check_extension == NULL || strcmp(extension, check_extension) != 0) {
		fprintf(stderr, "extension must be \".rle\"\n");
		exit(EXIT_FAILURE);
	}

	if((in_fp = fopen(argv[1], "rb")) == NULL) {
		fprintf(stderr, "Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	strcpy(out_filename, strtok(argv[1], "."));

	if((out_fp = fopen(out_filename, "wb")) == NULL) {
		fprintf(stderr, "Can't open %s\n", out_filename);

		fclose(in_fp);
		exit(EXIT_FAILURE);
	}

	while((ch_count = getc(in_fp)) != EOF) {
		ch = getc(in_fp);
		printf("%x %x\n", ch_count, ch);
		for(i = 0; i < ch_count; i++) {
			putc(ch, out_fp);
		}
	}

	fclose(in_fp);
	fclose(out_fp);

	return 0;
}
