
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;
int main()
{
	long double nums;
	bool first = false;
	cout << fixed;
	cout << setprecision(4);
	long double sums = 0.0;
	string input;
	while (getline(cin, input))
	{
		sums = 0.0;
		stringstream myStream(input);
		while (myStream.rdbuf()->in_avail() != 0)
		{
			myStream >> nums;
			sums += nums;
		}
		if (first == false)
		{
			cout << sums << endl;
			first = true;
		}
		else
		{
			cout << endl;
			cout << sums << endl;
		}
		
	}
	
	return 0;
}