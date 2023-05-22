#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
int bag[300001];
vector<pair<int, int> >ju;
priority_queue<int>pq;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for(int i = 0; i < N; i ++)
	{
		int w, c;
		cin >> w >> c;
		ju.push_back(pair<int, int>(w, c));
	}
	for(int i = 0; i < K; i ++)
	{
		cin >> bag[i];
	}
	sort(bag, bag+K);
	sort(ju.begin(), ju.end());


	int idx = 0;
	unsigned long long answer = 0;
	for(int i = 0; i < K; i ++)
	{
		for(; idx < N && ju[idx].first <= bag[i]; idx++)
		{
			pq.push(ju[idx].second);
		}
		if(!pq.empty())
		{
			answer += pq.top();
			pq.pop();
		}
	}
	cout << answer << endl;
}