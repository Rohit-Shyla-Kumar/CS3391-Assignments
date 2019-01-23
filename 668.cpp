//#include <iostream>
//#include <stdio.h>
//#include <cstring>
//using namespace std;
//void DFS(int map[51][51], int i, int j, int m, int n)
//{
//	map[i][j] = 2;
//	//now we look all around
//
//	//down
//	if (i < m && map[i + 1][j] != 1 && map[i + 1][j] !=2)
//		DFS(map, i + 1, j, m, n);
//
//	//up
//	if (i != 0 && map[i - 1][j] != 1 && map[i - 1][j] != 2)
//		DFS(map, i - 1, j, m, n);
//
//	//left
//	if (j != 0 && map[i][j - 1] != 1 && map[i][j - 1] != 2)
//		DFS(map, i, j - 1, m, n);
//
//	//right
//	if (j < n && map[i][j + 1] != 1 && map[i][j + 1] != 2)
//		DFS(map, i, j + 1, m, n);
//
//}
//void printGraph(int g[51][51],int r, int c)
//{
//	for (register int i = 0; i < r; i++)
//	{
//		for (register int j = 0; j < c; j++)
//		{
//			if (g[i][j] == 0 || g[i][j] == 2)
//				printf(".");
//			else if (g[i][j] == 4)
//				printf("S");
//			else if (g[i][j] == 5)
//				printf("A");
//			else if (g[i][j] == 6)
//				printf("W");
//		}
//		printf("\n");
//	}
//	//printf("\n");
//}
//int main()
//{
//	
//	int r, c;
//	while (~scanf("%d%d", &r, &c))
//	{
//		if (r == 0 && c == 0)
//			return 0;
//		int map[51][51];
//		memset(map, 0, sizeof(map));
//		char temp;
//		for (register int i = 0; i < r; i++)
//			for (register int j = 0; j < c; j++)
//			{
//				cin >> temp;
//				if (temp == '.');
//				else
//					map[i][j] = 1;
//			}
//
//		if (r == 1 && c == 1)
//		{		if (map[0][0] == 1)
//			{
//				printf("W\n");
//			}
//			else
//				printf(".\n");
//		continue;
//		}
//		//printGraph(map, r, c);
//		/*if (map[r / 2][0] == 0)
//			DFS(map, r / 2, 0, r, c);
//		if (map[r / 2][c-1] == 0)
//			DFS(map, r / 2, c - 1, r, c);
//		if (map[0][c /2] == 0)
//			DFS(map, r / 2, c - 1, r, c);
//		if (map[r -1][c /2] == 0)
//			DFS(map, r / 2, c - 1, r, c);*/
//		for (register int i = 0; i<r; i++)
//			for (register int j = 0; j < c; j++)
//			{
//				if ((i == 0 || j == 0 || i == r - 1||j==c-1) && map[i][j] == 0)
//					DFS(map, i, j, r, c);
//			}
//
//		for (register int i = 0; i<r; i++)
//			for (register int j = 0; j < c; j++)
//			{
//				if (map[i][j] == 1)
//				{
//					//modelling attack zone
//					bool touching = false;
//					//down
//					if (i==r-1 || i < r && map[i + 1][j] == 2)
//						touching = true;
//					//up
//					if (i == 0 || i > 0 && map[i - 1][j] == 2)
//						touching = true;
//					//left
//					if (j==0||j > 0 && map[i][j - 1] == 2)
//						touching = true;
//					//right
//					if (j==c-1 || j < c && map[i][j + 1] == 2)
//						touching = true;
//
//					if (touching)
//					{
//						map[i][j] = 5;
//						bool touching1 = true;
//						//down
//						if (i < r && map[i + 1][j] != 2)
//							touching1 = false;
//						//up
//						if (i != 0 && map[i - 1][j] != 2)
//							touching1 = false;
//						//left
//						if (j != 0 && map[i][j - 1] != 2)
//							touching1 = false;
//						//right
//						if (j < c && map[i][j + 1] != 2)
//							touching1 = false;
//
//						if (touching1)
//							map[i][j] = 6;
//					}
//					else
//					{
//						map[i][j] = 4;
//					}
//				}
//			}
//
//
//		printGraph(map, r, c);
//	}
//	
//	return 0;
//}