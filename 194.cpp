#include <math.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
#define N 8
int board[N][N];
int row, col,ctr=0;
int sol[1000];
inline bool isDigSafe(int i, int j)
{
	for (register int a = 0; a < j; a++)
		if (abs(sol[a] - i) == abs(a - j))
			return false;
	return true;
}
inline bool isRowColSafe(int i,int j)
{
	////first check row safety 
	//for (register int a = 0; a < N; a++)
	//	if (board[r][a] == 1)
	//		return false;
	////now column safety 
	//for (register int a = 0; a < N; a++)
	//	if (board[a][c] == 1)
	//		return false;
	////primary diagonal safety 
	//for (register int a = 0; a < N; a++)
	//	for (register int b = 0; b < N; b++)
	//		if (a - b == r - c)
	//			if (board[a][b] == 1)
	//				return false;

	//for (register int a = 0; a < 8; a++)
	//	for (register int b = 0; b < 8; b++)
	//		if (a + b == r + c)
	//			if (board[a][b] == 1)
	//				return false;

	//return true;

	for (register int a = 0; a < j; a++)
		if (sol[a] == i)
			return false;
	
			return true;
	
}
inline bool place(int r)
{
	int i=0;
	if (sol[col]==row&&r==N)
	{
		ctr += 1;
		printf("%2d      %d", ctr, sol[0] + 1);
		for (register int a = 1; a < N; a++)
			printf(" %d", sol[a] + 1);
		printf("\n");
		return true;
	}
		

	for(;i<N;i++)
	{
		if (isRowColSafe(i, r)&&isDigSafe(i,r))
		{
			sol[r] = i;
			place(r + 1);
		}
	}
	return false;
}
inline void printHeader()
{
	printf("SOLN       COLUMN\n");
	printf(" #      1 2 3 4 5 6 7 8\n\n");
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T)
	{
		T--;
		
		
		/*for (register int i = 0; i < 8; i++)
			for (register int j = 0; j < 8; j++)
				board[i][j] = 0;*/

		scanf("%d%d", &row, &col);
		row -= 1;
		col -= 1;
		board[row][col] = 1;
		printHeader();
		ctr = 0;
		place(0);
		if(T!=0)
			printf("\n");
			
	}
	return 0;
}