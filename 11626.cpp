//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//#include <algorithm>
//using namespace std;
//struct Pt {
//	long long x, y;
//};
//#define eps 1e-8
//long long checkCross(Pt o, Pt a, Pt b) {
//	return (a.x - o.x)*(b.y - o.y) - (a.y - o.y)*(b.x - o.x);
//}
//bool compare(Pt a, Pt b) {
//	if (a.x != b.x)
//		return a.x < b.x;
//	return a.y < b.y;
//}
//Pt Points[100005], Hull[200005];
//inline int findConvexHull(int numPoints)
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
//	return sol-1;
//}
//
//int main() {
//	int t, n, m, i, j;
//	char cc;
//	scanf("%d", &t);
//	while (t--) {
//		scanf("%d", &n);
//		for (i = 0, j = 0; i < n; i++) {
//			scanf("%lld %lld %c", &Points[j].x, &Points[j].y, &cc);
//			if (cc == 'Y')   j++;x	
//		}
//		m = findConvexHull(j);
//		printf("%d\n", m);
//		for (i = 0; i < m; i++)
//			printf("%lld %lld\n", Hull[i].x, Hull[i].y);
//	}
//	return 0;
//}