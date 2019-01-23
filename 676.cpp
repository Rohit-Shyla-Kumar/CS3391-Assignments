//#include <iostream>
//#include <cstring>
//#include <string>
//
//using namespace std;
//int graph[100][100];
//int main()
//{
//	int num_cities, num_roads;
//	while (cin >> num_cities >> num_roads)
//	{
//		
//		for (int i = 0; i < num_cities; i++)
//		{
//			for (int j = 0; j < num_cities; j++)
//			{
//				graph[i][j] = (i == j) ? 0 : 999999;
//			}
//		}
//		for (int i = 0; i < num_roads; i++)
//		{
//			int u, v, w;
//			cin >> u >> v >> w;
//			graph[u-1][v-1] = w;
//			graph[v-1][u-1] = w;
//		}
//
//		/*cout << "Input graph : " << endl;
//		for (int i = 0; i < num_cities; i++)
//		{
//			for (int j = 0; j < num_cities; j++)
//			{
//				cout << graph[i][j] << " ";
//			}
//			cout << endl;
//		}*/
//			
//	
//		for(int k=0;k<num_cities;k++)
//			for (int i = 0; i<num_cities; i++)
//				for (int j = 0; j < num_cities; j++)
//				{
//					if (graph[i][j] > graph[i][k] + graph[k][j])
//						graph[i][j] = graph[i][k] + graph[k][j];
//				}
//		/*cout << "with all min distances :" << endl;
//		for (int i = 0; i < num_cities; i++)
//		{
//			for (int j = 0; j < num_cities; j++)
//			{
//				cout << graph[i][j] << " ";
//			}
//			cout << endl;
//		}*/
//		int min = 99999999;
//		int minIndex = 0;
//		int sum;
//		for (int i = 0; i < num_cities; i++)
//		{
//			sum = 0;
//			for (int j = 0; j < num_cities; j++)
//			{
//				sum += graph[i][j];
//			}
//			if (sum < min)
//			{
//				min = sum;
//				minIndex = i;
//			}
//		}
//		
//		cout << minIndex+1 << endl;
//	}
//	return 0;
//}