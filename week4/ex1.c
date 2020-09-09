#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n=10;
	pid_t pid=fork();
	if(pid==0)
	{
		printf("Hello from child [%d-%d]\n",getpid(),n);
	}
	else
	{
		printf("Hello from parent [%d-%d]\n",getpid(),n);
	}
	return 0;
}
/* fork creates copy of process after taking pid.
if pid changes,than we are in child process,if not in parent */