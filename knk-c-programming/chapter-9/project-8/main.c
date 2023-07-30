#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int roll_dice(void);
bool play_game(void);

int main()
{
	int win_count = 0, lose_count = 0;
	char ch;
	bool is_running = true;

	srand((unsigned int) time(NULL));

	while(is_running) {
		if(play_game()) {
			printf("You win!\n");
			win_count++;
		} else {
			printf("You lose!\n");
			lose_count++;
		}

		printf("\nplay_again? ");
		ch = toupper(getchar());
		printf("\n");
		if(ch == 'N') {
			is_running = false;
		}
		while(getchar() != '\n');
	}
	printf("Wins:%d   Losses:%d\n", win_count, lose_count);

	return 0;
}

int roll_dice(void)
{
	int first, second;

	first = (rand() % 6) + 1;
	second = (rand() % 6) + 1;

	return first + second;
}
bool play_game(void)
{
	bool is_win;
	int point, rolled;

	point = roll_dice();
	printf("You rolled: %d\n", point);
	if(point == 7 || point == 11) {
		return true;
	} else if(point == 2 || point == 3 || point == 12) {
		return false;
	}

	printf("Your point is %d\n", point);

	while(1) {
		rolled = roll_dice();
		printf("You rolled: %d\n", rolled);

		if(rolled == point) {
			is_win = true;
			break;
		}

		if(rolled == 7) {
			is_win = false;
			break;
		}
	}
	return is_win;
}
