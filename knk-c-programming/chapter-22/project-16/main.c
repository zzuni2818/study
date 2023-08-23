#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
	FILE *src_fp, *dest_fp;
	int ch;
	char buffer[BLOCK_SIZE];
	size_t read_size;

	if(argc != 3) {
		fprintf(stderr, "usage: fcopy source dest\n");
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

	while((read_size = fread(buffer, sizeof(buffer[0]), BLOCK_SIZE, src_fp)) == BLOCK_SIZE) {
		if(fwrite(buffer, sizeof(buffer[0]), read_size, dest_fp) != read_size) {
			fprintf(stderr, "Failed to write file: %s\n", argv[2]);

			fclose(src_fp);
			fclose(dest_fp);

			remove(argv[2]);

			exit(EXIT_FAILURE);
		}
	}

	//flush buffer
	if(read_size > 0) {
		if(fwrite(buffer, sizeof(buffer[0]), read_size, dest_fp) != read_size) {
			fprintf(stderr, "Failed to write file: %s\n", argv[2]);

			fclose(src_fp);
			fclose(dest_fp);

			remove(argv[2]);

			exit(EXIT_FAILURE);
		}
	}
	
	fclose(src_fp);
	fclose(dest_fp);

	return 0;
}
