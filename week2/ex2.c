#include <string.h>
#include <stdio.h>
#include<float.h>
#include <limits.h>
int main()
{
  char str[100];
  fgets(str, 100, stdin);
  for (int i = strlen(str) - 1; i >-1 ; --i) printf("%c",str[i]);
  return 0;
}
