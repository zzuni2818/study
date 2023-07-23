#include <stdio.h>

int main()
{
	//answer 1
	/*
	int d, i1, i2, i3, i4, i5, j1, j2, j3, j4, j5,
		first_sum, second_sum, total;

	printf("Enter the first 11 digits of a UPC: ");
	scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", 
		&d, 
		&i1, &i2, &i3, &i4, &i5,
		&j1, &j2, &j3, &j4, &j5);
	
	first_sum = d + i2 + i4 + j1 + j3 +j5;
	second_sum = i1 + i3 + i5 + j2 + j4;
	total = 3 * first_sum + second_sum;

	printf("Check digit: %d\n", 9 - ((total - 1) % 10));
	*/

	//answer 2
	int number, 
		type_of_item, manufacturer, product,
		first_sum, second_sum, total;

	printf("Enter the first 11 digits of a UPC: ");
	scanf("%d", &number);

	product = (number % 100000);
	manufacturer = (number % 10000000000) / 100000;
	type_of_item = number / 100000000000;

	first_sum = type_of_item + 
		((manufacturer / 1000) % 10) + 
		((manufacturer / 10) % 10) + 
		(product / 10000) + 
		((product / 100) % 10) + 
		(product % 10);

	second_sum = (manufacturer / 10000) + 
		((manufacturer / 100) % 10) + 
		(manufacturer % 10) + 
		((product / 1000) % 10) + 
		((product / 10) % 10);

	total = first_sum * 3 + second_sum;

	printf("Check digit: %d\n", 9 - ((total - 1) % 10));

	return 0;
}

