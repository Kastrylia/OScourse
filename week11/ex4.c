#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main() {
	char *src, *tar;
	struct stat buf;
	int sfd = open("ex1.txt", O_RDONLY);
	int tarfd = open("ex1.memcp.txt", O_CREAT | O_RDWR);
	if (fstat(sfd, &buf)) {
		return -1;
	}
	s = mmap(NULL, buf.st_size, PROT_READ, MAP_SHARED, sfd, 0);
	ftruncate(tarfd, buf.st_size);
	tar = mmap(NULL, buf.st_size, PROT_WRITE, MAP_SHARED, tarfd, 0);
	memcpy(tar, src, buf.st_size);
	munmap(src, buf.st_size);
	munmap(tar, buf.st_size);
	close(sfd);
	close(tarfd);
	return 0;
}