#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
#include <limits>

using namespace std;

struct Point
{
	int x, y;
}points[202];
void printGraph(int **graph,int n)
{
	for (register int i = 0; i < n; i++)
	{
		for (register int j = 0; j < n; j++)
		{
			printf("%d ", graph[i][j]);
		}
		printf("\n");
	}
}
bool bfs(int** rG, int s, int t, int parent[], int size)
{
	bool *visited = new bool[size];
	memset(visited, false, sizeof(bool)*size);

	queue<int> q;
	q.push(s);
	visited[s] = true;
	parent[s] = -1;
	while (!q.empty() == true)
	{
		int temp = q.front();
		q.pop();

		for (int i = 0; i < size; i++)
		{
			if (visited[i] == false && rG[temp][i] > 0)
			{
				q.push(i);
				visited[i] = true;
				parent[i] = temp;
			}
		}
	}

	return visited[t];
}

int EdmondKarps(int size, int s, int t, int **g,int n)
{
	//printGraph(g, t);
	int rG[300][300];
	for (register int i = 0; i < t+1; i++)
		for (register int j = 0; j <t+1; j++)
			rG[i][j] = g[i][j];

	int *parent = new int[size];

	int flow = 0;

	unsigned int aaa[300];
	unsigned int aaaa[300];
	for (register int i = 0; i <= t; i++)
	{
		aaa[i] = -1;
		aaaa[i] = 0;
		if (i == s)
		{
			aaaa[i] = INT_MAX;
			aaa[i] = 2;
		}
	}
	
	

	while (bfs(g, s, t, parent, size) == true)
	{
		int path = 999999;
		int u, v;
		v = t;
		while (v != s)
		{
			u = parent[v];
			path = min(path, rG[u][v]);
			v = parent[v];
		}

		v = t;
		while (v != s)
		{
			u = parent[v];
			rG[u][v] -= path;
			rG[v][u] += path;
			v = parent[v];
		}

		flow += path;
	}
	return flow;
}

void set(int s, int d, int source, int t,int** graph,int n)
{
	//source
	for (int i = 1; i <= s; i++)
	{
		int temp;
		scanf("%d", &temp);
		graph[source][temp * 2] = 0;
		for (int j = 1; j <= n; j++)
		{
			if (graph[temp * 2 + 1][2 * j] > 0)
			{
				graph[source][temp * 2] = graph[source][temp * 2] + graph[temp * 2 + 1][2 * j];
			}
		}
	}
	//sink
	for (int i = 1; i <= d; i++)
	{
		int temp;
		scanf("%d", &temp);
		graph[temp * 2 + 1][t] = 0;
		for (int j = 1; j <= n; j++)
		{
			if (graph[j * 2 + 1][2 * temp] > 0)
			{
				graph[temp * 2 + 1][t] = graph[temp * 2 + 1][t] + graph[j * 2 + 1][2 * temp];
			}
		}
	}
}

int main()
{
	int n;
	int counter = 1;
	while (~scanf("%d",&n))
	{

		int **graph = new int*[300];
		for (int i = 0; i < 300; i++)
		{
			graph[i] = new int[300];
			memset(graph[i], 0, sizeof(int) * 300);
		}

		int a,m;
		for (int i = 1; i <=n; i++)
		{
			scanf("%d", &a);
			graph[2 * i][2 * i + 1] = a;
			graph[2 * i + 1][2 * i] = 0;
		}

		scanf("%d", &m);
		int u, v, w;
		for (int i = 0; i < m; i++)
		{
			scanf("%d%d%d", &u, &v, &w);
			graph[2 * u + 1][2 * v] = w;
		}

		int s, d;
		scanf("%d%d", &s, &d);
		int source = 0;
		int t = n * 2;
		t += 2;

		
		//set edges if dist less than the tackling dist (dist b/w radius formula)
		set(s,d,source,t,graph,n);

		/*for (int i = 0; i < n * 2; i++)
		{
		for (int j = 0; j < n * 2; j++)
		{
		cout << graph[i][j] << ",";
		}
		}
		cout << endl;*/

		int f = EdmondKarps(2 * n + 2, 0, 2 * n + 1, graph,n);
		printf("%d\n", f);
		delete graph;
	}
}