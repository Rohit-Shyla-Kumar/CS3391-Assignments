//#include <stdio.h>
//#include <math.h>
//#include <cstring>
//using namespace std;
//
//int arr[35];

// Returns true if there is a subset of set[] with sun equal to given sum
//bool isSubsetSum(int set[], int n, int sum)
//{
//	// Base Cases
//	if (sum == 0)
//		return true;
//	if (n == 0 && sum != 0)
//		return false;
//
//	// If last element is greater than sum, then ignore it
//	if (set[n - 1] > sum)
//		return isSubsetSum(set, n - 1, sum);
//
//	/* else, check if sum can be obtained by any of the following
//	(a) including the last element
//	(b) excluding the last element   */
//	return isSubsetSum(set, n - 1, sum) ||
//		isSubsetSum(set, n - 1, sum - set[n - 1]);
//}
//int main()
//{
//	int num;
//	int ctr = 0;
//	while (~scanf("%d", &num))
//	{
//		memset(arr, 0, sizeof(arr));
//		ctr++;
//		for (register int a = 0; a < num; a++)
//			scanf("%d", &arr[a]);
//
//		//if (num < 3)
//		//{
//		//	printf("Case #%d: ", ctr);
//		//	for (register int a = 0; a < num-1; a++)
//		//		printf("%d ", arr[a]);
//		//	printf("%d", arr[num-1]);
//		//	printf("\n");
//		//	printf("This is an A-sequence.\n");
//		//	continue;
//		//}
//		bool flag = true;
//		if (arr[0] < 1)
//		{
//			flag = false;
//			printf("Case #%d: ", ctr);
//			for (register int a = 0; a < num; a++)
//				printf("%d ", arr[a]);
//			printf("\n");
//			printf("This is not an A-sequence.\n");
//			continue;
//		}
//		
//		for (register int a = 2; a < num; a++)
//		{
//			for (register int i = 0; i < a; i++)
//			{
//				for (register int j = 0; j < a; j++)
//				{
//
//					if (arr[j] == arr[i])
//						continue;
//					if (arr[j] + arr[i] == arr[a] || arr[a]<arr[i]||arr[a]<arr[j])
//					{
//						flag = false;
//						break;
//					}
//				}
//			}
//		}
//
//		printf("Case #%d: ",ctr);
//		for (register int a = 0; a < num; a++)
//			printf("%d ", arr[a]);
//		printf("\n");
//		if (flag)
//			printf("This is an A-sequence.\n");
//		else
//			printf("This is not an A-sequence.\n");
//	}
//	return 0;
//}