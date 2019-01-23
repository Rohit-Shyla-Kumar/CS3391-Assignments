//#include <iostream>
//#include <string>
//#include <queue>
//#include <cstring>
//#include <vector>
//#include <functional>
//
//using namespace std;
//
//class Vertices
//{
//public:
//	int weight;
//	int y;
//	int x;
//};
//
//struct greatTh
//{
//	bool operator() (Vertices const& lhs, Vertices const& rhs)
//	{
//		return lhs.weight > rhs.weight;
//	}
//};
//int source = 0, dest = 0;
//
//
//int main()
//{
//	int N;
//	int counter = 1;
//	while (cin >> N)
//	{
//		if (N == 0)
//		{
//			break;
//		}
//		Vertices weights[125][125];
//		int dist[125][125];
//		//initializataion of distance of all vertices to infinity and source to 0
//		dest = N - 1;
//		for (int i = 0; i < N; i++)
//		{
//			for (int j = 0; j < N; j++)
//			{
//				dist[i][j] = 99999;
//				weights[i][j].x = j;
//				weights[i][j].y = i;
//				cin >> weights[i][j].weight;
//			}
//		}
//
//		dist[source][source] = weights[source][source].weight;
//		priority_queue<Vertices, vector<Vertices>, greatTh> q;
//
//		q.push(weights[source][source]);
//		while (!(q.empty()))
//		{
//			Vertices n = q.top();
//
//			q.pop();
//			//relax all edges leaving this vertex
//			//UP
//			if (n.y != 0)
//			{
//				if (dist[n.y - 1][n.x] > weights[n.y - 1][n.x].weight + dist[n.y][n.x])
//				{
//					dist[n.y - 1][n.x] = weights[n.y - 1][n.x].weight + dist[n.y][n.x];
//					q.push(weights[n.y - 1][n.x]);
//				}
//			}
//			//DOWN
//			if (n.y < N)
//			{
//				if (dist[n.y + 1][n.x] > weights[n.y + 1][n.x].weight + dist[n.y][n.x])
//				{
//					dist[n.y + 1][n.x] = weights[n.y + 1][n.x].weight + dist[n.y][n.x];
//					q.push(weights[n.y + 1][n.x]);
//				}
//			}
//			//LEFT
//			if (n.x != 0)
//			{
//				if (dist[n.y][n.x - 1] > weights[n.y][n.x - 1].weight + dist[n.y][n.x])
//				{
//					dist[n.y][n.x - 1] = weights[n.y][n.x - 1].weight + dist[n.y][n.x];
//					q.push(weights[n.y][n.x - 1]);
//				}
//			}
//			//RIGHT
//			if (n.x < N)
//			{
//				if (dist[n.y][n.x + 1] > weights[n.y][n.x + 1].weight + dist[n.y][n.x])
//				{
//					dist[n.y][n.x + 1] = weights[n.y][n.x + 1].weight + dist[n.y][n.x];
//					q.push(weights[n.y][n.x + 1]);
//				}
//			}
//		}
//		cout << "Problem " << counter << ": " << dist[dest][dest] << endl;
//		counter++;
//	}
//	return 0;
//}