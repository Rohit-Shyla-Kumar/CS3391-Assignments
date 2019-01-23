#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <cmath>

using namespace std;

class Edge
{
public:
	int weight;
	int p1, p2;
	Edge()
	{
		p1 = 0;
		p2 = 0;
		weight = 0;
	}
	Edge(int from, int to, int w)
	{
		p1 = from;
		p2 = to;
		weight = w;
	}
};

Edge* Edges = new Edge[1000000];
int CMP(const void* a, const void* b)
{
	Edge* A = (Edge*)a;
	Edge* B = (Edge*)b;
	return B->weight - A->weight;
}

class DisjointSet
{
public:
	int Find(int);
	void Union(int, int);
	void UnionSet(int, int);
	int* name = new int[502];
	int* val = new int[1000000];
};

int DisjointSet::Find(int element)
{
	if (name[element] < 0)
		return element;
	else
		return name[element] = Find(name[element]);
}

void DisjointSet::Union(int a, int b)
{
	int root1 = Find(a);
	int root2 = Find(b);
	if (name[root1]<name[root2])
		UnionSet(root1, root2);
	else
		UnionSet(root2, root1);
}

void DisjointSet::UnionSet(int set1, int set2)
{
	name[set1] += name[set2];
	name[set2] = set1;
}

int main()
{
	DisjointSet set;
	int P, R;
	while (cin >> P >> R)
	{
		if (P == 0)
			return 0;

		int p1, p2, l;
		for (int i = 0; i <= P; i++)
			set.name[i] = -1;
		for (int i = 0; i < R; i++)
		{
			scanf("%d%d%d", &p1, &p2, &l);
			Edges[i] = *(new Edge(p1, p2, l));
		}
		qsort(Edges, R, sizeof(Edge), CMP);
		int max = Edges[0].weight;
		for (int i = 0; i < R; i++)
		{
			if (Edges[i].weight < max) 
				break;
			int a = Edges[i].p1;
			int b = Edges[i].p2;
			if (set.Find(a) != set.Find(b))
				set.Union(a, b);
		}
		cout << abs(*std::min_element(set.name + 1, set.name + P + 1)) << endl;
	}
	return 0;
}