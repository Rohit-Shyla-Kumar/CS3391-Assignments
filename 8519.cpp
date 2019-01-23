//#include <stdio.h>
//#include <math.h>
//
//using namespace std;
//
//int arr[100005];
//int main()
//{	
//	
//	int T;
//	
//	scanf("%d", &T);
//	while (T--)
//	{
//		int kinds, k;
//		scanf("%d%d", &kinds, &k);
//		for (register int i = 1; i <=kinds; i++)
//		{
//			scanf("%d",&arr[i]);
//		}
//		int ctr = 0;
//		int where1 = 1;
//		
//		while (where1 != kinds)
//		{
//			bool flag = true;
//			for (register int i = where1; i < k; i++)
//			{
//				if (arr[i] > 0)
//					arr[i]--;
//				else
//					flag = false;
//			}
//			if (flag)
//				ctr++;
//			where1++;
//		}
//
//		printf("%d\n", ctr);
//	}
//
//}