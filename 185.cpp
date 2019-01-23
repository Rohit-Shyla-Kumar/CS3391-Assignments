//#include <string>
//#include <stdio.h>
//#include <queue>
//#include <iostream>
//#include <functional>
//
//#define MAX_SIZE 26
//
//using namespace std;
//typedef struct TrieNode
//{
//	TrieNode* children[MAX_SIZE];
//	bool isLast;
//}Node;
//Node* root;
//Node* getNode()
//{
//	Node *node = new Node;
//	
//	for (int i = 0; i < MAX_SIZE; i++)
//	{
//		node->children[i] = NULL;
//	}
//	node->isLast = false;
//	return node;
//}
//int search(Node* root,string word)
//{
//	Node* node = root;
//	for (register int i = 0; i < word.length(); i++)
//	{
//		int ind = word[i] - 'a';
//		if (!node->children[ind])
//			return 0;
//
//		node = node->children[ind];
//	}
//	if (node != NULL && node->isLast)
//		return 1;
//
//	return 0;
//}
//void insert(Node *root,string word)
//{
//	Node *node = root;
//
//	for(register int i = 0;i<word.length();i++)
//	{
//		int ind = word[i] - 'a';
//		if (!node->children[ind])
//			node->children[ind] = getNode();
//
//		node = node->children[ind];
//	}
//	node->isLast = true;
//}
//
//
//int main()
//{
//	string word;
//	bool first = true,flag = false;
//	int index = 0;
//	priority_queue<string, vector<string>,greater<string>> q;
//	while (cin >> word)
//	{
//		string word1[300];
//		int ctr = 0;
//		for (int i = 0; i < word.length(); i++)
//		{
//			if (word[i] >= 'A'&&word[i] <= 'Z')
//				word1[ctr].push_back(word[i] - 'A' + 'a');
//			else if (word[i] >= 'a'&&word[i] <= 'z')
//				word1[ctr].push_back(word[i]);
//			else
//				ctr++;
//		}
//		register int i = 0;
//		if (first)
//		{
//			root = getNode();
//			//cout << "inserting: " << word1[0] << endl;
//			insert(root,word1[0]);
//			first = !first;
//			q.push(word1[0]);
//			i++;
//		}
//		for (; i <=ctr; i++)
//		{
//			if (!(search(root, word1[i])))
//			{
//				//cout << "inserting: " << word1[i] << endl;
//				insert(root, word1[i]);
//				q.push(word1[i]);
//			}
//		}
//		
//	}
//	//cout << q.top() <<"a" << q.top() << "b";
//	bool second = true;
//	while (!q.empty())
//	{
//		if (second)
//		{
//			q.pop();
//			second = !second;
//		}
//		cout << q.top() << endl;
//		q.pop();
//	}
//	return 0;
//}