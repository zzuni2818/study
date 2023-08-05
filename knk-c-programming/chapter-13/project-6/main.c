#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_PLANETS 9

int compare_ignore_case(const char *str1, const char *str2);

int main(int argc, char *argv[])
{
	char *planets[] = {"Mercury", "Venus", "Earth", 
						"Mars", "Jupiter", "Saturn", 
						"Uranus", "Neptune", "Pluto"};
	int i, j;

	for(i = 1; i < argc; i++) {
		for(j = 0; j < NUM_PLANETS; j++) {
			if(compare_ignore_case(argv[i], planets[j]) == 0) {
				printf("%s is planet %d\n", argv[i], j + 1);
				break;
			}
		}
		if(j == NUM_PLANETS) {
			printf("%s is not a planet\n", argv[i]);
		}
	}

	return 0;
}

int compare_ignore_case(const char *str1, const char *str2)
{
	while(toupper(*str1) == toupper(*str2)) {
		if(*str1 == '\0' && *str2 == '\0') {
			return 0;
		}
		if(*str1 == '\0' || *str2 == '\0') {
			break;
		}
		str1++;
		str2++;
	}

	return *str1 - *str2;
}
