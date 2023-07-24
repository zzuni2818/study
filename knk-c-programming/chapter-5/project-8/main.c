#include <stdio.h>

#define DEPARTURE_TIME_1 (8 * 60)
#define DEPARTURE_TIME_2 (9 * 60 + 43)
#define DEPARTURE_TIME_3 (11 * 60 + 19)
#define DEPARTURE_TIME_4 (12 * 60 + 47)
#define DEPARTURE_TIME_5 ((2 + 12) * 60)
#define DEPARTURE_TIME_6 ((3 + 12) * 60 + 45)
#define DEPARTURE_TIME_7 ((7 + 12) * 60)
#define DEPARTURE_TIME_8 ((9 + 12) * 60 + 45)

#define ARRIVAL_TIME_1 (10 * 60 + 16)
#define ARRIVAL_TIME_2 (11 * 60 + 52)
#define ARRIVAL_TIME_3 ((1 + 12) * 60 + 31)
#define ARRIVAL_TIME_4 ((3 + 12) * 60)
#define ARRIVAL_TIME_5 ((4 + 12) * 60 + 8)
#define ARRIVAL_TIME_6 ((5 + 12) * 60 + 55)
#define ARRIVAL_TIME_7 ((9 + 12) * 60 + 20)
#define ARRIVAL_TIME_8 ((11 + 12) * 60 + 58)

int main()
{
	int input_hour, input_minute, converted_time, 
		departure_time, arrival_time,
		compare_with_past, compare_with_comming;

	printf("Enter a 24-hour time: ");
	scanf("%d:%d", &input_hour, &input_minute);

	converted_time = input_hour * 60 + input_minute;

	if(converted_time < DEPARTURE_TIME_1) {
		//be carefull
		compare_with_past = (1440 - DEPARTURE_TIME_8) + converted_time;
		compare_with_comming = converted_time - DEPARTURE_TIME_1;

		if(compare_with_past < 0)
			compare_with_past = -compare_with_past;
		if(compare_with_comming < 0)
			compare_with_comming = -compare_with_comming;
		
		if(compare_with_past < compare_with_comming) {
			departure_time = DEPARTURE_TIME_8;
			arrival_time = ARRIVAL_TIME_8;
		} else {
			departure_time = DEPARTURE_TIME_1;
			arrival_time = ARRIVAL_TIME_1;
		}
	} else if(converted_time < DEPARTURE_TIME_2) {
		compare_with_past = converted_time - DEPARTURE_TIME_1;
		compare_with_comming = converted_time - DEPARTURE_TIME_2;

		if(compare_with_past < 0)
			compare_with_past = -compare_with_past;
		if(compare_with_comming < 0)
			compare_with_comming = -compare_with_comming;

		if(compare_with_past < compare_with_comming) {
			departure_time = DEPARTURE_TIME_1;
			arrival_time = ARRIVAL_TIME_1;
		} else {
			departure_time = DEPARTURE_TIME_2;
			arrival_time = ARRIVAL_TIME_2;
		}
	} else if(converted_time < DEPARTURE_TIME_3) {
		compare_with_past = converted_time - DEPARTURE_TIME_2;
		compare_with_comming = converted_time - DEPARTURE_TIME_3;

		if(compare_with_past < 0)
			compare_with_past = -compare_with_past;
		if(compare_with_comming < 0)
			compare_with_comming = -compare_with_comming;

		if(compare_with_past < compare_with_comming) {
			departure_time = DEPARTURE_TIME_2;
			arrival_time = ARRIVAL_TIME_2;
		} else {
			departure_time = DEPARTURE_TIME_3;
			arrival_time = ARRIVAL_TIME_3;
		}
	} else if(converted_time < DEPARTURE_TIME_4) {
		compare_with_past = converted_time - DEPARTURE_TIME_3;
		compare_with_comming = converted_time - DEPARTURE_TIME_4;

		if(compare_with_past < 0)
			compare_with_past = -compare_with_past;
		if(compare_with_comming < 0)
			compare_with_comming = -compare_with_comming;

		if(compare_with_past < compare_with_comming) {
			departure_time = DEPARTURE_TIME_3;
			arrival_time = ARRIVAL_TIME_3;
		} else {
			departure_time = DEPARTURE_TIME_4;
			arrival_time = ARRIVAL_TIME_4;
		}
	} else if(converted_time < DEPARTURE_TIME_5) {
		compare_with_past = converted_time - DEPARTURE_TIME_4;
		compare_with_comming = converted_time - DEPARTURE_TIME_5;

		if(compare_with_past < 0)
			compare_with_past = -compare_with_past;
		if(compare_with_comming < 0)
			compare_with_comming = -compare_with_comming;

		if(compare_with_past < compare_with_comming) {
			departure_time = DEPARTURE_TIME_4;
			arrival_time = ARRIVAL_TIME_4;
		} else {
			departure_time = DEPARTURE_TIME_5;
			arrival_time = ARRIVAL_TIME_5;
		}
	} else if(converted_time < DEPARTURE_TIME_6) {
		compare_with_past = converted_time - DEPARTURE_TIME_5;
		compare_with_comming = converted_time - DEPARTURE_TIME_6;

		if(compare_with_past < 0)
			compare_with_past = -compare_with_past;
		if(compare_with_comming < 0)
			compare_with_comming = -compare_with_comming;

		if(compare_with_past < compare_with_comming) {
			departure_time = DEPARTURE_TIME_5;
			arrival_time = ARRIVAL_TIME_5;
		} else {
			departure_time = DEPARTURE_TIME_6;
			arrival_time = ARRIVAL_TIME_6;
		}
	} else if(converted_time < DEPARTURE_TIME_7) {
		compare_with_past = converted_time - DEPARTURE_TIME_6;
		compare_with_comming = converted_time - DEPARTURE_TIME_7;

		if(compare_with_past < 0)
			compare_with_past = -compare_with_past;
		if(compare_with_comming < 0)
			compare_with_comming = -compare_with_comming;

		if(compare_with_past < compare_with_comming) {
			departure_time = DEPARTURE_TIME_6;
			arrival_time = ARRIVAL_TIME_6;
		} else {
			departure_time = DEPARTURE_TIME_7;
			arrival_time = ARRIVAL_TIME_7;
		}
	} else if(converted_time < DEPARTURE_TIME_8) {
		compare_with_past = converted_time - DEPARTURE_TIME_7;
		compare_with_comming = converted_time - DEPARTURE_TIME_8;

		if(compare_with_past < 0)
			compare_with_past = -compare_with_past;
		if(compare_with_comming < 0)
			compare_with_comming = -compare_with_comming;

		if(compare_with_past < compare_with_comming) {
			departure_time = DEPARTURE_TIME_7;
			arrival_time = ARRIVAL_TIME_7;
		} else {
			departure_time = DEPARTURE_TIME_8;
			arrival_time = ARRIVAL_TIME_8;
		}
	} else {
		compare_with_past = converted_time - DEPARTURE_TIME_8;
		//be carefull
		compare_with_comming = (1440 - converted_time) + DEPARTURE_TIME_1;

		if(compare_with_past < 0)
			compare_with_past = -compare_with_past;
		if(compare_with_comming < 0)
			compare_with_comming = -compare_with_comming;

		if(compare_with_past < compare_with_comming) {
			departure_time = DEPARTURE_TIME_8;
			arrival_time = ARRIVAL_TIME_8;
		} else {
			departure_time = DEPARTURE_TIME_1;
			arrival_time = ARRIVAL_TIME_1;
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
