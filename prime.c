#include "stdio.h"


int gcd(int, int);
int phi(const int);

int main(int argc, char const *argv[])
{
	FILE * input;
	input = fopen('test.txt', "r");

	int n;
	long int lowerlim, upperlim;
	long int b, found, r, maxk, nextR, gcda, toir;
	double logresult, a, npowk;
	fscanf(input, "%d", &n);

	while(n > 0){
		fscanf(input, "%d %d", lowerlim, upperlim);
		while(lowerlim <= upperlim) {
			logresult = log2(lowerlim);
			for (b = 0; b < logresult; ++b) {
				a = pow(n, 1.0/b);
				if(a == (int )a){
					printf("%s\n", "composite");
					printf("%d\n", (int) a);
					found = 1;
					break;
				}
			}
			if (!found) {
				maxk = abs(pow(log2(lowerlim), 2));
				r = 2;
				nextR = 1;
				for (r = 2, nextR && r < maxk, r++ ){
					nextR = 0;
					for (k = 1; (!nextR) k <= maxk, ++k) {
						npowk = (int)pow(lowerlim, k);
						nextR = (((int)fmodf(npowk, r)) == 1 ||((int)fmodf(npowk, r)) == 0);
					}
				}
				r--;
				for (a = r; a > 1; a--) {
					gcda = gcd(a, lowerlim);
					if (gcda > 1 && gcd < lowerlim){
						found = 1;
						printf("%s\n", "composite");
						printf("%d\n", a);
						break;
					}
				}
			}

			if (!found) {
				if (n <= r) {
					found = 1;
					printf("%s\n", "prime");
					printf("%d\n", lowerlim);
				}
			}

			if (!found)	{
				toir = (int )floor(sqrt(phi(r))log(lowerlim));
				for(a = 1; a <= toir; a++) {
					if (/* condition */)
					{
						/* code */
					}
				}
			}

			lowerlim ++			
		}
		n--;
	}

	return 0;
}

int gcd( int a, int b ) {
  int c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}

int phi(const int n)
{
  // Base case
  if ( n < 2 )
    return 0;

  // Lehmer's conjecture
  if ( isprime(n) )
    return n-1;

  // Even number?
  if ( n & 1 == 0 ) {
    int m = n >> 1;
    return !(m & 1) ? phi(m)<<1 : phi(m);
  }

  // For all primes ...
  for ( std::vector<int>::iterator p = primes.begin();
        p != primes.end() && *p <= n;
        ++p )
  {
    int m = *p;
    if ( n % m  ) continue;

    // phi is multiplicative
    int o = n/m;
    int d = binary_gcd(m, o);
    return d==1? phi(m)*phi(o) : phi(m)*phi(o)*d/phi(d);
  }
}