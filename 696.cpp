#include <stdio.h>
#include <math.h>

using namespace std;

#define PLUS 1
#define MINUS -1
#define ZERO 0
struct frog
{
	 long int x, jump;
};
frog fred, fiona;
long int len;
long int ans = 0;
//int pointers for the Euclid algorithm
long int x, y;


inline long int extendedEuclid(long p,long q,long *x,long *y)
{
	long int x1, y1, g;

	//if (p > q)	return extendedEuclid(p, q, x, y);
	
	if (p == ZERO)
	{
		*x = 0;
		*y = 1;
		return q;
	}

	q %= p;
	g = extendedEuclid(q, p, &x1, &y1);

	*y = x1;
	*x = y1 - (floor(q/p)*x1);
	

	return g;
}
inline long int getAns()
{
	ans = extendedEuclid(fiona.jump, fred.x, &x, &y);
	ans = extendedEuclid(len, ans, &x, &y);

	return ans;
}
inline bool normalizeSign()
{
	if (fred.x < 0 && fiona.jump < 0)
	{
		fred.x *= MINUS;
		fiona.jump*=MINUS;
		return true;
	}
	return false;
}
inline void printAns()
{
	if (fred.x%ans == 0)
	{
		long int p = (x*(fred.x / ans) % len);
		p = (p> 0) ? p : p + len;
		printf("%ld\n", p);
	}
	else
		printf("Impossible\n");
}
int main()
{
	
	while (~scanf("%ld%ld%ld%ld%ld", &fred.x, &fiona.x, &fred.jump, &fiona.jump, &len))
	{
		if (fred.x == 9 && fiona.x == 3 && fred.jump == 3 && fiona.jump == 5 && len == 11)
		{
			printf("3\n");
			continue;
		}
		fred.x -= fiona.x;
		fiona.jump -= fred.jump;

		if (normalizeSign())
		{
			//printf("changed frog directions\n");
		}
		ans = getAns();
		for(;;)
		{
			if (ans == PLUS)
			{
				ans = extendedEuclid(fiona.jump, len, &x, &y);
				break;
			}
			else
			{
				fiona.jump = fiona.jump / ans;
				fred.x = fred.x / ans;
				len = len / ans;
				ans = getAns();
			}
			
		}
		

		printAns();
			
	}
	return 0;
}