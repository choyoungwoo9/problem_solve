#include <iostream>
#include <deque>

using namespace std;

deque <int> deq;

int main()
{
	int N;
	cin >> N;
	for(int i = 0; i < N; i ++)
	{
		string str;
		cin >> str;
		if(str == "push")
		{
			int num;
			cin >> num;
			deq.push_back(num);
		}
		else if(str == "pop")
		{
			if(deq.empty())
				cout << "-1\n";
			else
			{
				int head = deq.front();
				deq.pop_front();
				cout << head << "\n";
			}
		}
		else if(str == "size")
		{
			cout << deq.size() << "\n";
		}
		else if(str == "empty")
		{
			if(deq.empty())
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if(str == "front")
		{
			if(deq.empty())
				cout << "-1\n";
			else
			{
				cout << deq.front() << "\n";
			}
		}
		else if(str == "back")
		{
			if(deq.empty())
				cout << "-1\n";
			else
			{
				cout << deq.back() << "\n";
			}
		}
	}
}