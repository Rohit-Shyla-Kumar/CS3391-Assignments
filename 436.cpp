#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>
#include <string.h>

#define N 1000000
#define SQRT_N 1000
#define HALF_SQRT_N 500

using namespace std;
int ctr = 1;
long int primes[SQRT_N];
bool bits[1000000];
inline bool isCircularPrime(long num)
{
	bool flag = false;
	int len = to_string(num).length();
	for (int i = 0; i < len; i++)
	{
		if (!(bits[num] == 1))
			return false;
		int div = (int)(pow(10, len - 1));
		long temp = (num % div) * 10;
		int temp1 = num / div;
		//cout <<"temp and temp1" << temp << " " << temp1 << endl;
		num = temp + temp1;
	}
	return true;
}
inline bool isPrime(long n)
{
	long int i = 0;
	while (i < ctr)
	{
		if (n%primes[i] == 0) return false;
		i++;
	}
	if ((n - 3) / 2 < HALF_SQRT_N) {
		primes[ctr++] = n;
	}
	bits[n] = 1;
	return true;
}

int main()
{
	memset(primes, 0, sizeof(primes));
	memset(bits, 0, sizeof(bits));
	primes[0] = 3;
	for (int k = 5; k < N; k += 2)
		isPrime(k);

	int i, j;
	while (~(scanf("%d", &i)))
	{
		if (i == -1)
			return 0;
		scanf("%d", &j);
		if ((i & 1) == 0)
			i += 1;
		if ((j & 1) == 0)
			j -= 1;
		int lol = 0;
		for (int k = i; k <= j; k += 2)
		{
			if (bits[k] == 1)
				if (isCircularPrime(k)) lol++;
		}

		if (lol == 0) printf("No Circular Primes.\n");
		else if (lol == 1) printf("1 Circular Prime.\n");
		else printf("%d Circular Primes.\n", lol);
	}
	return 0;
}