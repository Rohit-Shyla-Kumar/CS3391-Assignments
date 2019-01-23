//#include <stdio.h>
//#include <string>
//#include <iostream>
//#include <string.h>
//#include <math.h>
//#include <stdlib.h>
//#include <iomanip>
//using namespace std;
//
//class Point2D {
//public:
//	double x, y;
//}Points[100000];
//
//double eucledianDist(Point2D a, Point2D b)
//{
//	double x = a.x - b.x;
//	double y = a.y - b.y;
//	return (sqrt(x*x + y * y));
//}
//int main()
//{
//	int T;
//	int ctr = 0;
//	//ios_base::sync_with_stdio(false);		
//	//	cin.tie(NULL);
//
//	while (~scanf("%d", &T))
//	{
//		if (T == 0)
//			return 0;
//		
//		//int x, y;
//		for (register int i = 0; i < T; i++)
//		{
//			cin >> Points[i].x >> Points[i].y;
//		}
//		double min = 99999;
//		for (register int i = 0; i < T-1; i++)
//		{
//			for (register int j = i + 1; j <T; j++)
//			{
//				double temp = eucledianDist(Points[i], Points[j]);
//				if (temp < min)
//					min = temp;
//				//cout << temp << endl;
//			}
//		}
//		if (min > 10000)
//			cout << "INFINITY\n";
//		else
//			cout << fixed<< setprecision(4) << min << endl;
//	}
//	return 0;
//}