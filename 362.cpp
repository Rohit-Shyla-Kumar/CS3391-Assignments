/*****************************************
* (This comment block is added by the Judge System)
* Submission ID: 54946
* Submitted at:  2018-04-01 01:52:56
*
* User ID:       440
* Username:      54581876
* Problem ID:    362
* Problem Name:  Winger Trial (UVa 11757)
*/

#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>

using namespace std;

struct Point
{
	int x, y;
}points[202];

int bfs(int** rG, int s, int t, int parent[], int size)
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

int EdmondKarps(int size, int s, int t, int **g)
{


	int *parent = new int[size];

	int flow = 0;

	while (bfs(g, s, t, parent, size) == true)
	{
		int path = 999999;
		int u, v;
		v = t;
		while (v != s)
		{
			u = parent[v];
			path = min(path, g[u][v]);
			v = parent[v];
		}

		v = t;
		while (v != s)
		{
			u = parent[v];
			g[u][v] -= path;
			g[v][u] += path;
			v = parent[v];
		}

		flow += path;
	}
	return flow;
}

void set(int n, int** graph, int d)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (pow(points[i].x - points[j].x, 2) + pow(points[i].y - points[j].y, 2) <= pow(d, 2))
			{
				graph[i * 2 + 1][2 * j] = 1;
			}
		}
	}
}

int main()
{
	int l, w, n, d;
	int counter = 1;
	while (~scanf("%d%d%d%d", &l, &w, &n, &d))
	{
		if (l == 0)
			break;

		int **graph = new int*[202];
		for (int i = 0; i < 202; i++)
		{
			graph[i] = new int[202];
			memset(graph[i], 0, sizeof(int) * 202);
		}
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d", &points[i].x, &points[i].y);
		}

		for (int i = 0; i < n; i++)
		{
			graph[i * 2][i * 2 + 1] = 1;
			if (points[i].y <= d)
				graph[2 * n][i * 2] = 1;
			if (w - points[i].y <= d)
				graph[i * 2 + 1][2 * n + 1] = 1;
		}

		//set edges if dist less than the tackling dist (dist b/w radius formula)
		set(n, graph, d * 2);

		/*for (int i = 0; i < n * 2; i++)
		{
		for (int j = 0; j < n * 2; j++)
		{
		cout << graph[i][j] << ",";
		}
		}
		cout << endl;*/

		int f = EdmondKarps(2 * n + 2, 2 * n, 2 * n + 1, graph);
		printf("Case %d: %d\n", counter++, f);
		delete graph;
	}
}