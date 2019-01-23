//#include <stdio.h>
//#include <math.h>
//#include <algorithm>
//#include <iostream>
//#define MAX 300
//
//using namespace std;
//
//class Point2D {
//public:
//	int x, y;
//	friend bool compare(Point2D lhs, Point2D rhs)
//	{
//		//compare by y if x's are equal
//		if (lhs.x != rhs.x)
//			return lhs.x < rhs.x;
//		else
//			return lhs.y < rhs.y;
//	}
//};
//
//class Segment {
//public:
//	Point2D first, second;
//	Segment() {}
//	Segment(int a, int b, int c, int d)
//	{
//		first.x = a;
//		first.y = b;
//		second.x = c;
//		second.y = d;
//	}
//};
//
//enum Orientation {
//	CLOCKWISE,
//	ANTICLOCKWISE,
//	COLINEAR
//};
//inline float areaX2(Point2D &a, Point2D &b, Point2D &c)
//{
//	return abs((float)(a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y))/2.0);
//	//triangle are formula, half into base into height
//}
//
//inline Orientation getOrinetation(Point2D &a, Point2D &b, Point2D &c)
//{
//	//formula referenced from geeksforgeeks at https://www.geeksforgeeks.org/check-if-two-given-line-segments-intersect/
//	int o = (b.y - a.y)*(c.x - b.x) - (b.x - a.x)*(c.y - b.y);
//	if (areaX2(a, b, c) == 0)
//		return COLINEAR;
//	else if (o > 0)
//		return CLOCKWISE;
//	else
//		return ANTICLOCKWISE;
//}
//
////The segments may not intersect conventionally, i.e, they may be colinear and intersecting
////This function checks and returns 1 if 3 colinear points are intersecting 
//inline int intersectingOnSeg(Point2D &a, Point2D &b, Point2D &c)
//{
//	//here, we're testing if point b is on the segment formed by a and c
//	//that'll only be true if two conditions are satisfied
//	//it's x is in between a and c's xs
//	//it's y is in between a and c's ys
//	//int t = 0;
//	if (b.x <= max(a.x, c.x) && b.x >= min(a.x, c.x));
//	else	return 0;
//	if (b.y <= max(a.y, c.y) && b.y >= min(a.y, c.y));
//	else	return 0;
//	return true;
//}
////Take two segments and check if they're intersecting
////First we do the conventional orientation checking as minming taught, then we check if it's colinear and on each other
//bool areIntersecting(Segment &s1, Segment &s2)
//{
//	Point2D points[4] = { s1.first,s1.second,s2.first,s2.second };
//	Orientation a1 = getOrinetation(points[0], points[1], points[2]);
//	Orientation a2 = getOrinetation(points[0], points[1], points[3]);
//	Orientation a3 = getOrinetation(points[2], points[3], points[0]);
//	Orientation a4 = getOrinetation(points[2], points[3], points[1]);
//
//	if (a1 != a2 && a3 != a4)
//		return true;
//	//cout << a1 << a2 << a3 << a4;
//	if (a1 == COLINEAR && intersectingOnSeg(points[0], points[2], points[1]))	return true;
//	if (a2 == COLINEAR && intersectingOnSeg(points[0], points[3], points[1]))	return true;
//	if (a3 == COLINEAR && intersectingOnSeg(points[2], points[0], points[3]))	return true;
//	if (a4 == COLINEAR && intersectingOnSeg(points[2], points[1], points[3]))	return true;
//
//	return false;
//}
//
//inline void getAns(int &a, short* b,int n)
//{
//	for (register int i = 0; i < n; i++)
//		if (b[i])
//			a++;
//}
//int main()
//{
//	int testcases;
//	scanf("%d", &testcases);
//	int ctr = 0;
//	while (ctr < testcases)
//	{
//		ctr++;
//		int numSegs;
//		scanf("%d", &numSegs);
//		int ctr1 = 0;
//		Segment segs[MAX];
//		while (ctr1 < numSegs)
//		{
//			int a, b, c, d;
//			scanf("%d%d%d%d", &a, &b, &c, &d);
//			segs[ctr1++] = Segment(a, b, c, d);
//		}
//
//		int ans = 0;
//		short checker[MAX];
//		for (register int i = 0; i < 300; i++)
//			checker[i] = 0;
//
//
//		for (register int a = 0; a < numSegs - 1; a++)
//		{
//			for (register int b = a + 1; b < numSegs; b++)
//			{
//				if (areIntersecting(segs[a], segs[b]))
//				{
//					checker[a] = 1;
//					checker[b] = 1;
//				}
//			}
//		}
//
//		getAns(ans, checker,numSegs);
//		//printf("%d", ans);
//		printf("%d\n", numSegs - ans);
//	}
//	return 0;
//}