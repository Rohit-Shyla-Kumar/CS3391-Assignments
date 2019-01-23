#include <iostream>

using namespace std;

// principal - use the least number of boxes by maximizing the number of nuts in each box
// maximize number of nuts by maximizing number of sections in each box within the limit of divisors
int main()
{
	long int num_boxes = 0;
	long int num_sections, nuts, divisors, cap;
	while (cin >> num_sections >> nuts >> divisors >> cap)
	{
		num_boxes = 0;
		while (nuts>0)
		{
			num_boxes++;
			if (divisors + 1 >= num_sections)
			{
				nuts -= num_sections*cap;
				divisors -= num_sections-1;
			}
			else
			{
				nuts -= (divisors + 1)*cap;
				divisors = 0;
			}
		}
		cout << num_boxes << endl;
	}
	return 0;
}