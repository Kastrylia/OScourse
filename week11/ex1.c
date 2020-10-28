#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main() {
	char *addr;
	struct stat buf;
	int fd = open("ex1.txt", O_RDWR);
	if (fstat(fd, &buf)) {
		return -1;
	}
	addr = mmap(NULL, buf.st_size, PROT_WRITE, MAP_SHARED, fd, 0);
	strncpy(addr, "This is a nice day", buf.st_size);
	munmap(addr, buf.st_size);
	close(fd);
	return 0;
}