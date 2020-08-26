#include <string.h>
#include <stdio.h>
#include<float.h>
#include <limits.h>
int main (int argc, char *argv[])
{
  int n;
  sscanf (argv[1], "%d", &n);
  for (int i = 1; i <= n-1; ++i)
    {
        int spaces=n-i-1;
        int stars=2*i-1;
        while (spaces>0)
        {
            putchar(' ');
            spaces--;
        }
        while (stars>0)
        {
            putchar('*');
           stars--;
        }
      putchar('\n');
    }
  return 0;
}
