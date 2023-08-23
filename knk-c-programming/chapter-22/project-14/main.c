#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
	const char *extension = ".enc";
	FILE *in_fp, *out_fp;
	int ch, enc_ch, shift_amount;
	char in_filename[FILENAME_MAX], out_filename[FILENAME_MAX];

	printf("Enter name of file to be encrypted: ");
	scanf("%s", in_filename);
	printf("Enter shift amount (1-25): ");
	scanf("%d", &shift_amount);


	strcpy(out_filename, in_filename);
	strcat(out_filename, extension);

	if((in_fp = fopen(in_filename, "r")) == NULL) {
		fprintf(stderr, "Can't open %s\n", in_filename);
		exit(EXIT_FAILURE);
	}
	if((out_fp = fopen(out_filename, "w")) == NULL) {
		fprintf(stderr, "Can't open %s\n", out_filename);

		fclose(in_fp);
		exit(EXIT_FAILURE);
	}

	while((ch = getc(in_fp)) != EOF) {
		if(isalpha(ch)) {
			if(islower(ch)) {
				enc_ch = ((ch - 'a') + shift_amount) % 26 + 'a';
			} else {
				enc_ch = ((ch - 'A') + shift_amount) % 26 + 'A';
			}
		} else {
			enc_ch = ch;
		}

		if(putc(enc_ch, out_fp) == EOF) {
			fclose(in_fp);
			fclose(out_fp);
			remove(out_filename);

			fprintf(stderr, "Failed to write file: %s\n", out_filename);

			exit(EXIT_FAILURE);
		}
	}

	fclose(in_fp);
	fclose(out_fp);

	return 0;
}
