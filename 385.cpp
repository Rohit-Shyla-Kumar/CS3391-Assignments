//#include <stdio.h>
//#include <math.h>
//#include <algorithm>
//#include <iostream>
//using namespace std;
//class Point2D {
//public:
//	float x, y;
//};
//bool compare(Point2D lhs, Point2D rhs)
//{
//	//compare by y if x's are equal
//	if (lhs.x != rhs.x)
//		return lhs.x < rhs.x;
//	else
//		return lhs.y < rhs.y;
//}
//#define MAX 1010
//Point2D Points[MAX],Hull[MAX];
//int numPoints;
//int tileNum = 0;
//inline double checkCross(Point2D a, Point2D b,Point2D c){	return ((b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x));	}
//
//inline void printSol(double tile, double hull)
//{
//	printf("Tile #%d\n", tileNum);
//	double solution = (hull - tile) * 100;
//	solution /= hull;
//	printf("Wasted Space = %.2lf %\n\n", solution);
//}
//
//inline double calcAreaOfPolygon(Point2D Points[], int numPoints)
//{
//	double area = 0.0;
//	for (register int a = 0; a < numPoints; a++)
//	{
//		area += Points[a].x*Points[a + 1].y - Points[a].y*Points[a + 1].x;
//	}
//	area /= 2;
//	return fabs(area);
//}
//
//inline int findConvexHull()
//{
//	sort(Points, Points + numPoints, compare);
//	int sol = 0, i = 0, t;
//	while (i < numPoints)
//	{
//		while (sol >= 2 && checkCross(Hull[sol - 2], Hull[sol - 1], Points[i]) <= 0)
//			sol--;
//		Hull[sol++] = Points[i];
//		i++;
//	}
//
//	for (i = numPoints - 1, t = sol + 1; i >= 0; i--)
//	{
//		while (sol >= t && checkCross(Hull[sol - 2], Hull[sol - 1], Points[i]) <= 0)
//		{
//			sol--;
//		}
//		Hull[sol++] = Points[i];
//	}
//	return sol;
//}
//int main()
//{
//	while (~scanf("%d", &numPoints))
//	{
//		
//		if (numPoints == 0)
//			return 0;
//		tileNum++;
//		for (register int a = 0; a < numPoints; a++)
//		{
//			scanf("%f%f", &Points[a].x, &Points[a].y);
//			if(a==0)
//				Points[numPoints] = Points[a];
//		}
//		double areaOfTile = calcAreaOfPolygon(Points, numPoints);
//		//cout << areaOfTile << endl;
//		int sol = findConvexHull();
//		
//		//cout << sol << endl;
//	
//		double areaOfConvHull = calcAreaOfPolygon(Hull,sol-1);
//		//cout << areaOfConvHull << endl;
//		printSol(areaOfTile, areaOfConvHull);
//	}
//	return 0;
//}