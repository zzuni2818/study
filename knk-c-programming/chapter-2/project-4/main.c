#include <stdio.h>

int main()
{
	float amount;

	printf("Enter an amount: ");
	scanf("%f", &amount);

	printf("With tax added: $%.2f\n", (amount + (amount * 0.05)));
	return 0;
}
