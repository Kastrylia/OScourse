#include <stdio.h>
#include<float.h>
#include <limits.h>
int main()
{
  int a;
  float b;
  double c;
  a=INT_MAX;
  b = FLT_MAX;
  c = DBL_MAX;
  printf("%d %lu\n", a, sizeof(a));
  printf("%g %lu\n", b, sizeof(b));
  printf("%g %lu\n", c, sizeof(c));
  return 0;
}
