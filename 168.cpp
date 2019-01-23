#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

const int MAX_SIZE = 100000;

class Edge
{
public:
	int weight;
	int from, to;
	Edge()
	{
		from = 0; 
		to = 0;
		weight = 0;
	}
	Edge(int _from, int _to, int w)
	{
		from = _from;
		to = _to;
		weight = w;
	}
}Edges[MAX_SIZE];

int compare(const void* a, const void* b)
{
	Edge* A = (Edge *)a;
	Edge* B = (Edge *)b;
	return (A->weight - B->weight);
}

class DisjointSet
{
public:
	int Find(int);
	void Union(int, int);
	void UnionSet(int, int);
	int name[500];
	int val[MAX_SIZE];
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
	int tot;
	while (cin >> P)
	{
		
		if (P == 0)
			return 0;

		tot = 0;
		scanf("%d",&R);
		int p1, p2, l;
		for (int i = 0; i <=P; i++)
			set.name[i] = -1;
		for (int i = 0; i < R; i++)
		{
			scanf("%d%d%d", &p1, &p2, &l);
			Edges[i] = *(new Edge(p1, p2, l));
		}
		qsort(Edges,R,sizeof(Edge),compare);
		for (int i = 0; i < R; i++)
		{
			int a = Edges[i].from;
			int b = Edges[i].to;
			if (set.Find(a) != set.Find(b))
			{
				set.Union(a,b);
				tot += Edges[i].weight;
			}
		}
		printf("%d\n", tot);
	}
	return 0;
}