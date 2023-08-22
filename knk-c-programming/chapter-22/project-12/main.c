#include <stdio.h>
#include <stdlib.h>

#define LINE_SIZE 100

int main(int argc, char *argv[])
{
	FILE *fp;
	char line[LINE_SIZE + 1];
	int item_number, year, month, day;
	float unit_price;

	if(argc < 2) {
		fprintf(stderr, "usage: [filename]\n");
		exit(EXIT_FAILURE);
	}

	if((fp = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	printf("Item\t\tUnit\t\tPurchase\n");
	printf("\t\tPrice\t\tDate\n");
	while(fgets(line, LINE_SIZE, fp) != NULL) {
		sscanf(line, "%d,%f,%d/%d/%d\n", &item_number, &unit_price, &month, &day, &year);
		printf("%d\t\t$%7.2f\t%d/%.2d/%d\n", item_number, unit_price, month, day, year);
	}

	fclose(fp);
	
	return 0;
}
