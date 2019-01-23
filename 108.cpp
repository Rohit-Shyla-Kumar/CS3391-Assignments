#include <iostream>
#include <string>

using namespace std;
int main()
{
	string names[100];
	int months[100];
	int years[100];
	int days[100];
	int selected[100] = { 0 };
	int selected1[100] = { 0 };
	int n;

	//accept number of names
	cin >> n;

	int min_year, max_year;
	int min_mon, max_mon;
	int min_day, max_day;

	//accepting input and computing min_year and max_year
	for (int i = 0; i < n; i++)
	{
		cin >> names[i] >> days[i] >> months[i] >> years[i];
		if (i == 0)
		{
			min_year = years[i];
			max_year = years[i];
		}
		else if (years[i] < min_year)
			min_year = years[i];
		else if (years[i] > max_year)
			max_year = years[i];
	}


	//computing all indexes of entries with min_year
	int j = 0;
	int j1 = 0;
	for (int i = 0; i < n; i++)
	{
		if (years[i] == min_year)
		{
			selected[j] = i;
			j++;
		}
		else if (years[i] == max_year)
		{
			selected1[j1] = i;
			j1++;
		}
	}

	//computing min_mon and max mon

	min_mon = months[selected[0]];
	max_mon = months[selected1[0]];

	for (int i = 0; i < j; i++)
	{
		if (min_mon > months[selected[i]])
			min_mon = months[selected[i]];
	}

	for (int i = 0; i < j1; i++)
	{
		if (max_mon < months[selected1[i]])
			max_mon = months[selected1[i]];
	}


	//computing all indexes of entries with min_year and min_mon
	int k = 0;
	int k1 = 0;
	for (int i = 0; i < n; i++)
	{
		if (months[i] == min_mon && years[i]==min_year)
		{
			selected[k] = i;
			k++;
		}
		else if (months[i] == max_mon && years[i]==max_year)
		{
			selected1[k1] = i;
			k1++;
		}
	}
	
	//computing min_day and max day
	min_day = days[selected[0]];
	max_day = days[selected1[0]];
	for (int i = 0; i < k; i++)
	{
		if (min_day>days[selected[i]])
			min_day = days[selected[i]];
	}
	for (int i = 0; i < k1; i++)
	{
		if (max_day<days[selected1[i]])
			max_day = days[selected1[i]];
	}

	//to output youngest person 
	for (int i = 0; i < n; i++)
	{
		if (max_day == days[i] && max_mon == months[i] && max_year == years[i])
			cout << names[i] << endl;
	}
	//to output oldest person 
	for (int i = 0; i < n; i++)
	{
		if (min_day == days[i] && min_mon == months[i] && min_year == years[i])
			cout << names[i] << endl;
	}

	return 0;
}