#include <stdio.h>
#include <stdlib.h>

int main()
{
	const char data[] = {
			0x46, 0x6f, 0x6f, 0x20, 0x62,
			0x61, 0x72, 0x21, 0x21, 0x21,
			0x20, 0x20, 0x20, 0x20, 0x20
	};
	FILE *fp;

	if((fp = fopen("memo", "wb")) == NULL) {
		fprintf(stderr, "Can't open %s\n", "memo");
		exit(EXIT_FAILURE);
	}
	
	fwrite(data, sizeof(data[0]), sizeof(data) / sizeof(data[0]), fp);

	fclose(fp);

	return 0;
}
