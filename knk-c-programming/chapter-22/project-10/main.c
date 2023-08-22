#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "readline.h"

#define NAME_LEN 25

struct part {
	int number;
	char name[NAME_LEN + 1];
	int on_hand;
	struct part *next;
};

int num_parts = 0;

struct part *inventory = NULL;

struct part *find_part(int number);
void insert();
void search();
void update();
void print();
void dump();
void restore();

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
		case 'd':
			dump();
			break;
		case 'r':
			restore();
			break;
		case 'q':
			return 0;
		default:
			printf("Illegal code\n");
		}
	}
	printf("\n");

	return 0;
}

struct part *find_part(int number)
{
	struct part *p;

	for(p = inventory; p != NULL && p->number < number; p = p->next)
		;
	if(p != NULL && number == p->number) {
		return p;
	}

	return NULL;
}
void insert()
{
	struct part *cur, *prev, *new_node;

	new_node = malloc(sizeof(struct part));
	if(new_node == NULL) {
		printf("Database is full; can't add more parts.\n");
		return;
	}

	printf("Enter part number: ");
	scanf("%d", &new_node->number);

	for(cur = inventory, prev = NULL;
		cur != NULL && cur->number < new_node->number;
		prev = cur, cur = cur->next)
		;

	if(cur != NULL && new_node->number == cur->number) {
		printf("Part already exits.\n");
		free(new_node);
		return;
	}

	printf("Enter part name: ");
	read_line(new_node->name, NAME_LEN);
	printf("Enter quantity on hand: ");
	scanf("%d", &new_node->on_hand);

	new_node->next = cur;
	if(prev == NULL) {
		inventory = new_node;
	} else {
		prev->next = new_node;
	}

	num_parts++;
}
void search()
{
	int number;
	struct part *p;
	
	printf("Enter part number: ");
	scanf("%d", &number);
	p = find_part(number);
	if(p != NULL) {
		printf("Part name: %s\n", p->name);
		printf("Quantity on hand: %d\n", p->on_hand);
	} else {
		printf("Part not found.\n");
	}
	
}
void update()
{
	int number, change;
	struct part *p;

	printf("Enter part number: ");
	scanf("%d", &number);
	p = find_part(number);
	if(p != NULL) {
		printf("Enter change in quantity on hand: ");
		scanf("%d", &change);
		p->on_hand += change;
	} else {
		printf("Part not found.\n");
	}
}
void print()
{
	struct part *p;

	printf("Part Number    Part Name                         "
		   "Quantity on Hand\n");

	for (p = inventory; p != NULL; p = p->next) {
		printf("%7d        %-25s%11d\n",
				p->number,
				p->name,
				p->on_hand);
	}
}
void dump()
{
	FILE *fp;
	char filename[FILENAME_MAX];
	struct part *p;
	bool is_fail_dump = false;

	printf("Enter name of output file: ");
	scanf("%s", filename);

	if((fp = fopen(filename, "wb")) == NULL) {
		printf("Can't open %s\n", filename);
		return;
	}

	if(fwrite(&num_parts, sizeof(int), 1, fp) != 1) {
		is_fail_dump = true;
	} else {
		for(p = inventory; p != NULL; p = p->next) {
			if(fwrite(&p->number, sizeof(int), 1, fp) != 1
				|| fwrite(&p->name, NAME_LEN + 1, 1, fp) != 1
				|| fwrite(&p->on_hand, sizeof(int), 1, fp) != 1) {
				is_fail_dump = true;
				break;
			}
		}
	}
	
	if(is_fail_dump) {
		printf("Failed to dump\n");
		fclose(fp);
		remove(filename);
		return;
	}

	fclose(fp);
}
void restore()
{
	FILE *fp;
	struct part *cur, *new_node;
	char filename[FILENAME_MAX];
	bool is_fail_load = false;
	int i;

	printf("Enter name of input file: ");
	scanf("%s", filename);

	if((fp = fopen(filename, "rb")) == NULL) {
		printf("Can't open %s\n", filename);
		return;
	}

	if(fread(&num_parts, sizeof(int), 1, fp) != 1) {
		is_fail_load = true;
	} else {
		for(i = 0; i < num_parts; i++) {
			new_node = malloc(sizeof(struct part));
			if(new_node == NULL) {
				is_fail_load = true;
				break;
			}

			if(fread(&new_node->number, sizeof(int), 1, fp) != 1
				|| fread(&new_node->name, NAME_LEN + 1, 1, fp) != 1
				|| fread(&new_node->on_hand, sizeof(int), 1, fp) != 1) {
				is_fail_load = true;
				free(new_node);
				break;
			}

			new_node->next = NULL;
			if(inventory == NULL) {
				inventory = new_node;
			} else {
				cur->next = new_node;
			}
			cur = new_node;
		}
	}

	if(is_fail_load) {
		printf("Failed to load\n");

		cur = inventory;
		while(cur != NULL) {
			new_node = cur;
			cur = cur->next;

			free(new_node);		
		}
		num_parts = 0;
		inventory = NULL;

		fclose(fp);
		return;
	}

	fclose(fp);
}
