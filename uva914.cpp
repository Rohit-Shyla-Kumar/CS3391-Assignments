//#include <stdio.h>
//#include <iostream>
//#include <math.h>
//#include <string.h>
//#include <vector>
//#include <string.h>
//
//using namespace std;
//
//#define N 100000000
//#define SQRT_N 10000
//#define HALF_SQRT_N 5000
//
//int A[(N >> 6) + 1];
//
//
//int ctr = 1;
//bool flag; int n1, n2;
//inline bool IsComp(int n) {
//	if (n == 1)
//		return 1;
//	if (n!=2&&n % 2 == 0)
//		return 1;
//	return (A[n >> 6] & (1 << ((n >> 1) & 31)));
//}
//
//inline void SetComp(int n)
//{
//	A[n >> 6] |= (1 << ((n >> 1) & 31));
//}
//
//inline void Atkin() {
//	for (int i = 3; i<SQRT_N; i += 2)
//		if (!IsComp(i))
//			for (int j = i * i; j < N; j += i + i)
//				SetComp(j);
//}
//inline void set(bool _flag, int _n1, int _n2)
//{
//	flag = _flag;
//	n1 = _n1;
//	n2 = _n2;
//}
//
//int main()
//{
//	Atkin();
//	int l,t, u;
//	scanf("%d", &t);
//	while (t--)
//	{
//		int diff[1000];
//		memset(diff, 0, sizeof(diff));
//		scanf("%d%d", &l, &u);
//		int p1=0, p2;
//		int ctr = 0;
//		for (int i = l; i <= u; i++)
//		{
//			if (!IsComp(i))
//			{
//				ctr++;
//				//cout << i << ": ";
//				if (p1 == 0)
//				{
//					p1 = i;	
//					continue;
//				}
//				p2 = i;
//				int d = p2 - p1;
//				//cout << d << endl;
//				diff[d]++;
//				
//				p1 = p2;
//			}
//		}
//		//cout << diff[2] << diff[4] << diff[6] << endl;
//		int max = 0;
//		int ind = 0;
//		bool flag = true;
//		for (register int i = 0; i < 1000; i++)
//		{
//			if (diff[i] > max)
//			{
//				max = diff[i];	ind = i;
//			}
//		}
//		for (register int i = 0; i < 1000; i++)
//		{
//			if (ind == i)
//				continue;
//			if (max == diff[i])
//				flag = false;
//		}
//		if (flag == false || ctr < 2)
//			printf("No jumping champion\n");
//		else
//			printf("The jumping champion is %d\n", ind);
//	}
//	return 0;
//}