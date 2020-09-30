#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void *my_realloc(void *ptr, size_t size) {
	if (ptr == NULL) {
		return malloc(size);
	} else if (size == 0) {
		free(ptr);
		return NULL;
	} else {
		char *new = malloc(size);
		if (new) {
			memcpy(new, (char *)ptr, size);
		}
		free(ptr);
		return new;
	}
}

void print(int *arr, int n) {
	for (int i = 0; i < n; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main() {
	// Testing
	printf("Ininital Array: ");
	int *arr = calloc(10, sizeof(int));
	print(arr, 10);

	printf("Increased-size Array: "); 
	arr = my_realloc(arr, 15*sizeof(int));
	print(arr, 15);

	printf("Decreased-size Array: ");
	arr = my_realloc(arr, 5*sizeof(int));
	print(arr, 5);

	printf("Free Array!\n");
	arr = my_realloc(arr, 0);

	printf("Array: ");
	arr = my_realloc(NULL, 10*sizeof(int));
	print(arr, 10);

	return 0;
}