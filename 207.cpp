#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <map>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

void printGraph(int graph[205][205], int num_rooms);
int Dijkstras(int vis[205],int num_rooms,int aaaa[205],int graph[205][205],map<string,string> &parent,string places[205],int x)
{
	for (register int i = 0; i < num_rooms - 1; i++)
	{
		int a, max = 999999;
		for (register int j = 0; j<num_rooms; j++)
			if (vis[j] == 0 && aaaa[j] < max)
			{
				max = aaaa[j];
				a = j;
			}
		vis[a] = 1;
		for (register int b = 0; b < num_rooms; b++)
		{
			if (vis[b] == 0 && graph[a][b] && aaaa[a] != 999999 && aaaa[b] > aaaa[a] + graph[a][b])
			{
				aaaa[b] = aaaa[a] + graph[a][b];
				//cout << places[b] << " -> "<<  places[a];
				parent[places[b]] = places[a];
			}
		}
	}
	return aaaa[x];
}
int main()
{
	int num_rooms;
	while (~scanf("%d", &num_rooms))
	{
		string places[205];
		int graph[205][205];
		bool first = true;
		int hallInd, officeInd;
		for (int i = 0; i < num_rooms; i++)
		{
			if (first)
			{
				cin.ignore();
				first = !first;
			}
			getline(cin, places[i]);
			if (places[i] == "hall")
				hallInd = i;
			if (places[i] == "office")
				officeInd = i;
		}
		int paths;
		bool flag1 = false;
		for (int i = 0; i < num_rooms; i++)
		{
			for (int j = 0; j < num_rooms; j++)
			{
				graph[i][j] = (i == j) ? 0 : 999999;
			}
		}
		scanf("%d", &paths);
		string shaata;
		for (register int i = 0; i < paths; i++)
		{
			int w1=0, w2=0;
			//for the \n
			if (!flag1)
			{
				getline(cin, shaata);
				flag1 = true;
			}
			char a[100], place1[25], place2[25];
			memset(place2, ' ', sizeof(place2));
			fgets(a, 100, stdin);
			short cut2 = -1, cut1 = 0;
			//cut1 = a.find(":");
			//x = cut1;
			//cout << a[0] << endl;
			while (a[cut1] != 58)
			{
				place1[cut1] = a[cut1];
				cut1++;
			}
			place1[cut1] = '\0';
			cut1++;

			for (register int b = 0; b < strlen(a); b++, cut1++)
			{
				cut2 = -1;
				place2[b] = a[cut1];
				string temp(place2, b + 1);
				//cout << "temp:" << temp << endl;
				
				for (register int abc = 0; abc < num_rooms; abc++)
				{
					/*cout << places[abc] << "   " << temp << endl;
					cout << places[abc].compare(temp)<<endl;*/
					if (places[abc] == temp)
						cut2 = abc;
				}
				if (cut2!=-1)
				{
					//cout << "tempIn:" << temp << endl;
					place2[b + 1] = '\0';
					break;
				}

			}
			//shaata is the string with just 1 or 2 number so now we can check that and update matrix
			string shaata(a, strlen(a)-1);
			string shaata1(place1, strlen(place1));
			string shaata2(place2, strlen(place2));
			shaata.erase(0, cut1 + 1);
			if (shaata[0] == 32)
				shaata.erase(0, 1);

			//cout << shaata1 << shaata2 <<"shaata:"<< shaata << endl;

			string delimiter = " ";
			short x = shaata.find(delimiter);
			//cout << shaata << endl;
			if (x == string::npos)
			{
				//cout << "Inside:" << shaata << endl;
				w1 = stoi(shaata);
			}
			else
			{
				string tempor = shaata.substr(0, x);
				w1 = stoi(tempor);
				shaata.erase(0, x);
				w2 = stoi(shaata);
			}
			/*cout << w1 << "," << w2;*/

			for(register int c = 0;c<num_rooms;c++)
				if (places[c] == shaata1)
					cut1 = c;

			//now update the graph
			if(graph[cut1][cut2]>w1)
				graph[cut1][cut2] = w1;
			if(w2&&graph[cut2][cut1]>w2)
				graph[cut2][cut1] = w2;
			
		}
		//printGraph(graph,num_rooms);
		
		map <string, string>parent;
		//so now we'll run floyd warshall (dijkstras*) and store the parent of each 
		for (register int i = 0; i < num_rooms; i++)
			parent[places[i]] = "0";

		//lol whoops floyd warshall doesn't work 
		/*for (register int k = 0; k < num_rooms; k++)
		{
			for (register int i = 0; i < num_rooms; i++)
			{
				for (register int j = 0; j < num_rooms; j++)
				{
					if (graph[i][k] + graph[k][j] < graph[i][j])
					{
						graph[i][j] = graph[i][k] + graph[k][j];
						parent[places[j]] = places[k];
					}
				}
			}
		}*/

		int aaaa[205];
		for (register int i = 0; i < num_rooms; i++)
			aaaa[i] = 999999;
		int vis[205];
		memset(vis, 0, sizeof(vis));
		aaaa[officeInd] = graph[officeInd][officeInd];

		int res1 = Dijkstras(vis, num_rooms, aaaa, graph, parent, places,hallInd);

		for (register int i = 0; i < num_rooms; i++)
			aaaa[i] = 999999;
		memset(vis, 0, sizeof(vis));
		aaaa[hallInd] = graph[hallInd][hallInd];

		//for (register int i = 0; i < num_rooms; i++)
		//	cout << parent[places[i]] << " ";
		//cout << endl;

		string abcd = parent["hall"];
		//vector<string> lol;
		string concat="";
		concat += " -> hall";
		//lol.push_back("hall");
		while (abcd != "office"&&abcd != "0")
		{
			concat = " -> " + abcd+concat;
			//lol.push_back(abcd);
			abcd = parent[abcd];
		}
		//lol.push_back("office");
		concat = "office"+concat;
		
		int res2 = Dijkstras(vis, num_rooms, aaaa, graph, parent, places,officeInd);
		//printGraph(graph, num_rooms);
		res2 += res1;
		cout << res2 << endl;
		cout << concat;
		concat = "";
		concat += " -> office";
		abcd = parent["office"];
		while (abcd != "hall"&&abcd != "0")
		{
			concat = " -> "+abcd+concat;
			//lol.push_back(abcd);
			abcd = parent[abcd];
		}
		//lol.push_back("hall");
		cout << concat <<endl << endl;
	/*	for (register int i = lol.size() - 1; i > 0; i--)
			printf("%s->", lol[i]);
		printf("%s\n\n", lol[0]);*/
	}
	return 0;
}
void printGraph(int graph[205][205], int num_rooms)
{
	for (int i = 0; i < num_rooms; i++)
	{
		for (int j = 0; j < num_rooms; j++)
		{
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}
}