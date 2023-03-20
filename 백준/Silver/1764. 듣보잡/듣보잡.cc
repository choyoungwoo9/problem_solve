#include <iostream>
#include <map>
#include <set>
using namespace std;

int N, M;
map<string, int> um;

set<string> answer;

int main()
{
	cin >> N >> M;
	for(int i = 0; i < N; i ++)
	{
		string str;
		cin >> str;
		um[str] = i;
	}
	for(int i = 0; i < M; i ++)
	{
		string str;
		cin >> str;
		if(um.count(str))
		{
			answer.insert(str);
		}
	}
	cout << answer.size() << endl;
	for(auto iter = answer.begin(); iter != answer.end(); iter ++)
	{
		cout << *iter << "\n";
	}
}