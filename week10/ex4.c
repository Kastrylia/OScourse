#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>


int main(int argc, char *argv[]) {
	errno = 0;
	DIR *dirp = opendir("./tmp/");
	struct dirent *dp;
	struct stat sb;
	char full_name[255];
	FILE *fp = fopen("ex4.txt", "w");
	
	while ((dp = readdir(dirp)) != NULL) {
		snprintf(full_name, sizeof(full_name), "%s%s", "./tmp/", dp->d_name);
		if (sb.st_nlink >= 2) {
			fprintf(fp, "%s\n", full_name);
		}
	}
	fclose(fp);
	return 0;
}