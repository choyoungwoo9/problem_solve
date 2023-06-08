#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, int> mp;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	cin >> N >> M;
	for(int i = 0; i < N; i ++)
	{
		string str;
		cin >> str;
		mp[str] = 1;
	}
	int answer = 0;
	for(int i = 0; i <M; i ++)
	{
		string str;
		cin >> str;
		if(mp[str] == 1)
			answer ++;
	}
	cout << answer << endl;
}