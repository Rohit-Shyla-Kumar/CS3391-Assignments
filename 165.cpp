#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <iomanip>
using namespace std;

const int MAX_SIZE = 201;

//int compare(const void* a, const void* b)
//{
//	Edge* A = (Edge *)a;
//	Edge* B = (Edge *)b;
//	return (A->weight - B->weight);
//}

double dists[MAX_SIZE][MAX_SIZE];
//class DisjointSet
//{
//public:
//	int Find(int);
//	void Union(int, int);
//	void UnionSet(int, int);
//	int name[500];
//	int val[MAX_SIZE];
//};
//
//int DisjointSet::Find(int element)
//{
//	if (name[element] < 0)
//		return element;
//	else
//		return name[element] = Find(name[element]);
//}
//
//void DisjointSet::Union(int a, int b)
//{
//	int root1 = Find(a);
//	int root2 = Find(b);
//	if (name[root1]<name[root2])
//		UnionSet(root1, root2);
//	else
//		UnionSet(root2, root1);
//}
//
//void DisjointSet::UnionSet(int set1, int set2)
//{
//	name[set1] += name[set2];
//	name[set2] = set1;
//}

struct Point
{
	int x, y;
};

void floyd(int n)
{
	for (int k = 0; k<n; k++)
		for (int i = 0; i<n; i++)
			for (int j = 0; j < n; j++)
			{
				if (dists[i][k] >= dists[k][j] && dists[i][k] < dists[i][j])
					dists[i][j] = dists[i][k];
				else if(dists[k][j]<dists[i][j]&&dists[k][j]>dists[i][k])
					dists[i][j] = dists[k][j];
			}
}
double dis;
int fred = 0;
int fiona = 1;
int counter = 1;
void printOff()
{
	cout << "Scenario #" << counter << endl;
	counter++;
	dis = dists[fred][fiona];
	cout << fixed;
	cout << setprecision(3);
	cout << "Frog Distance = " << dis << endl;
	cout << endl;
}
void getDists(int n,int *x,int *y)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			dists[i][j] = dists[j][i] = sqrt(pow((x[i] - x[j]), 2) + pow((y[i] - y[j]), 2));
		}
	}
}
int main()
{
	//DisjointSet set;
	int n;
	
	while (cin >> n)
	{
		
		if (n == 0)
			return 0;

		int *a = new int[n];
		int *b = new int[n];
		memset(a, 0, sizeof(int)*n);
		memset(b, 0, sizeof(int)*n);
		dis = 0;
		
		//for (int i = 0; i <= n; i++)
		//	set.name[i] = -1;

		for (int i = 0; i < n; i++)
		{
			scanf("%d%d",&a[i],&b[i]);
			//if (i == 1)
			//{
			//	fredX = x1;
			//	fredY = y1;
			//}
			//else if (i == 2)
			//{
			//	fiX = x1;
			//	fiY = y1;
			//}
		}

		getDists(n,a,b);

	/*	for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << dists[i][j] << " ";
			}
			cout << endl;
		}*/
		floyd(n);

		printOff();

	}
	return 0;
}