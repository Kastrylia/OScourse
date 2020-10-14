#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

struct frame {
	unsigned char age;	
	int page_number;
}*frames;


long n_frames;		
FILE *input;		
long hit = 0;		
long miss = 0;		


void get_n_frames(int argc, char *argv[]) {
	char *endptr;
	errno = 0;
	if (argc != 2) {
		return 1;
	}
	n_frames = strtol(argv[1], &endptr, 10);
}

void aging(int next_page) {
	long min_index = 0;
	for (long i = 0; i < n_frames; ++i) {
		if (frames[i].age < frames[min_index].age) {
			min_index = i;
		}
		frames[i].age = frames[i].age >> 1;
	}

	for (long i = 0; i < n_frames; ++i) {
		if (frames[i].page_number == next_page) {
			frames[i].age = frames[i].age | (1 << 7);
			hit++;
			return;
		}
	}
	miss++;
	frames[min_index].age = 1 << 7;
	frames[min_index].page_number = next_page;
}

void open_file(char *name) {
	input = fopen(name, "r");
}

int main(int argc, char *argv[]) {
	get_n_frames(argc, argv);

	frames = malloc(n_frames*sizeof(struct frame));
	for (long i = 0; i < n_frames; ++i) {
		frames[i].age = 0;
		frames[i].page_number = -1;
	}
	
	open_file("input.txt");	

	int next_page;
	while (fscanf(input, "%d", &next_page) != EOF) {
		aging(next_page);
	}

	printf("Hits\t%ld\n", hit);
        printf("Misses\t%ld\n", miss);
        printf("Hits:Misses\t%lf\n", (double)hit/(double)miss);

	free(frames);
	return 0;
}