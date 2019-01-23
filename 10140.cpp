//#include <vector>
//#include <iostream>
//#include <stdio.h>
//#include <algorithm>
//#include <Bits.h>
//using namespace std;
//#define n 48000
//vector<long long int>s;
//long long int p[n], k = 2, size;
//bool a[n];
//void prime()
//{
//	long long i, j;
//	a[0] = a[1] = 1;
//	for (i = 4; i <= n; i = i + 2)
//	{
//		a[i] = 1;
//	}
//	for (i = 3; i <= sqrt(n); i = i + 2)
//	{
//		for (j = i * i; j <= n; j = j + 2 * i)
//		{
//			a[j] = 1;
//		}
//	}
//	for (i = 2; i <= n; i++)
//	{
//		if (a[i] == 0)
//		{
//			p[k] = i;
//			//cout<<p[k]<<endl;
//			k++;
//		}
//	}
//
//
//}
//
//long long int isprime(long long int v)
//{
//	long long int x;
//	if (v<n)
//	{
//		if (a[v] == 0)
//		{
//			return 1;
//		}
//		else
//		{
//			return 0;
//		}
//	}
//	else if (v>n)
//	{
//		for (x = 2; x <= k && p[x] <= sqrt(v); x++)
//		{
//			if (v%p[x] == 0)
//			{
//				return 0;
//			}
//		}
//	}
//
//	return 1;
//}
//
//void generate_prime(long long int f, long long int t)
//{
//	s.clear();
//	long long int y;
//	for (y = f; y <= t; y++)
//	{
//		if (isprime(y))
//		{
//			s.push_back(y);
//		}
//	}
//
//
//}
//
//int main()
//{
//	long long int a1, b, g;
//	long long int c, d, e, f, l, m, q;
//	prime();
//	while (cin >> a1 >> b)
//	{
//		g = 0;
//		m = 0;
//		d = 999999999999;
//		f = 0;
//		e = 0;
//		q = 0;
//		generate_prime(a1, b);
//		for (c = 1; c<s.size(); c++)
//		{
//			//cout<<p[c]<< " "<<p[c+1]<<endl;
//			if (s[c] >= a1)
//			{
//				e = abs(s[c] - s[c - 1]);
//				f = abs(s[c] - s[c - 1]);
//
//				m = max(f, m);
//				d = min(e, d);
//				g = 1;
//			}
//
//
//
//
//		}
//		if (g == 1)
//		{
//
//			for (l = 1; l<s.size(); l++)
//			{
//				if (s[l] >= a1)
//				{
//
//					if (d == abs(s[l] - s[l - 1]) && q != d)
//					{
//						printf("%lld,%lld are closest,", s[l - 1], s[l]);
//						//out<<s[l-1]<<","<<s[l]<<" are closest,";
//						q = d;
//					}
//				}
//
//			}
//
//
//			for (l = 1; l<s.size(); l++)
//			{
//				if (m == abs(s[l] - s[l - 1]))
//				{
//					printf(" %lld,%lld are most distant.\n", s[l - 1], s[l]);
//					//out<<" "<<s[l-1]<<","<<s[l]<<" are most distant."<<endl;;
//					break;
//				}
//			}
//		}
//		else
//		{
//			printf("There are no adjacent primes.\n");
//			//out<<"There are no adjacent primes."<<endl;
//
//		}
//
//
//
//	}
//
//	return 0;
//}