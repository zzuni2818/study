#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define NUM_CARDS 5
#define RANK 0
#define SUIT 1

int hand[NUM_CARDS][2];

bool straight, flush, four, three;
int pairs;

void read_cards();
void analyze_hand();
void print_result();

int main()
{
	for(;;) {
		read_cards();
		analyze_hand();
		print_result();
	}
	return 0;
}

void read_cards()
{
	char ch, rank_ch, suit_ch;
	int i, rank, suit;
	bool bad_card, is_duplicated;
	int cards_read = 0;

	while(cards_read < NUM_CARDS) {
		bad_card = false;
	
		printf("Enter a card: ");

		rank_ch = getchar();
		switch(rank_ch) {
		case '0':
			exit(EXIT_SUCCESS);
		case '2':
			rank = 0;
			break;
		case '3':
			rank = 1;
			break;
		case '4':
			rank = 2;
			break;
		case '5':
			rank = 3;
			break;
		case '6':
			rank = 4;
			break;
		case '7':
			rank = 5;
			break;
		case '8':
			rank = 6;
			break;
		case '9':
			rank = 7;
			break;
		case 't':
		case 'T':
			rank = 8;
			break;
		case 'j':
		case 'J':
			rank = 9;
			break;
		case 'q':
		case 'Q':
			rank = 10;
			break;
		case 'k':
		case 'K':
			rank = 11;
			break;
		case 'a':
		case 'A':
			rank = 12;
			break;
		default:
			bad_card = true;
		}
	
		suit_ch = getchar();
		switch(suit_ch) {
		case 'c':
		case 'C':
			suit = 0;
			break;
		case 'd':
		case 'D':
			suit = 1;
			break;
		case 'h':
		case 'H':
			suit = 2;
			break;
		case 's':
		case 'S':
			suit = 3;
			break;
		default:
			bad_card = true;
		}

		while((ch = getchar()) != '\n') {
			if(ch != ' ') {
				bad_card = true;
			}
		}

		if(bad_card) {
			printf("Bad card; ignored.\n");
			continue;
		}

		is_duplicated = false;
		for(i = 0; i < NUM_CARDS; i++) {
			if(hand[i][RANK] == rank && hand[i][SUIT] == suit) {
				is_duplicated = true;
				break;
			}
		}

		if(is_duplicated) {
			printf("Duplicate card; ignored.\n");
		} else {
			hand[cards_read][RANK] = rank;
			hand[cards_read][SUIT] = suit;
			cards_read++;
		}
	}
}
void analyze_hand()
{
	int card, rank, suit;
	int i, j, min, same_rank_count;

	straight = true;
	flush = true;
	four = false;
	three = false;
	pairs = 0;

	// sort order by asc to check wheter straight
	for(i = 0; i < NUM_CARDS - 1; i++) {
		rank = hand[i][RANK];
		suit = hand[i][SUIT];
	
		min = i;
		for(j = i + 1; j < NUM_CARDS; j++) {
			if(hand[min][RANK] > hand[j][RANK]) {
				min = j;
			}
		}

		hand[i][RANK] = hand[min][RANK];
		hand[i][SUIT] = hand[min][SUIT];
		hand[min][RANK] = rank;
		hand[min][SUIT] = suit;
	}


	suit = hand[0][SUIT];
	for(card = 1; card < NUM_CARDS; card++) {
		if(hand[card][SUIT] != suit) {
			flush = false;
			break;
		}
	}

	for(card = 0; card < NUM_CARDS - 1; card++) {
		if(hand[card][RANK] + 1 != hand[card + 1][RANK]) {
			straight = false;
			break;
		}
	}

	card = 0;
	while(card < NUM_CARDS) {
		rank = hand[card][RANK];
		same_rank_count = 0;

		do {
			same_rank_count++;
			card++;
		} while(card < NUM_CARDS && hand[card][RANK] == rank);	

		switch(same_rank_count) {
		case 2:
			pairs++;
			break;
		case 3:
			three = true;
			break;
		case 4:
			four = true;
			break;
		}
	}
}
void print_result()
{
	if(straight && flush) {
		printf("Straight flush");
	} else if(four) {
		printf("Four of a kind");
	} else if(three && pairs == 1) {
		printf("Full house");
	} else if(flush) {
		printf("Flush");
	} else if(straight) {
		printf("Straight");
	} else if(three) {
		printf("Three of a kind");
	} else if(pairs == 2) {
		printf("Two pairs");
	} else if(pairs == 1) {
		printf("Pairs");
	} else {
		printf("High card");
	}

	printf("\n\n");
}
