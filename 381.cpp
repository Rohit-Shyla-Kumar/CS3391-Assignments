#include <iostream>
#include <string>
#include <stack>
#include <iomanip>

using namespace std;

int checkPriority(char op);
void evaluate(string expression);

int main()
{
	stack<char> st;
	string exp;
	char post[100];
	int i = 0, ctr = 0;
	while (getline(cin, exp))
	{
		for (int k = 0; k < exp.length(); k++)
		{
			if ((exp[k] >= '0' && exp[k] <= '9') || (exp[k] >= 'A' && exp[k] <= 'F'))
			{
				post[i] = exp[k];
				i++;
			}
			else if (exp[k] == '(')
				st.push(exp[k]);
			else if (exp[k] == ')')
			{
				while (st.top() != '(')
				{
					post[i] = st.top();
					i++;
					st.pop();
				}
				st.pop();
			}
			else if (exp[k] == '+' || exp[k] == '*')
			{
				while (1)
				{
					if (st.empty() == true || checkPriority(exp[k]) > checkPriority(st.top()))
					{
						st.push(exp[k]);
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
		evaluate(post);
		i = 0;
		ctr++;
	}
	return 0;
}

int checkPriority(char op)
{
	if (op == '(' || op == ')')
		return 1;
	else if (op == '+')
		return 2;
	else if (op == '*')
		return 3;
	return 0;
}
int convert(char ch)
{
	int num;
	if (ch >= '0' && ch <= '9')
		num = ch - 48;
	else
		num = ch - 55;
	return num;
}

void evaluate(string expression)
{
	stack<int> solve;
	for (int k = 0; k < expression.length(); k++)
	{
		if ((expression[k] >= '0' && expression[k] <= '9') || (expression[k] >= 'A' && expression[k] <= 'F'))
		{
			solve.push(convert(expression[k]));
		}
		else if (expression[k] == '*')
		{
			int temp1 = 0, temp2 = 0;

			temp1 = solve.top();
			solve.pop();
			temp2 = solve.top();
			solve.pop();

			int temp3 = temp1 * temp2;
			solve.push(temp3);
		}
		else if (expression[k] == '+')
		{
			int temp1 = 0, temp2 = 0;
			
			temp1 = solve.top();
			solve.pop();
			temp2 = solve.top();
			solve.pop();

			int temp3 = temp1 + temp2;
			solve.push(temp3);
		}

	}
	int ans = solve.top();
	cout << hex << uppercase << ans << endl;
}
