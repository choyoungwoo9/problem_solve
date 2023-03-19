#include <iostream>
#include <deque>

using namespace std;

void solution()
{
	deque <int> dq;
	string order;
	cin >> order;
	int N;
	cin >> N;
	string non_parsing_num;
	cin >> non_parsing_num;
	string str = "";
	for(int i = 0; i < non_parsing_num.length(); i ++)
	{
		if(isdigit(non_parsing_num[i]))
		{
			str += non_parsing_num[i];
		}
		else
		{
			if(!str.empty())
			{
				dq.push_back(stoi(str));
				str = "";
			}
		}
	}
	int mode = 0;
	for(int i = 0; i < order.size(); i ++)
	{
		if(order[i] == 'R')
			mode = (mode + 1) % 2;
		else if(order[i] == 'D')
		{
			if(dq.empty())
			{
				cout << "error\n";
				return ;
			}
			if(mode == 0)
			{
				dq.pop_front();
			}
			else if(mode == 1)
			{
				dq.pop_back();
			}
		}
	}
	cout << "[";
	if(mode == 0)
	{
		while(!dq.empty())
		{
			cout << dq.front();
			dq.pop_front();
			if(!dq.empty())
				cout << ",";
		}
	}
	else if(mode == 1)
	{
		while(!dq.empty())
		{
			cout << dq.back();
			dq.pop_back();
			if(!dq.empty())
				cout << ",";
		}
	}
	cout << "]\n";
}

int main()
{
	int T;
	cin >> T;
	for(int i = 0; i < T; i ++)
	{
		solution();
	}
}