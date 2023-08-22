#include <stdio.h>
#include <stdlib.h>

#define FLIGHT_TIME_SIZE 8
#define LINE_SIZE 100

struct flight_time {
	int departure_time;
	int arrival_time;
};

struct flight_time flight_times[FLIGHT_TIME_SIZE];

int main(int argc, char *argv[])
{
	FILE *fp;
	int input_hour, input_minute, converted_time, 
		compare_with_past, compare_with_comming,
		past_departure_time, past_arrival_time,
		comming_departure_time, comming_arrival_time,
		load_departure_hour, load_departure_minute,
		load_arrival_hour, load_arrival_minute,
		i;
	char line[LINE_SIZE + 1];
	struct flight_time closest_time;

	if(argc < 2) {
		fprintf(stderr, "usage: [filename]\n");
		exit(EXIT_FAILURE);
	}

	if((fp = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	for(i = 0; i < FLIGHT_TIME_SIZE && fgets(line, LINE_SIZE, fp) != NULL; i++) {
		sscanf(line, "%d:%d %d:%d", 
			&load_departure_hour, &load_departure_minute, 
			&load_arrival_hour, &load_arrival_minute);
		printf("%d:%d %d:%d\n", load_departure_hour, load_departure_minute, load_arrival_hour, load_arrival_minute);

		flight_times[i].departure_time = (load_departure_hour * 60) + load_departure_minute;
		flight_times[i].arrival_time = (load_arrival_hour * 60) + load_arrival_minute;
	}

	fclose(fp);

	printf("Enter a 24-hour time: ");
	scanf("%d:%d", &input_hour, &input_minute);

	converted_time = input_hour * 60 + input_minute;
	for(i = 0; i < FLIGHT_TIME_SIZE; i++) {
		if(converted_time <= flight_times[i].departure_time) {
			if(i == 0) {
				compare_with_past = (1440 - flight_times[FLIGHT_TIME_SIZE - 1].departure_time) + converted_time;
				compare_with_comming = converted_time - flight_times[i].departure_time;

				past_departure_time = flight_times[FLIGHT_TIME_SIZE - 1].departure_time;
				past_arrival_time = flight_times[FLIGHT_TIME_SIZE - 1].arrival_time;
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
			if(i == FLIGHT_TIME_SIZE - 1) {
				compare_with_past = converted_time - flight_times[FLIGHT_TIME_SIZE - 1].departure_time;
				compare_with_comming = (1440 - converted_time) + flight_times[0].departure_time;

				past_departure_time = flight_times[FLIGHT_TIME_SIZE - 1].departure_time;
				past_arrival_time = flight_times[FLIGHT_TIME_SIZE - 1].arrival_time;
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
