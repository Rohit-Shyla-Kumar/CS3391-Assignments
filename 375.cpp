//#include <iostream>
//#include <cstring>
//#include <string>
//#include <queue>
//#include <algorithm>
//#include <stdio.h>
//using namespace std;
//
//int a, b, c, d, T;
//int steps = 0;
//inline bool valid(int cap,int T)
//{
//	return cap > T;
//}
//
//class arrangement {
//public:
//	int a, b, c, d;
//	int steps;
//	arrangement(int _a,int _b,int _c,int _d,int _steps)
//	{
//		a = _a;
//		b = _b;
//		c = _c;
//		d = _d;
//		steps = _steps;
//	}
//};
//inline void getEm(queue<arrangement> &q, int a1, int b1, int c1, int d1,int cupToBeFilled,int pos1,int pos2,bool vis[30][30][25][25],int s,bool flag)
//{
//	int temp1, temp2;
//	
//	if (flag)
//	{
//		if (cupToBeFilled < (a1 + b1))
//		{
//			temp1 = cupToBeFilled;
//			temp2 = a1 + b1 - cupToBeFilled;
//			
//		}
//		else
//		{
//			temp1 = a1 + b1;
//			temp2 = 0;
//		}
//	}
//	else
//	{
//		if (cupToBeFilled < (a1 + b1))
//		{
//			//cout << a1 << " " << b1 << " " << cupToBeFilled << endl;
//			temp1 = a1 + b1 - cupToBeFilled;
//			temp2 = cupToBeFilled;
//			/*if (pos1 == 1 && pos2 == 2)
//				cout << temp1 << " " << temp2 << endl;*/
//		}
//		else
//		{
//			temp1 = 0;
//			temp2 = a1 + b1;
//		}
//	}
//	
//	if (pos1 == 0 && pos2 == 1)
//	{
//		if (vis[temp1][temp2][c1][d1] == false)
//		{
//			vis[temp1][temp2][c1][d1] = true;
//			q.push(*(new arrangement(temp1, temp2, c1, d1, s + 1)));
//		}
//		return;
//	}
//	if (pos1 == 0 && pos2 == 2)
//	{
//		if (vis[temp1][c1][temp2][d1] == false)
//		{
//			vis[temp1][c1][temp2][d1] = true;
//			q.push(*(new arrangement(temp1, c1, temp2, d1, s + 1)));
//		}
//		return;
//	}
//	if (pos1 == 0 && pos2 == 3)
//	{
//		if (vis[temp1][c1][d1][temp2] == false)
//		{
//			vis[temp1][c1][d1][temp2] = true;
//			q.push(*(new arrangement(temp1, c1, d1, temp2, s + 1)));
//		}
//		return;
//	}
//
//	else if (pos1 == 1 && pos2 == 2)
//	{
//		if (vis[c1][temp1][temp2][d1] == false)
//		{
//			vis[c1][temp1][temp2][d1] = true;
//				q.push(*(new arrangement(c1, temp1, temp1, d1, s + 1)));
//		}
//		return;
//	}
//	else if (pos1 == 1 && pos2 == 3)
//	{
//		if (vis[c1][temp1][d1][temp2] == false)
//		{
//			vis[c1][temp1][d1][temp2] = true;
//			q.push(*(new arrangement(c1, temp1, d1, temp2, s + 1)));
//		}
//	}
//	else if (pos1 == 2 && pos2 == 3)
//	{
//		if (vis[c1][d1][temp1][temp2] == false)
//		{
//			vis[c1][d1][temp1][temp2] = true;
//			q.push(*(new arrangement(c1, d1, temp1, temp2, s + 1)));
//		}
//		return;
//	}
//}
//inline int BFS(int T,bool vis[30][30][25][25])
//{
//	queue<arrangement> q;
//
//	q.push(*(new arrangement(0, 0, 0, 0, 0)));
//	vis[0][0][0][0] = true;
//	while (!q.empty())
//	{
//		//cout << "shaata" << endl;
//		int a1 = q.front().a;
//		int b1 = q.front().b;
//		int c1 = q.front().c;
//		int d1 = q.front().d;
//		int s = q.front().steps;
//		//cout << a1 << " " << b1 << " " << c1 <<" " << d1 << endl;
//			//cout << a1 << b1 << c1 << d1 << s << endl;
//		
//		//int diff = temp - T;
//		q.pop();
//		if (T == a1 || T == b1 || T == c1 || T == d1)
//		{
//			//cout << a1 << " " << b1 << " " << c1 << " " << d1 << " " << T <<  endl;
//			return s;
//		}
//			
//
//		
//
//		//4 cups to empty
//		int temp = 0;
//		for (register int i = 0; i < 4; i++)
//		{
//
//			if (i == 0)
//			{
//				if (vis[temp][b1][c1][d1] == false)
//				{
//					vis[temp][b1][c1][d1] = true;
//					q.push(*(new arrangement(temp, b1, c1, d1, s + 1)));
//				}
//			}
//			else if (i == 1)
//			{
//				if (vis[a1][temp][c1][d1] == false)
//				{
//					vis[a1][temp][c1][d1] = true;
//					q.push(*(new arrangement(a1, temp, c1, d1, s + 1)));
//				}
//			}
//			else if (i % 2 == 0)
//			{
//				if (vis[a1][b1][temp][d1] == false)
//				{
//					vis[a1][b1][temp][d1] = true;
//					q.push(*(new arrangement(a1, b1, temp, d1, s + 1)));
//				}
//			}
//			else
//			{
//				if (vis[a1][b1][c1][temp] == false)
//				{
//					vis[a1][b1][c1][temp] = true;
//					q.push(*(new arrangement(a1, b1, c1, temp, s + 1)));
//				}
//			}
//			
//		}
//
//		//4 cups to fill
//		//temp = 0;
//		for (register int i = 0; i < 4; i++)
//		{
//			if (i == 0)
//			{
//				if (vis[a][b1][c1][d1] == false)
//				{
//					vis[a][b1][c1][d1] = true;
//					//cout << s + 1 << endl;
//					q.push(*(new arrangement(a, b1, c1, d1, s + 1)));
//					//cout <<"steps" <<  q.front().steps << endl;
//				}
//			}
//			else if (i == 1)
//			{
//				if (vis[a1][b][c1][d1] == false)
//				{
//					vis[a1][b][c1][d1] = true;
//					//cout << s + 1 << endl;
//					q.push(*(new arrangement(a1, b, c1, d1, s + 1)));
//					//cout <<"steps" <<  q.front().steps << endl;
//				}
//			}
//			else if (i % 2 == 0)
//			{
//				if (vis[a1][b1][c][d1] == false)
//				{
//					vis[a1][b1][c][d1] = true;
//					//cout << s + 1 << endl;
//					q.push(*(new arrangement(a1, b1, c, d1, s + 1)));
//					//cout <<"steps" <<  q.front().steps << endl;
//				}
//			}
//			else
//			{
//				if (vis[a1][b1][c1][d] == false)
//				{
//					vis[a1][b1][c1][d] = true;
//					//cout << s + 1 << endl;
//					q.push(*(new arrangement(a1, b1, c1, d, s + 1)));
//					//cout <<"steps" <<  q.front().steps << endl;
//				}
//			}
//
//
//
//		}
//		
//		//4*3 ways to move flour from one cup to the other
//		getEm(q, a1, b1, c1, d1, b, 0, 1, vis, s,false);
//		getEm(q, a1, b1, c1, d1, a, 0, 1, vis, s,true);
//		getEm(q, a1, c1, b1, d1, c, 0, 2, vis, s,false);
//		getEm(q, a1, c1, b1, d1, a, 0, 2, vis, s, true);
//		getEm(q, a1, d1, b1, c1, d, 0, 3, vis, s, false);
//		getEm(q, a1, d1, b1, c1, a, 0, 3, vis, s, true);
//
//		/*getEm(q, b1, c1, a1, d1, c, 1, 2, vis, s, false);*/
//		int temp123, temp234;
//		if ((b1 + c1) > c)
//		{
//			temp123 = b1 + c1 - c;
//			temp234 = c;
//		}
//		else
//		{
//			temp123 = 0;
//			temp234 = b1 + c1;
//		}
//		if (vis[a1][temp123][temp234][d1] == 0)
//		{
//			vis[a1][temp123][temp234][d1] = 1;
//			q.push(*(new arrangement(a1, temp123, temp234, d1,s+1)));
//		}
//
//		/*getEm(q, b1, c1, a1, d1, b, 1, 2, vis, s, true);*/
//		temp123=0, temp234=0;
//		if ((b1 + c1) > b)
//		{
//			temp123 = b;
//			temp234 = b1+c1 -b;
//		}
//		else
//		{
//			temp123 = b1+c1;
//			temp234 = 0;
//		}
//		if (vis[a1][temp123][temp234][d1] == 0)
//		{
//			vis[a1][temp123][temp234][d1] = 1;
//			q.push(*(new arrangement(a1, temp123, temp234, d1, s + 1)));
//		}
//
//		getEm(q, b1, d1, a1, c1, d, 1, 3, vis, s, false);
//		getEm(q, b1, d1, a1, c1, b, 1, 3, vis, s, true);
//		getEm(q, c1, d1, a1, b1, d, 2, 3, vis, s, false);
//		getEm(q, c1, d1, a1, b1, c, 2, 3, vis, s, true);
//
//	}
//	return -1;
//}
//int main()
//{
//	
//	while (~scanf("%d%d%d%d%d",&a,&b,&c,&d,&T))
//	{
//		bool vis[30][30][25][25];
//		memset(vis, false, sizeof(vis));
//		if (T > a&&T > b&&T > c&&T > d)
//		{
//			printf("-1\n");
//			continue;
//		}
//		if (T == a || T == b || T == c || T == d)
//		{
//			printf("1\n");
//			continue;
//		}
//		printf("%d\n",BFS(T,vis));
//	}
//	return 0;
//}