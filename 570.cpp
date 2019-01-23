#include <iostream>
#include <string>

using namespace std;
short toMoveTo[1000];
int getNumberOfMoves(char c)
{
	int num = 0;
	if (c < 'N')
		num = (int)(c - 'A');
	else
		num = ('Z' - c) + 1;
	return num;
}
int getMoveNumber(int len,string name)
{
	int shaata = len - 1;
	register int i = 1;
	unsigned int low, high;
	while (i<len)
	{
		if (name[i] == 'A')
		{
			int j = i + 1;
			bool flag = true;
			while (flag)
			{

				if (j < len&&name[j] == 'A')
					j++;
				else
					flag = false;

			}

			low = (i - 1) * 2 + len - j;
			high = (len - j) * 2 + i - 1;

			if (shaata < low&&shaata < high)
			{
				i++;
				continue;
			}
			else if (low <= high && low < shaata)
				shaata = low;
			else if (high <= low && high<shaata)
				shaata = high;
		}
		i++;
	}
	return shaata;
}
int main()
{
	int t;
	//number of testcases
	cin >> t;
	string line;
	getline(cin, line);
	string name;
	int ctr = 0;
	int numMoves = 0;
	int numCharsToMove = 0;
	while (ctr < t)
	{
		//increment counter and reinitialize
		ctr++;
		numMoves = 0;
		numCharsToMove = 0;
		getline(cin, name);
		int len = name.length();

		//since the first character is already selected, we may as well change it if we must
		if(name[0]!='A')
			numMoves += getNumberOfMoves(name[0]);
		//now we calculate the change for all the other characters that need to be changed 
		for (int i = 1; i < len; i++)
		{
			if (name[i] != 'A')
			{
				numMoves += getNumberOfMoves(name[i]);
				toMoveTo[numCharsToMove++] = i;
			}	
		}
		/*cout << "Just changing all the characters, without moving :" << numMoves << endl;
		cout << "All the character indices we need to visit :"  ;
		//for (int i = 0; i < numCharsToMove; i++)
		//	cout << toMoveTo[i] << " ";
		//cout << endl;*/

		//int currentPos = 0;
		//int normalIndex = 0;
		//int normal = toMoveTo[normalIndex];

		//int shaataIndex = numCharsToMove - 1;
		//int shaata = toMoveTo[shaataIndex];

		////cout << normal << "   " << shaata << endl;
		////We just keep picking the closest character we need to change, counting steps to it until we have visited every character
		//while (numCharsToMove > 0)
		//{
		//	int  dist = 999999;
		//	int move = 0;
		//	//4 cases, the closest could be to the left, left with wrap around, right or right with wrap around
		//	if (normal > currentPos && dist > normal - currentPos)
		//	{
		//		dist = normal - currentPos;
		//		move = 1;
		//	}
		//	if (normal < currentPos && dist > len - currentPos + normal)
		//	{
		//		dist = len - currentPos + normal;
		//		move = 2;
		//	}
		//	if (shaata < currentPos && dist > currentPos - shaata)
		//	{
		//		dist = currentPos - shaata;
		//		move = 3;
		//	}
		//	if (shaata > currentPos && dist > currentPos + len - shaata)
		//	{
		//		dist = currentPos + len - shaata;
		//		move = 4;
		//	}
		//	numMoves += dist;
		//	if (move == 1 || move == 2)
		//	{
		//		currentPos = normal;
		//		normal = toMoveTo[++normalIndex];
		//	}
		//	else
		//	{
		//		currentPos = shaata;
		//		shaata = toMoveTo[--shaataIndex];
		//	}
		//	/*cout << "Distance to next index :" << dist << endl;
		//	cout << "Index selected :" << currentPos << endl;*/
		//	numCharsToMove--;
		//}


		numMoves += getMoveNumber(len, name);

		printf("%d\n", numMoves);
	}
	return 0;
}