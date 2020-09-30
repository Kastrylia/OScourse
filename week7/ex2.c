#include <stdio.h>
#include <stdlib.h>

int main() 
{
	int n = 0;
	int *arr;
	scanf("%d", &n);
	arr = malloc(n*sizeof(int));
	for (int i = 0; i < n; ++i)
	{
		arr[i] = i;
	}

	printf("\n");
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", arr[i]);
	}
	
	free(arr);
	exit(EXIT_SUCCESS);
}