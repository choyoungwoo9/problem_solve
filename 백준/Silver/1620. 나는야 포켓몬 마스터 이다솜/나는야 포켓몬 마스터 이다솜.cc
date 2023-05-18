#include <iostream>
#include <map>
#include <string>
using namespace std;

int N, M;
string ar[100001];

map<string, int> mmp;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;

	for(int i = 1; i <= N; i ++)
	{
		cin >> ar[i];
		mmp.insert(pair<string, int>(ar[i], i));
	}

	for(int i = 1; i <= M; i ++)
	{
		string str;
		cin >> str;
		if(str[0] >= '0' && str[0] <= '9')
		{
			cout << ar[stoi(str)] << "\n";
		}
		else
		{
			cout << mmp[str] << "\n";
		}
	}
}