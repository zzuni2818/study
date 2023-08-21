#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	int i, failed_count = 0;

	if(argc < 2) {	
		printf("usage: canopen [filenames]\n");
		exit(EXIT_FAILURE);
	}

	for(i = 1; i < argc; i++) {
		if((fp = fopen(argv[i], "r")) == NULL) {
			printf("%s can't be opened\n", argv[i]);
			failed_count++;
		} else {
			printf("%s can be opened\n", argv[i]);
			fclose(fp);
		}
	}

	if(failed_count > 0) {
		exit(EXIT_FAILURE);
	}

	return 0;
}
