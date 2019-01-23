//#include <stdio.h>
//#include <math.h>
//#include <cstring>
//
//#define MAX 2 << 19
//#define MOD(n) n%1000000007
//using namespace std;
//unsigned int arr[MAX];
//void dp(int numPows,unsigned int arr1[100],int n)
//{
//	for (register int a = 0; a < numPows; a++)
//	{
//		for (register int b = arr1[a]; b <= n; b++)
//		{
//			arr[b] = arr[b] + arr[b - arr1[a]];
//			if (arr[b] > 1000000007)
//				arr[b] = MOD(arr[b]);
//		}
//	}
//
//	printf("%d\n", arr[n]);
//}
//int main()
//{
//	
//	unsigned int arr1[100];
//	int n, m;
//	while (~scanf("%d%d", &n, &m))
//	{
//		memset(arr, 0, sizeof(arr));
//		arr[0] = 1;
//		memset(arr1, 0, sizeof(arr1));
//		unsigned int numPows = 0;
//		register int i = 0;
//		double d = 1;
//
//		while (1)
//		{
//			if (d > n)
//				break;
//
//			arr1[i] = d;
//			i++;
//			numPows++;
//			d *= m;
//		}
//		
//		dp(numPows, arr1, n);
//		
//	}
//}
