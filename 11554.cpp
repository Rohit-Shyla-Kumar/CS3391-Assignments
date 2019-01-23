//#include <iostream>
//#include <stdio.h>
//#include <math.h>
//
//using namespace std;
//long long int ans[1000010];
//int main()
//{
//	ans[1] = 0;
//	ans[2] = 0;
//	ans[3] = 0;
//	long long int ctr = 1;
//	long long int ctr1 = 2;
//	for (register int i = 4; i <=1000000; i++)
//	{
//		if (!(i & 1))
//		{
//			ans[i] = ans[i-1]+(ctr*ctr);
//			ctr++;
//		}
//		else
//		{
//			ans[i] = ans[i - 1] + (ctr1*(ctr1-1));
//			ctr1++;
//		}
//		
//	}
//	int T;
//	scanf("%d", &T);
//	
//	while (T--)
//	{
//		int n;
//		scanf("%d", &n);
//		printf("%lld\n", ans[n]);
//	}
//}