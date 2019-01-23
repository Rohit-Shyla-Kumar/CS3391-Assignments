//#include <iostream>
//#include <stdio.h>
//#include <math.h>
//#include <string>
//#include <string.h>
//
//
//using namespace std;
//inline bool isSquare(int n,int&s)
//{
//	double sr = sqrt(n);
//	s = (int)sr;
//	return ((sr - floor(sr)) == 0);
//}
//int main()
//{
//	int T;
//	scanf("%d", &T);
//	string line;
//	getline(cin, line);
//	while (T--)
//	{
//		string input;
//		
//		getline(cin, input);
//		int s=0;
//		if (!isSquare(input.length(),s))
//		{
//			printf("INVALID\n");
//			continue;
//		}
//		int charsprinted = 0;
//		register int i = 0;
//		int ctr = 0;
//		while (charsprinted != input.length())
//		{
//			i = ctr;
//			for (; i < input.length(); i += s)
//			{
//				printf("%c", input[i]);
//				charsprinted++;
//			}
//			ctr++;
//		}
//		printf("\n");
//	}
//	return 0;
//}