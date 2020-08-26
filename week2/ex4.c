#include <string.h>
#include <stdio.h>
#include<float.h>
#include <limits.h>
int main(void) 
{
	int a, b;
	scanf("%d %d", &a, &b);
	swap(&a, &b);
	return 0;
}
void swap(int *a, int *b) 
{
	int t = *a;
	*a = *b;
	*b = t;
}
