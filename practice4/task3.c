#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *file; // pointer to a file
	char write[10];


	printf("Enter the one character: ");
	scanf("%s", write);

	// check if user give only 1 character
	if (write[1] == '\0') {

		file = fopen("task3Write.txt", "w");

		if (file == NULL) {
			perror("Failed opening the file.\n");
			exit(EXIT_FAILURE);
		} else {

			fputc(write[0], file);
			fclose(file);
			printf("\"%c\" wrote to the file and the file is closed.\n", write[0]);
		}
	} else {
		printf("Enter only a single character.\n");
	}

	return 0;
}
