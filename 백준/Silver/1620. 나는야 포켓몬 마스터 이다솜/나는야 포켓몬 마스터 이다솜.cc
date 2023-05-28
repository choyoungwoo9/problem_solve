#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int N, M;
unordered_map<string, int>mp1;
unordered_map<int, string>mp2;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for(int i = 1; i <= N; i ++)
	{
		string str;
		cin >> str;
		mp1[str] = i;
		mp2[i] = str;
	}
	for(int i = 0; i < M; i ++)
	{
		string str;
		cin >> str;
		if(str[0] >= '0' && str[0] <= '9')
		{
			cout << mp2[stoi(str)] << "\n";
		}	
		else
			cout << mp1[str] << "\n";
	}
}