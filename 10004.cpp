//#include <iostream>
//#include <stdio.h>
//
//using namespace std;
//int map[200][200];
//class vertex {
//public:
//	int num, color;
//}vertices[200];
//void printGraph(int g[200][200], int r, int c)
//{
//	for (register int i = 0; i < r; i++)
//	{
//		for (register int j = 0; j < c; j++)
//		{
//			cout << g[i][j];
//		}
//		printf("\n");
//	}
//	//printf("\n");
//}
//int main()
//{
//	int n;
//	while (~scanf("%d", &n))
//	{
//		int l;
//		scanf("%d", &l);
//		int map[200][200];
//		memset(map, 0, sizeof(map));
//		for (register int i = 0; i < l; i++)
//		{
//			int tmp, tmp1;
//			scanf("%d%d", &tmp, &tmp1);
//			map[tmp][tmp1] = 1;
//			map[tmp1][tmp] = 1;
//		}
//		printGraph(map, n, n);
//		vertices[0].color = 2;
//		bool flag = true;
//		for(register int i =0;i<n && flag;i++)
//			for (register int j = 0; j < n; j++)
//			{
//				if (map[i][j] == 1)
//				{
//					if (vertices[i].color == 2 && vertices[j].color != 2)
//						vertices[j].color = 3;
//					else if (vertices[j].color == 3)
//						flag = false;
//					else if (vertices[i].color == 3 && vertices[j].color != 3)
//						vertices[j].color == 2;
//					else if (vertices[j].color == 3)
//						flag = false;
//				}
//
//			}
//		if (flag)
//			cout << "BICOLORABLE." << endl;
//		else
//			cout << "NOT BICOLORABLE." << endl;
//	}
//	return 0;
//}