#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *src_fp, *dest_fp;
	int ch, next_ch;

	if(argc < 3) {
		fprintf(stderr, "usage: unix_to_window [input filename][output filename]\n");
		exit(EXIT_FAILURE);
	}

	if((src_fp = fopen(argv[1], "rb")) == NULL) {
		fprintf(stderr, "Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if((dest_fp = fopen(argv[2], "wb")) == NULL) {
		fprintf(stderr, "Can't open %s\n", argv[2]);
		
		fclose(src_fp);
		exit(EXIT_FAILURE);
	}

	while((ch = getc(src_fp)) != EOF) {
		if(ch == '\x0a') {
			putc('\x0d', dest_fp);
			putc('\x0a', dest_fp);
		} else {
			putc(ch, dest_fp);
		}
	}

	fclose(src_fp);
	fclose(dest_fp);

	return 0;
}
