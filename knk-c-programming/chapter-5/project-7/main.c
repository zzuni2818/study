#include <stdio.h>

int main()
{
	int n1, n2, n3, n4, largest_number, smallest_number;

	printf("Enter four integers: ");
	scanf("%d %d %d %d", &n1, &n2, &n3, &n4);

	if(n1 > n2) {
		if(n3 > n4) {
			largest_number = n1 > n3 ? n1 : n3;
			smallest_number = n2 > n4 ? n4 : n2;
		} else {
			largest_number = n1 > n4 ? n1 : n4;
			smallest_number = n2 > n3 ? n3 : n2;
		}
	} else {
		if(n3 > n4) {
			largest_number = n2 > n3 ? n2 : n3;
			smallest_number = n1 > n4 ? n4 : n1;
		} else {
			largest_number = n2 > n4 ? n2 : n4;
			smallest_number = n1 > n3 ? n3 : n1;
		}
	}

	printf("Largest: %d\n", largest_number);
	printf("Smallest: %d\n", smallest_number);

	return 0;
}
