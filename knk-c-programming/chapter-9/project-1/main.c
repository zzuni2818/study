#include <stdio.h>

#define ARR_SIZE 10

void selection_sort(int arr[], int n);

int main()
{
	int i, arr[ARR_SIZE];

	printf("Enter %d numbers: ", ARR_SIZE);
	for(i = 0; i < ARR_SIZE; i++) {
		scanf("%d", &arr[i]);
	}

	selection_sort(arr, ARR_SIZE);


	printf("Sorted:");
	for(i = 0; i < ARR_SIZE; i++) {
		printf(" %d", arr[i]);
	}
	printf("\n");

	return 0;
}

void selection_sort(int arr[], int n)
{
	int i, temp, largest_index = 0;

	if(n <= 1) {
		return;
	}

	for(i = 1; i < n; i++) {
		if(arr[largest_index] < arr[i]) {
			largest_index = i;
		}
	}

	temp = arr[n - 1];
	arr[n - 1] = arr[largest_index];
	arr[largest_index] = temp;
	
	selection_sort(arr, n - 1);
}
