//#include <queue>
//#include <stdio.h>
//using namespace std;
//char map[105][105];
//int steps[105][105];
//int dxk[] = { 1,-1,1,-1,2,2,-2,-2 };
//int dyk[] = { 2,2,-2,-2,1,-1,1,-1 };
//int dx[] = { 0,0,1,-1,1,-1,1,-1 };
//int dy[] = { 1,-1,0,0,1,-1,-1,1 };
//int main()
//{
//	int r, c, runs;
//	scanf("%d", &runs);
//	while (runs--)
//	{
//		scanf("%d %d", &r, &c);
//		getchar();
//		int si, sj, ei, ej;
//		for (int i = 0; i<r; i++)
//			gets(map[i]);
//		queue<int> Q;
//		for (int i = 0; i<r; i++)
//		{
//			for (int j = 0; j<c; j++)
//			{
//				steps[i][j] = -1;
//				if (map[i][j] == 'Z')
//				{
//					steps[i][j] = 0;
//					Q.push(i);
//					Q.push(j);
//					Q.push(0);
//				}
//				else if (map[i][j] == 'A')
//				{
//					si = i;
//					sj = j;
//				}
//				else if (map[i][j] == 'B')
//				{
//					ei = i;
//					ej = j;
//				}
//			}
//		}
//		while (Q.size())
//		{
//			int i = Q.front(); Q.pop();
//			int j = Q.front(); Q.pop();
//			int t = Q.front(); Q.pop();
//			for (int d = 0; d<8; d++)
//			{
//				int x = i + dxk[d];
//				int y = j + dyk[d];
//				if (x >= 0 && x<r&&y >= 0 && y<c&&map[x][y] == '.'&&steps[x][y] == -1 && !t)
//				{
//					steps[x][y] = t + 1;
//					Q.push(x); Q.push(y); Q.push(t + 1);
//				}
//			}
//		}
//		bool found = false;
//		Q.push(si);
//		Q.push(sj);
//		Q.push(0);
//		map[si][sj] = 'V';
//		while (Q.size() && !found)
//		{
//			int ci = Q.front(); Q.pop();
//			int cj = Q.front(); Q.pop();
//			int t = Q.front(); Q.pop();
//			if (ci == ei && cj == ej)
//			{
//				printf("Minimal possible length of a trip is %d\n", t);
//				found = true;
//			}
//			else for (int d = 0; d<8; d++)
//			{
//				int x = ci + dx[d];
//				int y = cj + dy[d];
//				if (x >= 0 && y >= 0 && x<r&&y<c&&map[x][y] != 'V' && (steps[x][y] == -1 || t + 1<steps[x][y]))
//				{
//					map[x][y] = 'V';
//					Q.push(x);
//					Q.push(y);
//					Q.push(t + 1);
//				}
//			}
//		}
//		if (!found)
//			puts("King Peter, you can't go now!");
//	}
//}