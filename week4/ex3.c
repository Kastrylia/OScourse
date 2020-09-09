#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
	char command[200];
	while (scanf("%s", command) > 0) 
	{
		system(command);
	}

	return 0;
}