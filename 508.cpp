//#include<cstdio>
//#include<cstring>
//#include<iostream>
//#include<string>
//#include<algorithm>
//#include<queue>
//
//
//using namespace std;
//
//
//#define EPS 1e-10
//#define ll long long
//#define mx 100005
//
//char line[100005];
//char q[100005];
//int ans[mx];
//int vis[mx];
//int ch[mx][4];
//int v[mx], f[mx], last[mx];
//
//struct ac {
//	int sz;
//	void init() { memset(ch[0], 0, sizeof(ch[0])), sz = 1, f[0] = v[0] = last[0] = 0;memset(vis, 0, sizeof(vis)); }
//	int idx(char c) {
//		if (c == 'A')return 0;
//		if (c == 'C')return 1;
//		if (c == 'G')return 2;
//		if (c == 'T')return 3;
//	}
//	void insert(char* s, int id) {
//		int len = strlen(s);
//		int u = 0;
//		for (int i = 0;i < len;i++) {
//			int d = idx(s[i]);
//			if (!ch[u][d]) {
//				memset(ch[sz], 0, sizeof(ch[0]));
//				f[sz] = v[sz] = last[sz] = 0;
//				ch[u][d] = sz++;
//			}
//			u = ch[u][d];
//		}
//		ans[id] = u;
//		v[u] = 1;
//	}
//	void getfailed() {
//		queue<int>q;
//		for (int d = 0;d < 4;d++) {
//			if (!ch[0][d]) {
//				ch[0][d] = 0;continue;
//			}
//			int ret = ch[0][d];
//			last[ret] = f[ret] = 0;
//			q.push(ret);
//		}
//		while (!q.empty()) {
//			int u = q.front();q.pop();
//			for (int d = 0;d < 4;d++) {
//				if (!ch[u][d]) {
//					ch[u][d] = ch[f[u]][d];continue;
//				}
//				int ret = ch[u][d];
//				f[ret] = ch[f[u]][d];
//				last[ret] = v[f[ret]] ? f[ret] : last[f[ret]];
//				q.push(ret);
//			}
//		}
//	}
//	void find(char* s) {
//		int u = 0;int len = strlen(s);
//		for (int i = 0;i < len;i++) {
//			int d = idx(s[i]);
//			int ret = ch[u][d];
//			while (ret) {
//				vis[ret]++;
//				ret = last[ret];
//			}
//			u = ch[u][d];
//		}
//	}
//	int myans(int i) {
//		return vis[ans[i]];
//	}
//};
//
//int main()
//{
//	int t;
//	scanf("%d", &t);
//	gets_s(line);
//	ac my;
//	for (int T = 1;T <= t;T++) {
//		my.init();
//		gets_s(line);
//		gets_s(line);
//		int num;
//		scanf("%d", &num);
//		gets_s(q);
//		for (int i = 0;i < num;i++) {
//			gets_s(q);
//			my.insert(q, i);
//		}
//		my.getfailed();
//		my.find(line);
//		printf("Case #%d\n", T);
//		for (int i = 0;i < num;i++) {
//			printf("%d\n", my.myans(i));
//		}
//	}
//    return 0;
//}