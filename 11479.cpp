//#include <iostream>
//using namespace std;
//int main()
//{
//	unsigned long int t, test = 1, a, b, c;
//	cin >> t;
//	int ctr = 0;
//	while (ctr <t)
//	{
//		ctr++;
//		cin >> a >> b >> c;
//		printf("Case %ld: ", test++);
//		if (a + b <= c || b + c <= a || a + c <= b) 
//			cout << "Invalid\n";
//		else if (a <= 0 || b <= 0 || c <= 0) 
//			cout << "Invalid\n";
//		else
//		{
//			if (a == b && b == c)
//				cout << "Equilateral\n";
//			else if (a == b || a == c || b == c) 
//				cout << "Isosceles\n";
//			else  
//				cout << "Scalene\n";
//		}
//	}
//	return 0;
//}