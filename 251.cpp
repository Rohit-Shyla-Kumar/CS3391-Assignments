#include <iostream>

using namespace std;
void DFS(int map[51][51],int visited[51][51],int i,int j,int m,int n)
{
	visited[i][j] = 1;
	//now we look all around

	//down
	if (i < m && map[i + 1][j] == 1 && visited[i + 1][j] == 0)
		DFS(map, visited, i + 1, j, m, n);

	//up
	if (i != 0 && map[i - 1][j] == 1 && visited[i - 1][j] == 0)
		DFS(map, visited, i - 1, j,m,n);

	//left
	if (j != 0 && map[i][j-1] == 1 && visited[i][j-1] == 0)
		DFS(map, visited, i, j - 1, m, n);

	//up-left
	if (i != 0 && j!=0 && map[i - 1][j - 1] == 1 && visited[i - 1][j - 1] == 0)
		DFS(map, visited, i - 1, j - 1,m,n);

	//down-left
	if (i < m && j!=0 && map[i + 1][j - 1] == 1 && visited[i + 1][j - 1] == 0)
		DFS(map, visited, i + 1, j - 1,m,n);


	//right
	if (j < n && map[i][j + 1] == 1 && visited[i][j + 1] == 0)
		DFS(map, visited, i, j + 1, m, n);

	//down-right
	if (i < m  && j <n && map[i + 1][j + 1] == 1 && visited[i + 1][j + 1] == 0)
		DFS(map, visited, i + 1, j + 1, m, n);

	//up-right
	if (i!=0 && j<n  && map[i - 1][j + 1] == 1 && visited[i - 1][j + 1] == 0)
		DFS(map, visited, i - 1, j + 1, m, n);
}
int main()
{
	int map[51][51];
	int visited[51][51];
	
	int w, h,ctr=0;
	while (cin >> w >> h)
	{
		if (w == 0)
			break;

		ctr = 0;
		
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				map[i][j] = 0;
				visited[i][j] = 0;
			}
		}

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (map[i][j] == 1 && visited[i][j] == 0)
				{
					ctr++;
					DFS(map, visited, i, j,h,w);
				}
			}
		}

		cout << ctr << endl;
	}
	return 0;
}