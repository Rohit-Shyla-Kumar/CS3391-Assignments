//#include <stdio.h>
//#include <iostream>
//#include <math.h>
//#include <string.h>
//#include <vector>
//#include <string>
//
//using namespace std;
//
//#define N 100000000
//#define SQRT_N 10000
//#define HALF_SQRT_N 5000
//
//int A[(N >> 6) + 1];
//
//int primes[5770000];
//
//int ctr = 1;
//bool flag; int n1, n2;
//inline bool IsComp(int n) {
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
//inline int binarySearch(int key)
//{
//	int l = 0; int u = ctr; int mid = (l + u) / 2;
//	if (key < 5000000)
//		u = key;
//
//	while (u > l&&mid>0)
//	{
//		mid = (l + u) / 2;
//
//		if (key > primes[mid])
//			l = mid + 1;
//		else if (key < primes[mid])
//			u = mid - 1;
//		else
//			return mid;
//	}
//	return -1;
//}
//int main()
//{
//	primes[0] = 2;
//	Atkin();
//	for (int i = 3; i <= N; i += 2)	if (!IsComp(i))	primes[ctr++] = i;
//	/*for (int i = 0; i < ctr; i++)
//	cout << primes[i] << " ";*/
//	long int n;
//	int c = 100000;
//	while (c)
//	{
//		c--;
//		scanf("%d", &n);
//		flag = false;
//		if (n == 1 || n == 2 || n == 3||n==4||n==6); //hardcoding base cases lol
//		//case even
//		else if ((n & 1) == 0)
//		{
//
//			long int temp = n / 2 - 1;
//			int high = -1;
//			while (temp>0)
//			{
//				if (((n - temp) & 1) && !IsComp(n - temp) && (temp&1)&&!IsComp(temp))
//				{
//					set(true, temp, n - temp);
//					break;
//				}
//				temp-=1; //Can't use -=2
//			}
//		}
//		//case odd
//		else
//		{
//			if (!IsComp(n - 2))
//				set(true, 2, n - 2);
//		}
//
//		if (!flag)
//			printf("%d is not the sum of two primes!\n", n);
//		else
//			printf("%d is the sum of %d and %d.\n", n, n1, n2);
//	}
//	return 0;
//}