#include <string>
#include <iostream>

using namespace std;

int main()
{
	int t,ctr = 0;
	string word;
	scanf("%d", &t);
	while (ctr < t)
	{
		ctr++;
		cin >> word;
		int max = 0;
		int len = word.length();
		int lastIndex=0;
		char m;
		string seq;
		int seqLen = 0;
		for (int i = 0; i < len; i++)
		{
			if (word[i] >= max)
				max = (int)(word[i]);
		}
		m = max;
		while (m >='a')
		{
			for (int i = lastIndex; i < len; i++)
			{
				if (word[i] == m)
				{
					seq+= word[i];
					lastIndex = i;
					seqLen++;
				}
			}
			m--;
		}
		cout << seq << endl;
	}
	return 0;
}