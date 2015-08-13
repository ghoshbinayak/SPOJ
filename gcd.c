#include "stdio.h"

int gcd ( int a, int b )
{
  int c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
     printf("%d %d %d\n", a, b, c);
  }
  return b;
}

int main(int argc, char const *argv[])
{
	printf("%d\n", gcd(12, 5));
	return 0;
}