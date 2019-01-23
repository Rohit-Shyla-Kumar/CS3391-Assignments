#include <iostream>
#include <string>

using namespace std;

string toLower(string word)
{
	string word1="";
	for (int i = 0; i < word.length(); i++)
	{
		if (word[i] > 64 && word[i] < 91)
			word[i]=word[i] - 'A' + 'a';
		if ((word[i] > 96 && word[i] < 123) || word[i] == 45)
			word1 += word[i];
	}
	return word1;
}

int length(string word)
{
	int ctr = 0;
	for (int i = 0; i < word.length(); i++)
	{
		if ((word[i] > 96 && word[i] < 123) || word[i] == 45)
			ctr++;
	}
	return ctr;
}
int main()
{
	string selected;
	string word;
	int len=0;
	while (cin >> word)
	{
		if (word == "E-N-D")
			break;
		if (length(word) > len)
		{
			len = length(word);
			selected = word;
		}
	}
	selected=toLower(selected);
	cout << selected << endl;
	return 0;
}