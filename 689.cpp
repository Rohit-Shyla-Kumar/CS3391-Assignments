#include <iostream>
#include <cstring>
#include <cstdio>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int bSearch(int stock,int n,int* p)
{
	int l = 0;
	int u = n;
	int mid = (l + u) / 2;

	if (p[n-1] <= stock)
	{
		return n;
	}

	bool flag = true;
	while (flag)
	{
		mid = (l + u)/ 2;
		if (u - l <= 1)
		{
			flag = false;
		}
		if (p[mid] == stock)
		{
			if (p[mid + 1] > stock)
			{
				flag = false;
				return mid + 1;
			}
			else l = mid;
		}
		else if (p[mid] < stock)
		{
			l = mid;
		}
		else if (p[mid] > stock)
		{
			u = mid;
		}
	}
	return u;
}
int main()
{
	int n;
	
	while (cin >> n)
	{
		int* stocks = new int[1000003];
		int* p = new int[1000003];
		/*memset(p, 0, sizeof(int) * 1000003);
		memset(stocks, 0, sizeof(int) * 1000003);*/
		for (int i = 0; i < n; i++)
			scanf("%d", &stocks[i]);
		
		p[0] = 0;
		p[1] = stocks[0];
		int max1 = 1;
		int i = 1;
		while (i < n)
		{
			int position = bSearch(stocks[i],max1+1,p);
			p[position] = stocks[i];
			
			i++; 

			if (position > max1)
				max1 = position;
		}

		printf("%d\n", max1);

		//this beautiful solution is too slow
		/*for (int i = 1; i < n; i++)
		{
			int max = 0;
			for (int j = 0; j < i; j++)
			{
				if (stocks[j] <= stocks[i] && p[j] > max)
				{
					max = p[j];
				}
			}
			p[i] = 1 + max;
			if (p[i] > maxAns)
			{
				maxAns = p[i];
			}
		}*/
		delete stocks;
		delete p;
	}
	
	return 0;
}