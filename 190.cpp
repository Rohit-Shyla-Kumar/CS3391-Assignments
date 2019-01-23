

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int checkPriority(char op);

int main()
{
	stack<char> st;
	string exp;
	char post[100];
	int num;
	cin >> num;
	int i = 0, ctr = 0;
	getline(cin, exp);
	bool first = true;
	while (getline(cin, exp))
	{
		if (first)
		{
			first = false;
			continue;
		}
		if (exp.length() == 0)
		{
			while (!st.empty())
			{
				post[i] = st.top();
				st.pop();
				i++;
			}
			post[i] = '\0';
			cout << post << endl;

			i = 0;
			ctr++;
			cout << endl;
		}
		else if (exp[0] >= '0' && exp[0] <= '9')
		{
			post[i] = exp[0];
			i++;
		}
		else if (exp[0] == '(')
			st.push(exp[0]);
		else if (exp[0] == ')')
		{
			while (st.top() != '(')
			{
				post[i] = st.top();
				i++;
				st.pop();
			}
			st.pop();
		}
		else if (exp[0] == '+' || exp[0] == '*' || exp[0] == '-' || exp[0] == '/')
		{
			while (1)
			{
				if (st.empty() == true || checkPriority(exp[0]) > checkPriority(st.top()))
				{
					st.push(exp[0]);
					break;
				}
				else
				{
					post[i] = st.top();
					i++;
					st.pop();
				}
			}


		}
	}

	while (!st.empty())
	{
		post[i] = st.top();
		st.pop();
		i++;
	}
	post[i] = '\0';
	cout << post << endl;
	return 0;
}

int checkPriority(char op)
{
	if (op == '(' || op == ')')
		return 1;
	else if (op == '+' || op == '-')
		return 2;
	else if (op == '*' || op == '/')
		return 3;
	return 0;
}