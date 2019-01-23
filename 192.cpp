#include <iostream>
#include <string>

using namespace std;

int check();
 
int main()
{
	int T;
	cin >> T;
	int ctr = 0;
	while (ctr<T)
	{
		if (check() == 0)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
		if (ctr != T - 1)
			cout << endl;
		ctr++;
	}
	return 0;
}

int check()
{
	int wL, dL, wR, dR;
	int sum = 0;
	cin >> wL >> dL >> wR >> dR;
	//cout << wL << " " << dL << " " << wR << " " << dR << " " << endl;
	if (wL < 1)
		wL = check();
	if (wR < 1)
		wR = check();
	if (wL*dL == wR * dR)
		sum = wL+wR;
	return sum;
}