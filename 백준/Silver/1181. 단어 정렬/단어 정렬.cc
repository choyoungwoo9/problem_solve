#include <iostream>
#include <queue>
#include <string>

using namespace std;

int N;

struct compare{
	bool operator ()(string a, string b)
	{
		if(a.size() != b.size())
				return a.size() > b.size();
		return a > b;
	}
};

priority_queue<string, vector<string>, compare> que;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for(int i = 0; i < N; i ++)
	{
		string str;
		cin >> str;
		que.push(str);
	}
	string str;
	for(int i = 0; i < N; i ++)
	{
		if(str == que.top())
		{
			que.pop();
			continue;
		}
		str = que.top();
		cout << que.top() << "\n";
		que.pop();

	}
}