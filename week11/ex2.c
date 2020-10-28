#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main() {
	for (int i = 0; i < 5; ++i) {
		printf("Hello");
		sleep(1);
	}
	return 0;
}