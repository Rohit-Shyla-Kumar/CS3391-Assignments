#include <iostream>
#include <string>
#include <queue>

using namespace std;
int ctr = 1;

void BFS(char mat[9][9],bool visited[9][9],int s1,int s2,int t1,int t2,int path[9][9])
{
	bool flag = false;
	visited[s1][s2]=1;
	queue<int>q;
	q.push(s1);
	q.push(s2);
	int a, b;
	//keep poping and adding neighbours until we reach the target
	while (!flag)
	{
		if (q.empty() == true)
		{
			flag = true;
			cout << "Case " << ctr << ": IMPOSSIBLE" << endl;
		}
		else
		{
			a = q.front();
			q.pop();
			b = q.front();
			q.pop();
			if (a == t1 && b == t2)
			{
				flag = true;
				cout << "Case " << ctr << ": " << path[a][b] << endl;
			}
				
			//add neighbours to q
			//8 possible neighbours for the black knight
			if (a > 0 && b > 1 && mat[a][b]!='*' && visited[a-1][b-2] == 0)
			{
				visited[a - 1][b - 2] = 1;
				path[a - 1][b - 2] = path[a][b] + 1;
				q.push(a - 1);
				q.push(b - 2);
			}
			if (a > 1 && b > 0 && mat[a][b] != '*' && visited[a - 2][b - 1] == 0)
			{
				visited[a - 2][b - 1] = 1;
				path[a - 2][b - 1] = path[a][b] + 1;
				q.push(a - 2);
				q.push(b - 1);
			}
			if (a > 1 && b < 7 && mat[a][b] != '*' && visited[a - 2][b + 1] == 0)
			{
				visited[a - 2][b + 1] = 1;
				path[a - 2][b + 1] = path[a][b] + 1;
				q.push(a - 2);
				q.push(b + 1);
			}
			if (a > 0 && b < 6 && mat[a][b] != '*' && visited[a - 1][b + 2]==0)
			{
				visited[a - 1][b + 2] = 1;
				path[a - 1][b + 2] = path[a][b] + 1;
				q.push(a - 1);
				q.push(b + 2);
			}

			if (a < 7 && b < 6 && mat[a][b] != '*' && visited[a + 1][b + 2] ==0)
			{
				visited[a + 1][b + 2] = 1;
				path[a + 1][b + 2] = path[a][b] + 1;
				q.push(a + 1);
				q.push(b + 2);
			}
			if (a < 6 && b < 7 && mat[a][b] != '*' && visited[a + 2][b + 1] ==0)
			{
				visited[a + 2][b + 1] = 1;
				path[a + 2][b + 1] = path[a][b] + 1;
				q.push(a + 2);
				q.push(b + 1);
			}
			if (a < 6 && b > 0 && mat[a][b] != '*' && visited[a + 2][b - 1] ==0)
			{
				visited[a + 2][b - 1] = 1;
				path[a + 2][b - 1] = path[a][b] + 1;
				q.push(a + 2);
				q.push(b - 1);
			}
			if (a < 7 && b > 1 && mat[a][b] != '*' && visited[a + 1][b - 2] ==0)
			{
				visited[a + 1][b - 2] = 1;
				path[a + 1][b - 2] = path[a][b] + 1;
				q.push(a + 1);
				q.push(b - 2);
			}
		}
	}
}
int main()
{
	int T;
	cin >> T;
	char mat[9][9];
	int path[9][9];
	bool visited[9][9];
	for (int l = 0; l < 9; l++)
	{
		for (int k = 0; k < 9; k++)
		{
			visited[l][k] = false;
			mat[l][k] = 0;
			path[l][k] = 0;
		}
	}
	int i = 0, j = 0;
	string str;
	getline(cin, str);
	int bkX, bkY, wkX = 0, wkY = 0;
	while (ctr<=T)
	{
		getline(cin, str);
		if (str.length() == 0)
		{
			BFS(mat, visited, bkX, bkY,wkX,wkY,path);
			i = 0;
			j = 0;
			ctr++;
			for (int l = 0; l < 9; l++)
			{
				for (int k = 0; k < 9; k++)
				{
					visited[l][k] = false;
					mat[l][k] = 0;
					path[l][k] = 0;
				}
			}
		}
		else
		{
			for (j = 0; j < 9; j++)
			{
				mat[i][j] = str[j];
				if (mat[i][j] == '#')
				{
					bkX = i;
					bkY = j;
				}
				else if (mat[i][j] == '@')
				{
					wkX = i;
					wkY = j;
				}
			}
			i++;
		}
		
	}
	return 0;
}