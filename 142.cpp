/*****************************************
* (This comment block is added by the Judge System)
* Submission ID: 53767
* Submitted at:  2018-03-17 22:15:20
*
* User ID:       440
* Username:      54581876
* Problem ID:    142
* Problem Name:  FRIENDS (UVa 10608)
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

using namespace std;

const int MAX_SIZE = 30001;

class DisjointSet
{
public:
	int Find(int);
	void Union(int, int);
	void UnionSet(int, int);
	int name[MAX_SIZE];
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
	if (root1 == root2)
		return;
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

int counter[MAX_SIZE];

int main()
{
	int t, ctr = 0;
	scanf("%d", &t);
	DisjointSet set;

	while (ctr < t)
	{
		ctr++;
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
		{
			set.name[i] = -1;
		}
		for (int i = 0; i < m; i++)
		{
			int temp1, temp2;
			scanf("%d%d", &temp1, &temp2);
			set.Union(temp1, temp2);
			/*for (int j = 1;j <= n;j++)
			cout << set.name[j] << " ";
			cout << endl;*/
		}
		cout << abs(*std::min_element(set.name + 1, set.name + n + 1)) << endl;
	}

	return 0;
}