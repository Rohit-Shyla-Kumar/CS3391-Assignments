#include <stdio.h>
#include <string.h>
using namespace std;


//Two testcases - aaaabaabaaabaa	and		 baedcadbcecedec
//oututs -		  aaaabaabaaabaabaaaa  and	 baedcadbcecedececbdacdeab
#define MAX_SIZE 1000020
char word[MAX_SIZE];
char word1[10000];
inline bool isPalindrome(char word[MAX_SIZE], int l, int r)
{
	while (l < r)
	{
		if (word[l] != word[r])
			return false;

		l++;
		r--;
	}
	return true;
}
int main()
{
	while (~scanf("%s", &word))
	{
		int l = 0;
		int r = strlen(word) - 1;

		if (r < 35)
		{
			if (isPalindrome(word, l, r))
			{
				printf("%s\n", word);
				continue;
			}
			int i = 0;
			int ctr = 0;
			while (l <= r)
			{
				if (isPalindrome(word, l, r))
				{
					ctr = l - 1;
					for (; ctr >= 0; i++, ctr--)
					{
						word1[i] = word[ctr];
						//printf("%c\n", word[ctr]);
					}
					break;
				}
				l++;
			}
			word1[i] = '\0';
			printf("%s%s\n", word, word1);
			continue;
		}
		
		int ctr = 0, ctr1 = 0;
		bool flag = false;
		int m = r;
		//printf("r: %d\n", r);
		for (; l < r; l++)
		{
			if (word[l] == word[r])
			{
				r--;
				flag = true;
				if (m > l)
					m = l;
			}
			else
			{
				if (flag)
				{
					l--;
					flag = false;
				}
				r = strlen(word) - 1;
				m = r;
			}
			/*printf("r: %d\n", r);
			printf("flag: %d\n", flag);*/
		}
		ctr = strlen(word);
		for (int i = m - 1; i >= 0; i--)
		{
			word[ctr++] = word[i];
		}
		word[ctr] = '\0'; 
		printf("%s\n", word);
	}
	return 0;
}