#include <stdio.h>
#include <stdlib.h>

int main()
{
	int* pointer;
	int size = 10,
	 iterator = 0;
	// use malloc() function to create size-size int array
	pointer = (int*)malloc(size * sizeof(int));
	for (iterator = 0; iterator < size; ++iterator) {
		pointer[iterator] = iterator + 1;
	}
	printf("The program created array of: ");
	for (iterator = 0; iterator < size; ++iterator) {
		printf("%d", pointer[iterator]);
		if (pointer[iterator] < 10) {
			printf(", ");
		}
	}
	free(pointer);
	printf("\nMemory freed.\n");
	return 0;
}
