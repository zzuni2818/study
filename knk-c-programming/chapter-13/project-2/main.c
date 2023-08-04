#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50
#define MSG_LEN 60

int read_line(char str[], int n);

int main()
{
	char reminders[MAX_REMIND][MSG_LEN + 11]; // MSG_LEN + month/day (5) + hour/minut (5) + '\0' (1)
	char day_str[6], time_str[6], msg_str[MSG_LEN + 1];
	int month, day, hour, minute, i, j, num_remind = 0;

	for(;;) {
		if(num_remind == MAX_REMIND) {
			printf("--No space left --\n");
			break;
		}

		printf("Enter day(month/day) and 24-hour time and reminder: ");
		scanf("%d/%d", &month, &day);
		if(month == 0 || day == 0) {
			break;
		} else if(month < 0 || month > 12 || day < 0 || day > 31) {
			printf("Invalid day: %d/%.2d\n", month, day);
			while(getchar() != '\n');
			continue;
		}
		sprintf(day_str, "%2d/%.2d", month, day);

		scanf("%d:%d", &hour, &minute);
		if(hour < 0 || hour > 24 || minute < 0 || minute > 59) {
			printf("Invalid time: %d:%.2d\n", hour, minute);
			while(getchar() != '\n');
			continue;
		}
		sprintf(time_str, "%2d:%.2d", hour, minute);

		read_line(msg_str, MSG_LEN);

		for(i = 0; i < num_remind; i++) {
			if(strcmp(day_str, reminders[i]) < 0) {
				break;
			}
		}
		for(j = num_remind; j > i; j--) {
			strcpy(reminders[j], reminders[j-1]);
		}

		strcpy(reminders[i], day_str);
		strcat(reminders[i], " ");
		strcat(reminders[i], time_str);
		strcat(reminders[i], msg_str);
		
		num_remind++;
	}

	//printf("\nDay Time Reminder\n");
	printf("\n %-5s %-5s %s\n", "Day", "Time", "Reminder");
	for(i = 0; i < num_remind; i++) {
		printf(" %s\n", reminders[i]);
	}	

	return 0;
}

int read_line(char str[], int n)
{
	int ch, i = 0;
	
	while((ch = getchar()) != '\n') {
		if(i < n) {
			str[i++] = ch;
		}
	}
	str[i] = '\0';

	return i;
}
