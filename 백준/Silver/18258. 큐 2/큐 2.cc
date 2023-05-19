#include <iostream>
#include <string>
#include <queue>

using namespace std;
queue<int> que;

void solution()
{
	string str;
	cin >> str;
	int num;
	if(str == "push")
	{
		cin >> num;
		que.push(num);
	}
	else if(str == "pop")
	{
		if(que.empty())
			cout << "-1\n";
		else
		{
			cout << que.front() << "\n";
			que.pop();
		}
	}
	else if(str == "size")
	{
		cout << que.size() << "\n";
	}
	else if(str == "empty")
	{
		cout << que.empty() << "\n";
	}
	else if(str == "front")
	{
		if(que.empty())
			cout << "-1\n";
		else
		{
			cout << que.front() << "\n";
		}
	}
	else if(str == "back")
	{
		if(que.empty())
			cout << "-1\n";
		else
		{
			cout << que.back() << "\n";
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	for(int i = 0; i < N; i ++)
	{
		solution();
	}
}