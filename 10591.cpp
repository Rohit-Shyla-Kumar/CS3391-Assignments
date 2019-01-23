//#include <stdio.h>
//#include <math.h>
//#include <iostream>
//
//using namespace std;
//
//
//int numSquareSum(int n)
//{
//	int squareSum = 0;
//	while (n)
//	{
//		squareSum += (n % 10) * (n % 10);
//		n /= 10;
//	}
//	return squareSum;
//}
//
//bool isHappynumber(int n)
//{
//	int slow, fast;
//
//	slow = fast = n;
//	do
//	{
//		slow = numSquareSum(slow);
//		fast = numSquareSum(numSquareSum(fast));
//
//	} while (slow != fast);
//	return (slow == 1);
//}
//
//int main()
//{
//	int t, ctr=0;
//	scanf("%d", &t);
//	while (t--)
//	{
//		ctr++;
//		int num;
//		scanf("%d", &num);
//		
//		if (num == 1)
//		{
//			printf("Case #%d: %d is a Happy number.\n",ctr,1);
//			continue;
//		}
//		
//		bool flag = isHappynumber(num);
//		if(flag)
//			printf("Case #%d: %d is a Happy number.\n", ctr, num);
//		else
//			printf("Case #%d: %d is an Unhappy number.\n", ctr, num);
//	}
//	return 0;
//}