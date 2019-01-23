#include <stdio.h>
#include <math.h>
#include <algorithm>

#define EPSILON 0.0001
#define N 1440
#define TWO_PI 3.141592653*2
#define SUN 500
#define generateSunX(n) (sin(TWO_PI*n / N)*SUN)
#define generateSunY(n) (cos(TWO_PI*n / N)*SUN)
#define sqrtDis(x,y)(sqrt(pow(x, 2) + pow(y, 2)))
#define chordLen(r1,r3)	(2*sqrt(r1-r3))

// radians to degrees = tan(i*PI/180.0)
//chord length formul with radians = 2*sprt(r*r-pow(rads*x+y/(sqrt(rads*rads+1)),2));

using namespace std;

inline long double collisionDetection(int num_trees,int* x,int *y,int *r,double x12,double y12)
{
	long double ans1 = 0.0f;
	for (register unsigned char j = 0; j < num_trees; j++)
	{
		double rad = pow(r[j], 2);
		//check collision with each tree
		double c = (x[j] * x12 + y12 * y[j]);
		c /= sqrtDis(x12, y12);

		if (c >= 0)
		{
			//apply circle distance formula
			c = pow(x[j], 2) + pow(y[j], 2) - pow(c, 2);
		}
		else
			continue;

		if (c <= rad)
			ans1 = ans1 + chordLen(rad, c);
		else continue;
	}
	return ans1;
}
int main()
{
	int num_trees;
	double x12, y12;
	
	while (~scanf("%d", &num_trees))
	{
		float ans = 0.0f;
		if (num_trees <= 0)
			return 0;
		int* x = new int[200];
		int* y = new int[200];
		int* r = new int[200];
		for (register unsigned char a = 0; a < num_trees; a++)
		{
			x[a] = 0;
			y[a] = 0;
			r[a] = 0;
		}
		for (register int i = 0; i < num_trees; i++)
			scanf("%d%d%d", &x[i], &y[i], &r[i]);

		//we check which trees it intercepts for every minute of the day so we need a loop to 1440
		for (int i = 0; i < N; i++)
		{
			x12 = generateSunX(i);
			y12 = generateSunY(i);
			//printf("%lf   %lf\n", x12, y12);
			long double ans1 = collisionDetection(num_trees,x,y,r,x12,y12);
			//printf("ans1 = %lf\n", ans1);
			if (ans < ans1)
				ans = ans1;
		}
		printf("%.3lf\n", ans);
		delete x, y, r;
	}
	return 0;
}