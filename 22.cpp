//Simple BFS program. Just find the depth of the BFS which will be the cost.
#include <iostream>
#include <string>
#include <queue>
#include <cstring>
#include <stdio.h>
using namespace std;
#define N 10000
#define SQRT_N 100
#define HALF_SQRT_N 50

int A[(N >> 6) + 1];

int primes[5700];

int ctr = 1;
bool flag; int n1, n2;
inline bool IsComp(int n) {
	return (A[n >> 6] & (1 << ((n >> 1) & 31)));
}

inline void SetComp(int n)
{
	A[n >> 6] |= (1 << ((n >> 1) & 31));
}

inline void Atkin() {
	for (register int i = 3; i<SQRT_N; i += 2)
		if (!IsComp(i))
			for (register int j = i * i; j < N; j += i + i)
				SetComp(j);
}
//bool isPrime(int num)
//{
//	int num1 = num / 2;
//	for (int i = 2; i < num1; i++)
//	{
//		if (num%i == 0)
//			return false;
//	}
//	return true;
//}
inline void BFS(int c, int t)
{
	int steps = 0;
	Atkin();
	int temp;
	short visited[10000];
	memset(visited, 0, sizeof(visited));
	queue<int> q;
	q.push(c);
	int depth = q.size();
	//we should pop one element and add all it's neighbours. It's neighbours are all prime numbers one digit away
	while (!(q.empty()))
	{
		int a = q.front();
		if (depth-- == 0)
		{
			depth = q.size() - 1;
			steps++;
		}
		/*cout << a << endl;*/
		visited[a] = 1;
		if (a == t)
		{
			printf("%d\n", steps);
			break;
		}
		q.pop();
		//change last digit, check prime, add to queue
		for (register int i = 1; i < 10; i+=2)
		{
			if (a % 10 != i)
			{
				temp = a - a % 10 + i;
				if (visited[temp] != 1 && !IsComp(temp))
				{
					visited[temp] = 1;
					//cout << temp << "  ";

					/*if (temp == t)
					{
						printf("%d\n", steps+1);
						break;
					}*/
					q.push(temp);
					//cout << endl;
				}
			}
		}
		//change second last digit, check prime, add to queue
		for (register int i = 0; i < 10; i++)
		{
			if ((a % 100) / 10 != i)
			{
				temp = a - a % 100 + a % 10 + i * 10;
				if (visited[temp] != 1 && !IsComp(temp))
				{
					visited[temp] = 1;
					//cout << temp << "  ";
					q.push(temp);
					/*if (temp == t)
					{
						printf("%d\n", steps+1);
						break;
					}*/
					//cout << endl;
				}
			}
		}
		//change third last digit, check prime, add to queue
		for (register int i = 0; i < 10; i++)
		{
			if ((a % 1000) / 100 != i)
			{
				temp = a - a % 1000 + a % 100 + i * 100;
				if (visited[temp] != 1 && !IsComp(temp))
				{
					visited[temp] = 1;
					//cout << temp << "  ";
					/*if (temp == t)
					{
						printf("%d\n", steps+1);
						break;
					}*/
					q.push(temp);
					//cout << endl;
				}
			}
		}
		//change fourth digit, check prime, add to queue
		for (register int i = 1; i < 10; i++)
		{
			if ((a % 10000) / 1000 != i)
			{
				temp = a - a % 10000 + a % 1000 + i * 1000;
				if (visited[temp] != 1 && !IsComp(temp))
				{
					visited[temp] = 1;
					//cout << temp << "  ";
					/*if (temp == t)
					{
						printf("%d\n", steps+1);
						break;
					}*/
					q.push(temp);
					//cout << endl;
				}
			}
		}
	}
}

int main()
{
	int currentNum, targetNum, T, ctr = 0, steps = 0;
	scanf("%d", &T);
	while (ctr < T)
	{
		ctr++;
		scanf("%d%d",&currentNum,&targetNum);
		if (currentNum == targetNum)
		{
			printf("%d\n", steps);
			continue;
		}
		if(IsComp(currentNum)||IsComp(targetNum))
		{
			printf("Impossible\n", steps);
			continue;
		}
		BFS(currentNum, targetNum);
	}
	return 0;
}