#include <iostream>
#include <cstring>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

const int MAX = 53 * 53;
class DisjointSet
{
public:
	int Find(int);
	int Union(int, int);
	void UnionSet(int, int);
	int name[MAX+10];
};

int DisjointSet::Find(int element)
{
	if (name[element] < 0)
		return element;
	else
		return name[element] = Find(name[element]);
}

int DisjointSet::Union(int a, int b)
{
	int root1 = Find(a);
	int root2 = Find(b);

	if (root1 == root2)
		return 0;
	if (name[root1]<name[root2])
		UnionSet(root1, root2);
	else
		UnionSet(root2, root1);
	return 1;
}

void DisjointSet::UnionSet(int set1, int set2)
{
	name[set1] += name[set2];
	name[set2] = set1;
}

void printArray(int* arr,int N)
{
	for (int i = 0; i < N; i++)
	{
			cout << arr[i];
	}
}

struct Road {
	int i, j;
	int connected;
	int cost;
};

//descending sorting function 
int compare(const void* a, const void* b)
{
	Road* A = (Road *)a;
	Road* B = (Road *)b;
	if (B->cost == A->cost)
	{
		if (B->i == A->i)
		{
			if (B->j == A->j)
				return 0;
			else if (B->i > A->i)
				return -1;
			else
				return 1;
		}
		else if (B->i > A->i)
			return -1;
		else
			return 1;
	}
	else if (B->cost > A->cost)
		return 1;
	else
		return -1;
}
//ascending sorting function 
int compare1(const void* a, const void* b)
{
	Road* A = (Road *)a;
	Road* B = (Road *)b;
	if (B->cost == A->cost)
	{
		if (B->i == A->i)
		{
			if (B->j == A->j)
				return 0;
			else if (B->i > A->i)
				return -1;
			else
				return 1;
		}
		else if (B->i > A->i)
			return -1;
		else
			return 1;
	}
	else if (B->cost > A->cost)
		return -1;
	else
		return 1;
}

void printArr(Road* arr, int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << arr[i].cost;
	}
}


int main()
{
	int N;
	while (~scanf("%d",&N))
	{
		
		if (N == 0)
			break;
		DisjointSet set;
		for (int i = 0; i < MAX+10; i++)
			set.name[i] = -1;
		Road C[MAX];
		string temp;
		getline(cin, temp); // for blank line
		Road Destroy[MAX];
		int ctr = 0;
		for (int i = 0; i < N; i++)
		{
			getline(cin,temp);
			for (int j = 0; j < N; j++)
			{
				Destroy[ctr].i = i;
				Destroy[ctr].j = j;
				Destroy[ctr].connected = temp[j] - '0';
				ctr++;
			}	
		}

		
		for (int i = 0; i < N*N; i++)
		{
				scanf("%d", &C[i].cost);
				C[i].i = (floor)(i / N);
				C[i].j = i % N;
		}

		for (int i = 0; i < N*N; i++)
		{
				scanf("%d", &Destroy[i].cost);
				
		}
		
		qsort(Destroy, N*N, sizeof(Road), compare);
		qsort(C, N*N, sizeof(Road), compare1);


		int tot = 0;


		for (int i = 0; i < N*N; i++)
		{
			if (Destroy[i].connected)
			{
					if (set.Find(Destroy[i].i) == set.Find(Destroy[i].j))
					{
						if (Destroy[i].j > Destroy[i].i)
						{
							tot += Destroy[i].cost;
						}
					}
					else
					{
						set.Union(Destroy[i].i, Destroy[i].j);
					}
			}	
		}
		
		//now we should have cost of destroying all the unecessary roads so we just build the mst with what we have left
		
		int min = 0;
		for (int i = 0; i < N*N; i++)
		{
			if (set.Find(C[i].i) != set.Find(C[i].j)&&C[i].j>C[i].i)
			{
				int temp1 = set.Union(C[i].i, C[i].j);
				if(temp1)	tot += C[i].cost;
				min = *(std::min_element(set.name, set.name + N));
				if (abs(min) == N)
					break;
			}
		
		}

		printf("%d\n", tot);
	}
	return 0;
}