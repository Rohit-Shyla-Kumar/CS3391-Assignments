#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main()
{
	int cows, games, a, b;
	while (cin >> cows >> games)
	{
		int wins[100][100];
		int losses[100][100];
		memset(wins, 0, sizeof(wins));
		memset(losses, 0, sizeof(losses));
		bool ranked_cow[100];
		int count = cows;
		memset(ranked_cow, true, sizeof(ranked_cow));
		for (int i = 0; i < games; i++)
		{
			cin >> a >> b;
			//a beats b
			wins[a - 1][b - 1] = 1;
			losses[b - 1][a - 1] = 1;
		}
		for (int lol = 0; lol < cows; lol++)
		{
			for (int i = 0; i < cows; i++)
			{
				for (int j = 0; j < cows; j++)
				{
					if(wins[i][lol]==1 && wins[lol][j] == 1)
						wins[i][j] = 1;
					if (losses[i][lol] == 1 && losses[lol][j] == 1)
						losses[i][j] = 1;
				}
			}
		}
		//for (int i = 0; i < cows; i++)
		//{
		//	for (int j = 0; j < cows; j++)
		//	{
		//		cout << wins[i][j] << " ";

		//	}
		//	cout << endl;
		//}
		//for (int i = 0; i < cows; i++)
		//{
		//	for (int j = 0; j < cows; j++)
		//	{
		//		cout << losses[i][j] << " ";
		//	}
		//	cout << endl;
		//}
		for (int i = 0; i < cows; i++)
		{
			for (int j = 0; j < cows; j++)
			{
				if (i == j)
					continue;
				if (wins[i][j] == 0 && losses[i][j] == 0)
				{
					ranked_cow[i] = false;
					break;
				}
			}
		}
		int ctr=0;
		for (int i = 0; i < cows; i++)
		{
			if (ranked_cow[i] == true)
				ctr++;
		}

		cout << ctr << endl;
	}
	return 0;
}