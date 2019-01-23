#include <iostream>
#include <string>

using namespace std; 
short c[1001][1001];
int main()
{
	string word;
	string word1;
	while (getline(cin,word)) 
	{
		word = 'a' + word;
		getline(cin, word1);
		word1 = 'a' + word1;
		int m = word.length();
		int n = word1.length();
		
		for (int i = 1; i < m; i++)
			c[i][0] = 0;
		for (int j = 0; j < n; j++)
			c[0][j] = 0;

		/*
		key:
		 1 = up left
		 2 = left 
		 3 = up
		 */
		for (int i = 1; i < m; i++)
		{
			for (int j = 1; j < n;j++)
			{
				if (word[i] == word1[j])
					c[i][j] = c[i - 1][j - 1] + 1;
				else if (c[i - 1][j] < c[i][j - 1])
					c[i][j] = c[i][j - 1];
				else
					c[i][j] = c[i-1][j];
			}
		}

		cout << c[m-1][n-1] << endl;
	}
	return 0;
}