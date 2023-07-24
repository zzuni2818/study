#include <stdio.h>

int main()
{
	float number_of_share, price_per_share, value, rival_commission, original_commission;

	printf("Enter the number of share and price per share: ");
	scanf("%f %f", &number_of_share, &price_per_share);

	value = number_of_share * price_per_share;

	if(number_of_share < 2000) {
		rival_commission = 33.0f + (value * 0.03f);
	} else {
		rival_commission = 33.0f + (value * 0.02f);
	}

	if(value < 2500.00f) {
		original_commission = 30.00f + .017f * value;
	} else if(value < 6250.00f) {
		original_commission = 56.00f + .0066f * value;
	} else if(value < 20000.00f) {
		original_commission = 76.00f + .0034f * value;
	} else if(value < 50000.00f) {
		original_commission = 100.00f + .0022f * value;
	} else if(value < 500000.00f) {
		original_commission = 155.00f + .0011f * value;
	} else {
		original_commission = 255.00f + .0009f * value;
	}

	if(original_commission < 39.00f) {
		original_commission = 39.00f;
	}

	printf("rival commssion: %f\n", rival_commission);
	printf("original commssion: %f\n", original_commission);

	return 0;
}
