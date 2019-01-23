#include <iostream>
#include <cmath>

using namespace std;
int ans[11] = { -1 }; //for memoization
int move(int);
int main()
{
	int num_disks;
	while (scanf("%d",&num_disks)!=EOF)
	{
		ans[num_disks] = move(num_disks);
		printf("%d\n", ans[num_disks]);
	}
	return 0;
}

int move(int num)
{
	//dp
	if (ans[num] != 0)
		return ans[num];
	if (num == 1)
		return 2;
	return move(num - 1) * 3 + 2;
}