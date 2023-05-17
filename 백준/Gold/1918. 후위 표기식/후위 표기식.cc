#include <iostream>
#include <string>
#include <stack>

using namespace std;

string str;
stack<char> st;


void print_ans(int start)
{
	for(int i = start; i < str.size(); i++)
	{
		if(str[i] == '(')
			st.push(str[i]);
		else if(str[i] == ')')
		{
			while(st.top() != '(')
			{
				cout << st.top();
				st.pop();
			}
			st.pop();
		}
		else if(str[i] == '+' || str[i] == '-')
		{
			while(!st.empty() && st.top() != '(')
			{
				cout << st.top();
				st.pop();
			}
			st.push(str[i]);
		}
		else if(str[i] == '*' || str[i] == '/')
		{
			while(!st.empty() && (st.top() == '*' || st.top() == '/'))
			{
				cout << st.top();
				st.pop();
			}
			st.push(str[i]);
		}
		else
		{
			cout << str[i];
		}
	}
	while(!st.empty())
	{
		cout << st.top();
		st.pop();
	}
}

int main()
{
	cin >> str;
	print_ans(0);
	cout << endl;
}