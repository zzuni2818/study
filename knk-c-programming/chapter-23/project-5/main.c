#include <stdio.h>
#include <math.h>

int main()
{
	int year;
	double deposit, interest;

	printf("Enter amount to deposit: ");
	scanf("%lf", &deposit);
	printf("Enter interest rate: ");
	scanf("%lf", &interest);
	printf("Enter number of year: "); 
	scanf("%d", &year);

	interest *= 0.01;
	printf("result: %.2f\n", deposit * exp(interest * year));

	return 0;
}
