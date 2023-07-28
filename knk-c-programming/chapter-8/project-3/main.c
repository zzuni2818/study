#include <stdio.h>

int main()
{
	int digit_seen[10] = {0};
	int digit, i;
	long n;

	while(1) {
		printf("Enter a number: ");
		scanf("%ld", &n);

		if(n <= 0) {
			break;
		}

		while(n > 0) {
			digit = n % 10;
			++digit_seen[digit];
			n /= 10;
		}
		printf("%-12s", "Digit:");
		for(i = 0; i < 10; i++) {
			printf(" %d", i);
		}
		printf("\n");
		printf("%-12s", "Occurrences:");
		for(i = 0; i < 10; i++) {
			printf(" %d", digit_seen[i]);
		}
		printf("\n");
	}

	return 0;
}
