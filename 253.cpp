#include <iostream>
#include <string>
#include <queue>
#include <iomanip>
#include <string.h>

using namespace std;
float dist=9999999; 
#define REACHABLE(n) (n<9999999)
#define EPSILON 0.001
class Road
{
public: 
	int x, y, l, s;
	double t;
	Road()
	{
		x = 0;
		y = 0;
		l = 0;
		s = 0;
	}
	Road(int _x,int _y,int _l,int _s)
	{
		x = _x;
		y = _y;
		l = _l;
		s = _s;
		t = 0;
	}
	inline friend bool operator<(Road lhs, Road rhs)
	{
		return(lhs.t > rhs.t);
	}
};




bool bfs(unsigned short cities[30][30],unsigned short limit[30][30],int s,int t,int num_cities, float path[30][30][30])
{
	bool visited[30][30][30];
	memset(visited, false, 30 * 30 * 30);
	
	priority_queue<Road> q;
	q.push(Road(-1, s, 0, 0));

	while (q.empty() == false)
	{
		Road r = q.top();
		q.pop();
		for (unsigned short i = 0; i < num_cities; i++)
		{
			if (i != r.x&&cities[r.y][i] != 0)
			{
				for (int a = -1; a < 2; a++)
				{
					Road r2 = (Road(r.y, i,0, r.s + a));
					//cout << r2.s << " " << limit[r2.x][r2.y] << endl;
					if (r2.s <=limit[r2.x][r2.y]&&r2.s>0&&r2.s!=-1&&r2.s!=-2)
					{
						r2.t =r.t+(float)cities[r2.x][r2.y] / r2.s;
						//r2.t += r.t;

						if (!visited[r2.x][r2.y][r2.s] && path[r2.x][r2.y][r2.s] > r2.t)
						{
							
							visited[r2.x][r2.y][r2.s] = 1;
							path[r2.x][r2.y][r2.s] = r2.t;
							//cout << "shaata" << endl;
							q.push(r2);
							
						}
					}
				}
			}
		}
	}
	for (register int i = 0; i <num_cities; i++)
	{
		//cout << "path" << path[i][t][i];
		if (path[i][t][1] < dist)
			dist = path[i][t][1];
		/*if (dist < 10)
			break;*/
	}
	if (REACHABLE(dist))
		return true;
	return false;
}
int main()
{
	int n, m, s, g,x,y,d,c;
	while (~scanf("%d%d",&n,&m))
	{
		dist = 9999999;
		if (n == 0)
		{
			return 0;
		}
		unsigned short cities[30][30];
		unsigned short limit[30][30];
		memset(cities, 0, sizeof(cities));

		memset(limit, 0, sizeof(limit));
		float path[30][30][30];
		for (register int i = 0; i < 30; i++)
			for (register int j = 0; j < 30; j++)
				for (register int k = 0; k < 30; k++)
					path[i][j][k] = 9999999;

		scanf("%d%d", &s, &g);
		s--;
		g--;
		if (m == 0)
		{
			//cout << "shaata1" << endl;
			printf("unreachable\n");
			continue;
		}
		for (int i = 0; i < m; i++)
		{
			scanf("%d%d%d%d",&x, &y, &d, &c);
			cities[x-1][y-1] = d;
			cities[y-1][x-1] = d;
			limit[x-1][y-1] = c;
			limit[y-1][x-1] = c;
		}
		
		if (bfs(cities,limit,s, g, n,path))
		{
				printf("%.5f\n", dist);
			continue;
		}
		printf("unreachable\n");
	}

	return 0;
}