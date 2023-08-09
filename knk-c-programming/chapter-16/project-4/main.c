#include <stdio.h>
#include "readline.h"

#define NAME_LEN 25
#define MAX_PARTS 100

enum { UPDATE_PRICE, UPDATE_QUANTITY };

struct part {
	int number;
	char name[NAME_LEN + 1];
	int price;
	int on_hand;
} inventory[MAX_PARTS];

int num_parts = 0;

int find_part(int number);
void insert();
void search();
void update(int type);
void print();

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
			printf("Enter operation code(p: price, q: quantity): ");
			scanf(" %c", &code);
			if(code == 'p') {
				update(UPDATE_PRICE);
			} else if(code == 'q') {
				update(UPDATE_QUANTITY);
			} else {
				printf("Illegal code\n");
			}
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
	printf("Enter part price: ");
	scanf("%d", &new_part.price);
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
		printf("Part price: %d\n", inventory[i].price);
		printf("Quantity on hand: %d\n", inventory[i].on_hand);
	} else {
		printf("Part not found.\n");
	}
}
void update(int type)
{
	int i, number, change;

	printf("Enter part number: ");
	scanf("%d", &number);
	i = find_part(number);
	if(i >= 0) {
		switch(type) {
		case UPDATE_PRICE:
			printf("Enter change price: ");
			scanf("%d", &change);
			inventory[i].price = change;
			break;
		case UPDATE_QUANTITY:
			printf("Enter change in quantity on hand: ");
			scanf("%d", &change);
			inventory[i].on_hand += change;
			break;
		}
	} else {
		printf("Part not found.\n");
	}
}
void print()
{
	int i;

	printf("Part Number    Part Name                Price          "
		   "Quantity on Hand\n");

	for (i = 0; i < num_parts; i++)
		printf("%7d        %-25s%5d%11d\n",
				inventory[i].number,
				inventory[i].name,
				inventory[i].price,
				inventory[i].on_hand);
}
