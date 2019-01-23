//#include <stdio.h>
//
//using namespace std;
//
//int main()
//{
//	long long int a, b;
//	int ct = 1;
//	while (~scanf("%lld%lld", &a, &b))
//	{
//		if (a == 0 && b == 0)
//			return 0;
//
//		//euler theorm to not add
//		long long int a1 = (a*a - a) / 2;
//		long long int b1 = (b*b - b) / 2;
//
//		
//		printf("Case %d: %lld\n", ct, a1*b1);
//		ct++;
//	}
//	return 0;
//}