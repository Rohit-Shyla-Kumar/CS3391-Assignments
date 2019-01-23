#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std; 
inline long long int getAns(long long int a, long long int b,long long int m)
{
	long long int temp = 1;
	if (b == 0);
	else if (b == 1) return a;
	else if (b & 1) {
		temp = (a%m);
		temp*=getAns(a, (b - 1), m);	
	}
	else
	{
		temp = getAns(a, b / 2, m);
		temp = ((temp%m)*(temp%m));
	}
	temp %= m;
	return temp;
}
int main()
{
	long long int b, p, m;
	while (~(scanf("%lld%lld%lld", &b, &p, &m)))
	{
		if (b == 0)
		{
			printf("0\n");
			continue;
		}
		long long int ans;
		ans = getAns(b,p,m);
		printf("%lld\n",ans);
	}
}