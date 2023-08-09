#include <stdio.h>

struct flight_time {
	int departure_time;
	int arrival_time;
};

const struct flight_time flight_times[] = {
	{(8 * 60), (10 * 60 + 16)},
	{(9 * 60 + 43), (11 * 60 + 52)},
	{(11 * 60 + 19), ((1 + 12) * 60 + 31)},
	{(12 * 60 + 47), ((3 + 12) * 60)},
	{((2 + 12) * 60), ((4 + 12) * 60 + 8)},
	{((3 + 12) * 60 + 45), ((5 + 12) * 60 + 55)},
	{((7 + 12) * 60), ((9 + 12) * 60 + 20)},
	{((9 + 12) * 60 + 45), ((11 + 12) * 60 +58)}
};

int main()
{
	int input_hour, input_minute, converted_time,
		compare_with_past, compare_with_comming,
		past_departure_time, past_arrival_time,
		comming_departure_time, comming_arrival_time,
		i;
	struct flight_time closest_time;

	printf("Enter a 24-hour time: ");
	scanf("%d:%d", &input_hour, &input_minute);

	converted_time = input_hour * 60 + input_minute;

	const int flight_times_length = sizeof(flight_times) / sizeof(struct flight_time);

	for(i = 0; i < flight_times_length; i++) {
		if(converted_time <= flight_times[i].departure_time) {
			if(i == 0) {
				compare_with_past = (1440 - flight_times[flight_times_length - 1].departure_time) + converted_time;
				compare_with_comming = converted_time - flight_times[i].departure_time;

				past_departure_time = flight_times[flight_times_length - 1].departure_time;
				past_arrival_time = flight_times[flight_times_length - 1].arrival_time;
				comming_departure_time = flight_times[i].departure_time;
				comming_arrival_time = flight_times[i].arrival_time;
			} else {
				compare_with_past = converted_time - flight_times[i - 1].departure_time;
				compare_with_comming = converted_time - flight_times[i].departure_time;

				past_departure_time = flight_times[i - 1].departure_time;
				past_arrival_time = flight_times[i - 1].arrival_time;
				comming_departure_time = flight_times[i].departure_time;
				comming_arrival_time = flight_times[i].arrival_time;
			}

			if(compare_with_past < 0)
				compare_with_past = -compare_with_past;
			if(compare_with_comming < 0)
				compare_with_comming = -compare_with_comming;

			if(compare_with_past < compare_with_comming) {
				closest_time.departure_time = past_departure_time;
				closest_time.arrival_time = past_arrival_time;
			} else {
				closest_time.departure_time = comming_departure_time;
				closest_time.arrival_time = comming_arrival_time;
			}


			break;
		} else {
			if(i == flight_times_length - 1) {
				compare_with_past = converted_time - flight_times[flight_times_length - 1].departure_time;
				compare_with_comming = (1440 - converted_time) + flight_times[0].departure_time;

				past_departure_time = flight_times[flight_times_length - 1].departure_time;
				past_arrival_time = flight_times[flight_times_length - 1].arrival_time;
				comming_departure_time = flight_times[0].departure_time;
				comming_arrival_time = flight_times[0].arrival_time;

				if(compare_with_past < 0)
					compare_with_past = -compare_with_past;
				if(compare_with_comming < 0)
					compare_with_comming = -compare_with_comming;

				if(compare_with_past < compare_with_comming) {
					closest_time.departure_time = past_departure_time;
					closest_time.arrival_time = past_arrival_time;
				} else {
					closest_time.departure_time = comming_departure_time;
					closest_time.arrival_time = comming_arrival_time;
				}
			}
		}
	}

	printf("Closest departure time is %d:%.2d %s, arriving at %d:%.2d %s\n", 
	closest_time.departure_time / 60,
	closest_time.departure_time % 60,
	(closest_time.departure_time / 60 < 12 ? "a.m." : "p.m."),
	closest_time.arrival_time / 60,
	closest_time.arrival_time % 60,
	(closest_time.arrival_time / 60 < 12 ? "a.m." : "p.m."));

	return 0;
}
