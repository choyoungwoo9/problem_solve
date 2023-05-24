#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void solution()
{
	int N;
	cin >> N;
	vector<pair<int, int> >vt;
	int ans = N;
	for(int i = 0; i < N; i ++)
	{
		int n1, n2;
		cin >> n1 >> n2;
		vt.push_back(pair<int, int>(n1, n2));
	}
	sort(vt.begin(), vt.end());
	int m_max = -1;
	for(int i = 0; i < N; i ++)
	{
		if(i == 0)
		{
			m_max = vt[i].second;
		}
		else if(m_max < vt[i].second)
		{
			ans --;
		}
		else if(m_max > vt[i].second)
			m_max = vt[i].second;
	}
	cout << ans << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	for(int i = 0; i < T; i ++)
	{
		solution();
	}
}
