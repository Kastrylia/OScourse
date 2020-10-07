#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/resource.h>
int main() 
{
	struct rusage t;
	for (int i = 0; i < 10; ++i) {
		// Allocate 10MB
		void *ptr = malloc(10485760);
		memset(ptr, 0, 10485760); 
		if (getrusage(RUSAGE_SELF, &t) == 0) 
		{
		    printf("%ld KB\n", t.ru_maxrss);
		    
		}
		else return 1;
		sleep(1);
	}
	return 0;
}