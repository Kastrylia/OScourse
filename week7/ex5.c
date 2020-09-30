#include <stdio.h>
#include <stdlib.h> 	

int main() {
	char **s;
	char foo[] = "Hello World";
	/* We cant use variable before it is allocated */
	s = malloc(sizeof(char *));
	*s = foo;
	/*string pointed by *s  can be printed out by using *s instead s  */
	printf("*s is %s\n", *s);
	s[0] = foo;
	printf("s[0] is %s\n", s[0]);
	return(0);
}
