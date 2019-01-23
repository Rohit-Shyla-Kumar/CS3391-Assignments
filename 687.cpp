#include <iostream>

using namespace std;
int arr[10000];
int maxDiff = 0;
int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
			scanf("%d",&arr[i]);

		maxDiff = 0;
		bool flag = false;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (arr[j] - arr[i] >= maxDiff)
				{
					maxDiff = arr[j] - arr[i];
					flag = true;
				}
					
			}
		}

		if (flag)
			cout << maxDiff << endl;
		else
			cout << "QUIT" << endl;
	}
	return 0;

}