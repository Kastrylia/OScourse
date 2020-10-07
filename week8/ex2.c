#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main() 
{
	for (int i = 0; i < 10; ++i) 
	{
		void *ptr = malloc(10485760); //10 mb
		memset(ptr, 0, 10485760); 
		sleep(1);
	}
	return 0;
    
}

//if virtual memory is filled  and we cant acclocate new 10mb,then operating system puts it into swapped memory