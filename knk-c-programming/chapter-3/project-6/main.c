#include <stdio.h>

int main()
{
	int num1, denom1, num2, denom2, result_num, result_denom;

	printf("Enter two fractions separated by a plus sign: ");

	/*
	 * input type: 
	 * 1. 5/6+3/4
	 * 2. 5 / 6 + 3 / 4
	 * 3. 5/6 + 3/4
	 */

	//available input type: 1
	//scanf("%d/%d+%d/%d", &num1, &denom1, &num2, &denom2);

	//available input type: 1, 2, 3
	scanf("%d /%d +%d /%d", &num1, &denom1, &num2, &denom2);

	result_num = num1 * denom2 + num2 * denom1;
	result_denom = denom1 * denom2;
	
	printf("The sum is %d/%d\n", result_num, result_denom);

	return 0;
}	
