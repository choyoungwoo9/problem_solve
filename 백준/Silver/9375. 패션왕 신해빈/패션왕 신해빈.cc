#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;

void solution()
{
	map<string, int> mp;
	vector<int> ar;
	for(int i = 0; i < 30; i ++)
		ar.push_back(0);
	int N;
	cin >> N;
	int cnt = 1;
	for(int i = 0; i < N; i ++)
	{
		string s1, s2;
		cin >> s1 >> s2;
		int idx = mp[s2];
		if(idx == 0)
		{
			mp[s2] = cnt;
			ar[cnt] = 1;
			cnt ++;
		}
		else
			ar[idx] ++;
	}
	int sum = 1;
	for(int i = 1; i < cnt; i ++)
	{
		sum = sum * (ar[i] + 1);
	}
	sum --;
	cout << sum << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >>T;
	for(int i = 0; i < T; i ++)
	{
		solution();
	}
}

//경우의 수는 곱하기임
//2, 1이 있으면
//2에서 3개의 경우가 있음 -> 각각 하나씩 선택하는 경우, 아무것도 선택하지 않는경우
//1에서 2개의 경우가 있음 -> 선택 하거나, 말거나
//즉 곱하면 되는거임
//그런데 문제에서 아무것도 선택하지 않는 케이스는 제외한다 했으니 1을 빼자