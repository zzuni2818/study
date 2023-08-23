#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_NUMBER 10000

int comp(const void *p1, const void *p2);

int main(int argc, char *argv[])
{
	FILE *fp;
	int i, j, ch, count, number, number_of_digit, digit_length, number_r[5], numbers[MAX_NUMBER] = {0};

	if(argc < 2) {
		fprintf(stderr, "usage: [filename]\n");
		exit(EXIT_FAILURE);
	}

	if((fp = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	//answer1
	/*
	digit_length = count = 0;
	while((ch = getc(fp)) != EOF) {
		if(isdigit(ch)) {
			number_r[digit_length++] = ch - '0';
		} else {
			number_of_digit = digit_length - 1;
			for(i = 0; i < digit_length; i++) {
				number = number_r[i];
				for(j = number_of_digit; j > 0; j--) {
					number *= 10;
				}
				number_of_digit--;
				numbers[count] += number;
			}
			digit_length = 0;
			count++;
		}
	}
	*/

	//answer2
	int ret;
	for(count = 0; count < MAX_NUMBER; count++) {
		ret = fscanf(fp, "%d", &numbers[count]);
		if(ret != 1 || ret == EOF) {
			break;
		}
	}

	if(count != 0) {
		qsort(numbers, count, sizeof(numbers[0]), comp);

		printf("smallest number: %d\n", numbers[0]);
		printf("largets number: %d\n", numbers[count - 1]);
		if(count % 2 == 0) {
			printf("middle number: %d\n", numbers[count/2 - 1]);
			printf("middle number: %d\n", numbers[count/2]);
		} else {
			printf("middle number: %d\n", numbers[count/2]);
		}
	} else {
		printf("There is no number\n");
	}
	/*
	for(i = 0; i < count; i++) {
		printf("%d ", numbers[i]);
	}
	printf("\n");
	*/

	fclose(fp);

	return 0;
}

int comp(const void *p1, const void *p2)
{
	const int *n1 = p1;
	const int *n2 = p2;

	if(*n1 < *n2) {
		return -1;
	} else if(*n1 > *n2) {
		return 1;
	} else {
		return 0;
	}
}

