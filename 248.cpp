//#include <iostream>
//#include <stdio.h>
//#include <math.h>
//#include <algorithm>
//
//using namespace std;
//
//#define EPSILON 0.00001
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
//class Rectangle
//{
//public:
//	Point2D tl;
//	Point2D br;
//	Segment up;
//	Segment bottom;
//	Segment left;
//	Segment right;
//	Rectangle()
//	{
//	}
//	Rectangle(Point2D _tl, Point2D _br)
//	{
//		tl = _tl;
//		br = _br;
//		up = Segment(_tl.x, _tl.y, _br.x, _tl.y);
//		bottom = Segment(_tl.x, _br.y, _br.x, _br.y);
//		left = Segment(_tl.x, _tl.y, _tl.x, _br.y);
//		right = Segment(_br.x, _tl.y, _br.x, _br.y);
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
//	if (o == 0)
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
//inline bool isWithin(Point2D &a, Rectangle &r)
//{
//	if ((a.x <= max(r.br.x, r.tl.x) && a.x >= min(r.br.x, r.tl.x)) && (a.y <= max(r.br.y, r.tl.y) && a.y >= min(r.br.y, r.tl.y)))
//		return true;
//}
//int main()
//{
//	int T;
//	scanf("%d", &T);
//	int ctr = 0;
//	while (ctr < T)
//	{
//		ctr++;
//		bool flag = false;
//		Point2D p,q, tl, br;
//		scanf("%d%d%d%d%d%d%d%d", &p.x, &p.y, &q.x, &q.y, &tl.x, &tl.y, &br.x, &br.y);
//		Rectangle r1 = Rectangle(tl, br);
//		Segment s1 = Segment(p.x,p.y, q.x,q.y);
//		if (areIntersecting(s1, r1.up))	flag = true;
//		if (areIntersecting(s1, r1.bottom))	flag = true;
//		if (areIntersecting(s1, r1.left))	flag = true;
//		if (areIntersecting(s1, r1.right))	flag = true;
//		if (isWithin(s1.first, r1))	flag = true;
//		if (isWithin(s1.second, r1))	flag = true;
//		if (flag)
//			printf("T\n");
//		else
//			printf("F\n");
//	}
//}