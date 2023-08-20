#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack <int> st;
string str;

int main()
{
	cin >> str;
	for(int i = 0; i < str.size(); i++)
	{
		if(str[i] >= '0' && str[i] <= '9')
			st.push(str[i]-'0');
		else
		{
			int n2 = st.top();
			st.pop();
			int n1 = st.top();
			st.pop();
			int n3;
			if(str[i] == '+')
				n3 = n1 + n2;
			else if(str[i] == '-')
				n3 = n1 - n2;
			else if(str[i] == '*')
				n3 = n1 * n2;
			else if(str[i] == '/')
				n3 = n1 / n2;
			st.push(n3);
		}
	}
	cout << st.top() << endl;
}