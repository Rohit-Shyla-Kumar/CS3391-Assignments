//#include <iostream>
//#include <stdio.h>
//#include <string>
//#include <stdlib.h>
//#include <math.h>
//#include <iomanip>
//using namespace std;
//
//int main()
//{
//	
//	int T;
//	cin >> T;
//	int ctr = 0;
//	while (ctr<T)
//	{
//		ctr++;
//		string input;
//		cin >> input;
//		int h = stoi(input.substr(0, 2));
//		int m = 60 - stoi(input.substr(3));
//		if (h == 12 && m == 60)
//		{
//			cout << setfill('0') << setw(2) << 12 << ":" << setfill('0') << setw(2) << 0 << endl;
//			continue;
//		}
//		if (m == 60)
//		{
//			m = 0;
//			h = 12 - h;
//		}
//		else
//		{
//			if(h!=12)
//				h = 12 - h;
//		}
//		if (h - 1 == 0)
//		{
//			if (m != 0)
//				h = 12;
//		}
//		else if(m!=0)
//			h = h - 1;
//		cout << setfill('0') << setw(2) << h << ":" << setfill('0') <<setw(2)<< m << endl;
//	}
//}