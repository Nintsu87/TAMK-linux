#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *file;
	char read[3];
	// try opening the file for reading
	if (file = fopen("task3Write.txt", "r")) {
		fgets(read, 3, file);
		fseek(file, 0, SEEK_SET);
		fclose(file);
		// if file have one char, print the file
		if (read[1] == '\0') {
			printf("Char in file: %s\n", read);
			return 0;
		} else { // if file has more than 1 char, create error
			perror("File is too big");
			return -1;
		}
	} else { // file failed to open
		perror("Failed opening the file.\n");
		return -1;
	}
}
