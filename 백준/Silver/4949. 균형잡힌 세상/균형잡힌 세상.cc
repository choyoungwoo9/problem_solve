#include <iostream>
#include <string>
#include <stack>
using namespace std;

void solve(string &str)
{
	stack<char> st;
	for(char ch : str)
	{
		if(ch == '(')
		{
			st.push(ch);
		}
		else if(ch == ')')
		{
			if(st.empty() || st.top() != '(')
			{
				cout << "no" << "\n";
				return ;
			}
			else
				st.pop();
		}
		else if(ch == '[')
		{
			st.push(ch);
		}
		else if(ch == ']')
		{
			if(st.empty() || st.top() != '[')
			{
				cout << "no" << "\n";
				return ;
			}
			else
				st.pop();
		}
	}
	if(st.empty())
		cout << "yes\n";
	else
		cout << "no\n";
}

int main()
{
	while(1)
	{
		string str;
		std::getline(cin, str);
		if(str == ".")
			break;
		solve(str);
	}
}