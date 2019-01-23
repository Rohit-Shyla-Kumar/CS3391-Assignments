//#include <stdio.h>
//#include <iostream>
//#include <vector>
//#include <string.h>
//#include <stack>
//
//using namespace std;
//
//struct point {
//	int x, y;
//	point(int a, int b)
//	{
//		x = a;
//		y = b;
//	}
//};
//
//vector<int> neighbours[1005];
//vector<point> pts;
//int main()
//{
//	int n;
//	while (~scanf("%d", &n))
//	{
//		if (n == 0)
//			return 0;
//		int a, b;
//		for (register int i = 0; i < n; i++)
//		{
//			cin >> a >> b;
//			pts.push_back(point(a, b));
//			for (register int j = 0; j < i; j++)
//			{
//				if (pts[j].x == a || pts[j].y == b)
//				{
//					neighbours[i].push_back(j);
//					neighbours[j].push_back(i);
//				}
//			}
//		}
//
//		/*for (register int i = 0; i < n; i++)
//		{
//			for (register int j = 0; j < neighbours[i].size(); j++)
//			{
//				printf("%d",neighbours[i][j]);
//			}
//			printf("\n");
//		}*/
//
//		stack<int> st;
//		st.push(0);
//		while (!st.empty())
//		{
//			int p = st.top();
//			st.pop();
//			
//		}
//	}
//	return 0;
//}