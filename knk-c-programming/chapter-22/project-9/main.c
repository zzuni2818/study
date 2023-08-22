#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAME_LEN 25

struct part {
	int number;
	char name[NAME_LEN + 1];
	int on_hand;
};

int main(int argc, char *argv[])
{
	FILE *in_fp1, *in_fp2, *out_fp;
	size_t read_size1, read_size2;
	struct part part1, part2;

	if(argc < 4) {
		fprintf(stderr, "usage: merge [input file 1][input file 2][output file]\n");
		exit(EXIT_FAILURE);
	}

	if((in_fp1 = fopen(argv[1], "rb")) == NULL) {
		fprintf(stderr, "Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if((in_fp2 = fopen(argv[2], "rb")) == NULL) {
		fprintf(stderr, "Can't open %s\n", argv[2]);

		fclose(in_fp1);
		exit(EXIT_FAILURE);
	}
	if((out_fp = fopen(argv[3], "wb")) == NULL) {
		fprintf(stderr, "Can't open %s\n", argv[3]);

		fclose(in_fp1);
		fclose(in_fp2);
		exit(EXIT_FAILURE);
	}

	read_size1 = fread(&part1, sizeof(struct part), 1, in_fp1);
	read_size2 = fread(&part2, sizeof(struct part), 1, in_fp2);
	while(read_size1 == 1 && read_size2 == 1) {
		if(part1.number < part2.number) {
			fwrite(&part1, sizeof(struct part), 1, out_fp);
			read_size1 = fread(&part1, sizeof(struct part), 1, in_fp1);
		} else if(part1.number > part2.number) {
			fwrite(&part2, sizeof(struct part), 1, out_fp);
			read_size2 = fread(&part2, sizeof(struct part), 1, in_fp2);
		} else {
			if(strcmp(part1.name, part2.name) != 0) {
				fprintf(stderr, "Name don't match: part1: (%d, %s), part2: (%d, %s)\n", 
					part1.number, part1.name, part2.number, part2.name);
			}

			part1.on_hand += part2.on_hand;
			fwrite(&part1, sizeof(struct part), 1, out_fp);

			read_size1 = fread(&part1, sizeof(struct part), 1, in_fp1);
			read_size2 = fread(&part2, sizeof(struct part), 1, in_fp2);
		}
	}

	while(read_size1 == 1) {
		fwrite(&part1, sizeof(struct part), 1, out_fp);
		read_size1 = fread(&part1, sizeof(struct part), 1, in_fp1);
	}
	while(read_size2 == 1) {
		fwrite(&part2, sizeof(struct part), 1, out_fp);
		read_size2 = fread(&part2, sizeof(struct part), 1, in_fp2);
	}


	fclose(in_fp1);
	fclose(in_fp2);
	fclose(out_fp);

	return 0;
}
