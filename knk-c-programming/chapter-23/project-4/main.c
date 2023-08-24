#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

int main()
{
	char temp, buffer[BUFFER_SIZE + 1];
	char *word;
	int front, rear;
	size_t word_length;
	
	printf("Enter a series of words(separated by single spaces): ");
	if(fgets(buffer, BUFFER_SIZE, stdin) == NULL) {
		fprintf(stderr, "Failed to read.\n");
		exit(EXIT_FAILURE);
	}

	buffer[strlen(buffer) - 1] = '\0';
	
	word = strtok(buffer, " ");
	while(word != NULL) {
		word_length = strlen(word);
		for(front = 0, rear = word_length - 1; front < rear; front++, rear--) {
			temp = word[front];
			word[front] = word[rear];
			word[rear] = temp;
		}
		printf("%s ", word);

		word = strtok(NULL, " ");
	}
	puts("");

	return 0;
}
