//#include <algorithm>
//#include <stdio.h>
//#include <math.h>
//#include <iostream>
////just accept all the points for set1, then 
//using namespace std;
//#define MAX 2<<20
//#define OTHER 2 << 14
//#define EPSILON 0.00001
//class Point2D {
//public: int x, y;
//};
//Point2D first[MAX];
//Point2D second[OTHER];
//
//inline float areaX2(Point2D &a, Point2D &b, Point2D &c)
//{
//	return abs((float)(a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y))/2.0);
//	//triangle are formula, half into base into height
//}
//
//inline bool collinear(Point2D &a, Point2D &b, Point2D &c)
//{
//	int o = (b.y - a.y)*(c.x - b.x) - (b.x - a.x)*(c.y - b.y);
//	return (o == 0);
//}
//inline bool in(float a, float b, float c, float d)
//{
//	if (a <= (b + c + d+EPSILON) && a >= (b + c + d - EPSILON))
//		return true;
//	return false;
//}
//inline void getAns(int num,int num1,int p)
//{
//	bool flag = false;
//	for (register int a = 0; a < num; a++)
//	{
//		for (register int b = 0; b < num; b++)
//		{
//			if (a != b)
//			{
//				for (register int c = 0; c < num; c++)
//				{
//					if (a != c && b != c)
//					{
//						if (!collinear(first[a], first[b], first[c])) // this means it forms a triangle
//						{
//							float original = areaX2(first[a], first[b], first[c]);
//							float trig1 = areaX2(second[p], first[b], first[c]);
//							float trig2 = areaX2(first[a], second[p], first[c]);
//							float trig3 = areaX2(first[a], first[b], second[p]);
//							//cout << original << " " << trig1 << " " << trig2 << " " << trig3 << " " << endl;
//							if (in(original, trig1, trig2, trig3))
//							{
//								//cout << original << " " << trig1 << " " << trig2 << " " << trig3 << " " << endl;
//								flag = true;
//								break;
//							}
//						}
//					}
//				}
//			}
//			if (flag == true)
//				break;
//		}
//		if (flag == true)
//			break;
//	}
//	if (flag)
//		printf("inside\n");
//	else
//		printf("outside\n");
//}
//int main()
//{
//	/*Point2D a,b,c;
//	a.x = 1;
//	a.y = 3;
//	b.x = 2;
//	b.y = 3;
//	c.x = 3;
//	c.y = 4;
//	cout << areaX2(a, b, c)<< endl;
//	cout << collinear(a, b, c);*/
//
//	//so now lets have two sets of points. 
//	
//
//	int numPoints;
//	while (~scanf("%d", &numPoints))
//	{
//		int ctr = 0;
//		while (ctr<numPoints)
//		{
//			scanf("%d%d", &first[ctr].x, &first[ctr].y);
//			ctr++;
//		}
//		int secondNumPoints;
//		scanf("%d", &secondNumPoints);
//		int ctr1 = 0;
//		while (ctr1<secondNumPoints)
//		{
//			scanf("%d%d", &second[ctr1].x, &second[ctr1].y);			
//			ctr1++;
//		}
//		for (int a = 0; a < secondNumPoints; a++)
//		{
//			getAns(numPoints, secondNumPoints, a);
//		}
//		
//	}
//	return 0;
//}