//#include <stdio.h>
//
//using namespace std;
//int ans[10000000];
//int main()
//{
//	long int l, u;
//	while (~scanf("%ld%ld", &l,&u))
//	{
//		if (l == 0 && u == 0)
//			return 0;
//		if (u < l)
//		{
//			int temp = u;
//			u = l;
//			l = temp;
//		}
//		
//		for (long int i = l; i <= u; i++)
//		{
//			
//			long int num = i;
//			long int steps = 0;
//			while (!(num == 1))
//			{
//				//printf("Shaata");
//				steps++;
//				if (num & 1)
//					num = 3 * num + 1;
//				else
//					num /= 2;
//			}
//			ans[i] = steps;
//		}
//		ans[1] = 3;
//		long int max = 0,maxI=0;
//		for (long int i = l; i <= u; i++)
//		{
//			//printf("%d ",ans[i]);
//			if (ans[i] > max)
//			{
//				max = ans[i];
//				maxI = i;
//			}
//		}
//		printf("Between %ld and %ld, %ld generates the longest sequence of %ld values.\n", l, u, maxI, max);
//	}
//	return 0;
//}