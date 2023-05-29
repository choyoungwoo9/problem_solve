#include <stack>
#include <iostream>
#include <string>

using namespace std;

int answer;

void solution()
{
	stack<int> st;
	string str;
	cin >> str;
	for(char i : str)
	{
		if(st.empty())
			st.push(i);
		else
		{
			if(st.top() == i)
				st.pop();
			else
				st.push(i);
		}
	}
	if(st.empty())
		answer ++;
}

int main()
{
	int T;
	cin >> T;
	for(int i = 0; i < T; i ++)
	{
		solution();
	}
	cout << answer << endl;
}