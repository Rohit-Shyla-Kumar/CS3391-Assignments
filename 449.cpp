//#include <iostream>
//#include <string>
//using namespace std;
//
//void printField(char field[][50], int m, int n)
//{
//	for (int j = 0; j < n; j++)
//	{
//		for (int k = 0; k < m; k++)
//		{
//			cout << field[j][k] << " ";
//		}
//		cout << endl;
//	}
//}
//
//
//int countLength(char field[][50],int m,int n)
//{
//	//printField(field,m,n);
//	int sum = 0;
//	for (int j = 0; j < n; j++)
//	{
//		for (int k = 0; k < m; k++)
//		{
//			if (field[j][k] == '#')
//			{
//				if (j & 1)
//				{
//					//up-right
//					if (j != 0 && k != m - 1 && field[j - 1][k + 1] == '.')
//						sum += 1;
//					//down-right
//					if (j != n - 1 && k != m - 1 && field[j + 1][k + 1] == '.')
//						sum += 1;
//				}
//				else
//				{
//					//up-left
//					if (j != 0 && k != 0 && field[j - 1][k - 1] == '.')
//						sum += 1;
//					//down-left
//					if (j != n - 1 && k != 0 && field[j + 1][k - 1] == '.')
//						sum += 1;
//				}
//				//up
//				if (j != 0 && field[j - 1][k] == '.')
//					sum += 1;
//				//left
//				if (k != 0 && field[j][k - 1] == '.')
//					sum += 1;
//				//right
//				if (k != m - 1 && field[j][k + 1] == '.')
//					sum += 1;
//				//down
//				if (j != n - 1 && field[j + 1][k] == '.')
//					sum += 1;
//			}
//		}
//	}
//	//printField(field,m,n);
//	return sum;
//}
//int main()
//{
//	char field[50][50];
//	int n = 0, m = 0, j = 0;
//	string line;
//	while ((getline(cin,line)))
//	{
//		if (line.length()!=0)
//		{
//			m = line.length();
//			for (int i = 0; i < line.length(); i++)
//			{
//				field[n][i] = line[i];
//				//cout << n << " " << i << " " << field[n][i] << endl;
//			}
//			n++;
//		}
//		else
//		{
//			int sum = countLength(field,m,n);
//			cout << sum << endl;
//			n = 0;
//			j = 0;
//			m = 0;
//		}
//		
//	}
//	return 0;
//}