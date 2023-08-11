#include <stdio.h>
#include <stdlib.h>
#include "readline.h"

#define NAME_LEN 25
#define MAX_PARTS 100

struct part {
	int number;
	char name[NAME_LEN + 1];
	int on_hand;
} inventory[MAX_PARTS];

int num_parts = 0;

int find_part(int number);
void insert();
void search();
void update();
void print();

int compare_part(const void *p, const void *q);

int main()
{
	char code;

	for(;;) {
		printf("Enter operation code: ");
		scanf(" %c", &code);
		while(getchar() != '\n')
			;
		switch(code) {
		case 'i':
			insert();
			break;
		case 's':
			search();
			break;
		case 'u':
			update();
			break;
		case 'p':
			print();
			break;
		case 'q':
			return 0;
		default:
			printf("Illegal code\n");
		}
		printf("\n");
	}

	return 0;
}

int find_part(int number)
{
	int i;

	for(i = 0; i < num_parts; i++) {
		if(inventory[i].number == number) {
			return i;
		}
	}

	return -1;
}
void insert()
{
	int part_number, offset, i;
	struct part new_part;

	if(num_parts == MAX_PARTS) {
		printf("Database is full; can't add more parts.\n");
		return;
	}

	printf("Enter part number: ");
	scanf("%d", &part_number);
	
	if(find_part(part_number) >= 0) {
		printf("Part already exists.\n");
		return;
	}

	new_part.number = part_number;
	printf("Enter part name: ");
	read_line(new_part.name, NAME_LEN);
	printf("Enter quantity on hand: ");
	scanf("%d", &new_part.on_hand);

	for(offset = 0; offset < num_parts; offset++) {
		if(new_part.number < inventory[offset].number) {
			break;
		}
	}

	for(i = num_parts; i > offset; i--) {
		inventory[i] = inventory[i - 1];
	}
	inventory[offset] = new_part;

	num_parts++;
}
void search()
{
	int i, number;

	printf("Enter part number: ");
	scanf("%d", &number);
	i = find_part(number);
	if(i >= 0) {
		printf("Part name: %s\n", inventory[i].name);
		printf("Quantity on hand: %d\n", inventory[i].on_hand);
	} else {
		printf("Part not found.\n");
	}
}
void update()
{
	int i, number, change;

	printf("Enter part number: ");
	scanf("%d", &number);
	i = find_part(number);
	if(i >= 0) {
		printf("Enter change in quantity on hand: ");
		scanf("%d", &change);
		inventory[i].on_hand += change;
	} else {
		printf("Part not found.\n");
	}
}
void print()
{
	int i;

	qsort(inventory, num_parts, sizeof(struct part), compare_part);

	printf("Part Number    Part Name                         "
		   "Quantity on Hand\n");

	for (i = 0; i < num_parts; i++)
		printf("%7d        %-25s%11d\n",
				inventory[i].number,
				inventory[i].name,
				inventory[i].on_hand);
}

int compare_part(const void *p, const void *q)
{
	const struct part *p1 = p;
	const struct part *p2 = q;

	if(p1->number == p2->number) {
		return 0;
	}
	return p1->number < p2->number ? -1 : 1;
}
