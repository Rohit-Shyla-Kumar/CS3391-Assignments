//#include <iostream>
//using namespace std;
//int main()
//{
//	short arr[50][50];
//	short n, m;
//	while (cin >> n >> m)
//	{
//		if (n == 0 && m == 0)
//			break;
//		short answer = 4;
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < m; j++)
//			{
//				cin >> arr[i][j];
//				if (arr[i][j] == 1 && ((i == 0 || i == n - 1) || (j == 0 || j == m - 1)))
//					answer = 2;
//			}
//		}
//		printf("%d\n",answer);
//	}
//	return 0;
//}