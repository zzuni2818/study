#include <stdio.h>

#define TIME_SIZE 8

int main()
{
	int departure_times[TIME_SIZE] = {
		(8 * 60),
		(9 * 60 + 43),
		(11 * 60 + 19),
		(12 * 60 + 47),
		((2 + 12) * 60),
		((3 + 12) * 60 + 45),
		((7 + 12) * 60),
		((9 + 12) * 60 + 45) 
	};
	int arrival_times[TIME_SIZE] = {
		(10 * 60 + 16),
		(11 * 60 + 52),
		((1 + 12) * 60 + 31),
		((3 + 12) * 60),
		((4 + 12) * 60 + 8),
		((5 + 12) * 60 + 55),
		((9 + 12) * 60 + 20),
		((11 + 12) * 60 + 58)
	};
	

	int input_hour, input_minute, converted_time, 
		departure_time, arrival_time,
		compare_with_past, compare_with_comming,
		past_departure_time, past_arrival_time,
		comming_departure_time, comming_arrival_time;
	int i;

	printf("Enter a 24-hour time: ");
	scanf("%d:%d", &input_hour, &input_minute);

	converted_time = input_hour * 60 + input_minute;

	for(i = 0; i < TIME_SIZE; i++) {
		if(converted_time <= departure_times[i]) {
			if(i == 0) {
				compare_with_past = (1440 - departure_times[TIME_SIZE - 1]) + converted_time;
				compare_with_comming = converted_time - departure_times[i];

				past_departure_time = departure_times[TIME_SIZE - 1];
				past_arrival_time = arrival_times[TIME_SIZE - 1];
				comming_departure_time = departure_times[i];
				comming_arrival_time = arrival_times[i];
			} else if(i == TIME_SIZE - 1) {
				compare_with_past = converted_time - departure_times[TIME_SIZE - 1];
				compare_with_comming = (1440 - converted_time) + departure_times[1];

				past_departure_time = departure_times[TIME_SIZE - 1];
				past_arrival_time = arrival_times[TIME_SIZE - 1];
				comming_departure_time = departure_times[i];
				comming_arrival_time = arrival_times[i];
			} else {
				compare_with_past = converted_time - departure_times[i - 1];
				compare_with_comming = converted_time - departure_times[i];

				past_departure_time = departure_times[i - 1];
				past_arrival_time = arrival_times[i - 1];
				comming_departure_time = departure_times[i];
				comming_arrival_time = arrival_times[i];
			}

			if(compare_with_past < 0)
				compare_with_past = -compare_with_past;
			if(compare_with_comming < 0)
				compare_with_comming = -compare_with_comming;

			if(compare_with_past < compare_with_comming) {
				departure_time = past_departure_time;
				arrival_time = past_arrival_time;
			} else {
				departure_time = comming_departure_time;
				arrival_time = comming_arrival_time;
			}


			break;
		}
	}

	printf("Closest departure time is %d:%.2d %s, arriving at %d:%.2d %s\n", 
	departure_time / 60,
	departure_time % 60,
	(departure_time / 60 < 12 ? "a.m." : "p.m."),
	arrival_time / 60,
	arrival_time % 60,
	(arrival_time / 60 < 12 ? "a.m." : "p.m."));
	
	return 0;
}
