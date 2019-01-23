//This is a minumum edit distance problem. The 2D cells array are used to memoize and backtrack like in MTP. 
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
using namespace std;

char a[25];
char b[25];


class Cell {
public:
	int val;
	int parent;
	Cell()
	{
		val = 0;
		parent = 0;
	}
	Cell(int i, int j)
	{
		val = i;
		parent = j;
	}
}cells[1000][1000];

void print1(int, int);

//This function initializes values in the table. Exactly the same as lcss.
void init(int len1, int len2)
{
	for (register int i = 0; i < len1+1; i++)
	{
		for (register int j = 0; j < len2+1; j++)
		{
			cells[i][j].val = INT_MAX;
			cells[i][j].parent = 0;
		}
	}
	for (register int i = 0; i <len1+1; i++)
	{
		cells[i][0].parent = 1;
		cells[i][0].val = i;
	}
	for (register int j = 0; j <len2+1; j++)
	{
		cells[0][j].parent = 2;
		cells[0][j].val = j;
	}
}
int main()
{
	
	while (cin >> a)
	{
		if (a[0] == '#')
			return 0;
		else
		{
			scanf("%s",b);
			/*gets(b);*/
			int len1= strlen(a);
			int len2 =strlen(b);
			
			init(len1, len2);
			
			for (register int i = 1; i < len1+1; i++)
			{
				for (register int j = 1; j < len2+1; j++)
				{
					if (a[i - 1] != b[j - 1])
					{
						cells[i][j].val = cells[i - 1][j - 1].val + 1;
						cells[i][j].parent = 3;
					}
					else 
						cells[i][j].val = cells[i - 1][j - 1].val;
					if (cells[i][j - 1].val + 1 < cells[i][j].val)
					{
						cells[i][j].val = cells[i][j - 1].val + 1;
						cells[i][j].parent = 2;
					}
					if (cells[i - 1][j].val + 1 < cells[i][j].val)
					{
						cells[i][j].val = cells[i - 1][j].val + 1;
						cells[i][j].parent = 1;
					}
				}
			}
			/*bool flag = true;
			while (flag)
			{

			}*/
			print1(len1, len2);
			//Print the E after 
			cout << "E" << endl;
		}
	}
	return 0;
}

void print1(int len1, int len2)
{
	
	if (len1 == 0 && len2 == 0)
		return;
	//cout << setfill('0') << setw(2);
	//deleted
	if (cells[len1][len2].parent == 1)
	{
		print1(len1 - 1, len2);
		cout << "D"  << a[len1 - 1] << setfill('0') <<  setw(2) << len2 + 1;
	}
	//inserted
	else if (cells[len1][len2].parent == 2)
	{
		print1(len1, len2 - 1);
		cout << "I" << b[len2 - 1] << setfill ('0') << setw(2) << len2;
	}
	//changed
	else if (cells[len1][len2].parent == 3)
	{
		print1(len1 - 1, len2 - 1);
		cout << "C" << b[len2 - 1] << setfill('0') << setw(2) << len2;
	}
	//equal
	else
		print1(len1 - 1, len2 - 1);
}